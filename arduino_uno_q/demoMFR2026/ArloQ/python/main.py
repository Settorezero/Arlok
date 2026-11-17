from arduino.app_utils import *
from arduino.app_bricks.web_ui import WebUI
from arduino.app_bricks.video_objectdetection import VideoObjectDetection
from datetime import datetime, UTC
import threading
import queue

ui = WebUI()
detection_stream = VideoObjectDetection(confidence=0.6, debounce_sec=0.5)

"""
model used: yolox nano
https://studio.edgeimpulse.com/public/717280/live/impulse/1/pretrained-model

Objects detected:
person, bicycle, car, motorcycle, airplane, bus, train, truck, boat, traffic light, 
fire hydrant, stop sign, parking meter, bench, bird, cat, dog, horse, sheep, cow, 
elephant, bear, zebra, giraffe, backpack, umbrella, handbag, tie, suitcase, frisbee, skis, 
snowboard, sports ball, kite, baseball bat, baseball glove, skateboard, surfboard, tennis racket, 
bottle, wine glass, cup, fork, knife, spoon, bowl, banana, apple, sandwich, orange, broccoli, carrot, 
hot dog, pizza, donut, cake, chair, couch, potted plant, bed, dining table, toilet, tv, laptop, 
mouse, remote, keyboard, cell phone, microwave, oven, toaster, sink, refrigerator, book, clock, vase, 
scissors, teddy bear, hair drier, toothbrush
"""

""" 
-------------------------------------------------------------------------------------
Joystick worker
bridged as 'drive', runs on a separate thread
-------------------------------------------------------------------------------------
"""
bridge_lock = threading.Lock()
latest_joystick = None
latest_ts = 0  # timestamp of last accepted command
joystick_lock = threading.Lock()
joystick_event = threading.Event()

def joystick_worker():
    global latest_joystick
    while True:
        joystick_event.wait()
        joystick_event.clear()
        with joystick_lock:
            if latest_joystick is None:
                continue
            l, r = latest_joystick
            latest_joystick = None
        try:
            with bridge_lock:
                Bridge.call("drive", l, r)
        except Exception as e:
            print(f"[joystick_worker] error: {e}")

threading.Thread(target=joystick_worker, daemon=True).start()
"""
-------------------------------------------------------------------------------------
Joystick movement
Handle joystick movement data from the browser.
Receives 'l' and 'r' values (0-180 degrees) and timestamp of the command
Discard values if considered as "glitches", save values in memory if good
values in memory will be evaluated by joystick worker, running asynchronously
-------------------------------------------------------------------------------------
"""
last_accepted = {"l": 90, "r": 90, "ts": 0}
MIN_MS_PER_UNIT = 0.8  # at least 0.8ms per unit

def on_joystick_move(client, data):
    global latest_joystick, latest_ts
    l = data.get("l", 90)
    r = data.get("r", 90)
    ts = data.get("ts", 0)

    with joystick_lock:
        if ts < latest_ts:
            return

    is_stop = (l == 90 and r == 90) # stop always accepted

    if not is_stop:
        dt = ts - last_accepted["ts"]  # elapsed time
        delta_l = abs(l - last_accepted["l"])
        delta_r = abs(r - last_accepted["r"])
        max_delta = max(delta_l, delta_r)

        min_time_needed = max_delta * MIN_MS_PER_UNIT

        if dt < min_time_needed:
            print(f"[joystick] GLITCH discarded: delta={max_delta} in {dt}ms (min={min_time_needed:.0f}ms)")
            return

    last_accepted["l"] = l
    last_accepted["r"] = r
    last_accepted["ts"] = ts

    with joystick_lock:
        latest_ts = ts
        latest_joystick = (l, r)
    joystick_event.set()

    print(f"[joystick] ts={ts} l={l} r={r}")

ui.on_message("move_robot", on_joystick_move)

# -------------------------------------------------------------------------------------
# Artificial vision
# -------------------------------------------------------------------------------------
def send_detections_to_ui(detections: dict):
    for key, values in detections.items():
        for value in values:
            entry = {
                "content": key,
                "confidence": value.get("confidence"),
                "timestamp": datetime.now(UTC).isoformat()
            }
            ui.send_message("detection", message=entry)

detection_stream.on_detect_all(send_detections_to_ui) # callback

# -------------------------------------------------------------------------------------
# Data from HTU sensor
# -------------------------------------------------------------------------------------
def on_data(elapsed: int, htu_te: float, htu_rh: float):
    ui.send_message("mcu_data", message={
        "elapsed": elapsed,
        "temperature": htu_te,
        "humidity": htu_rh
    })

Bridge.provide("data", on_data) # callback

# -------------------------------------------------------------------------------------
# Lights
# -------------------------------------------------------------------------------------
def on_led_toggle(client, data):
    state = data.get("state", False)
    with bridge_lock:
        confirmed_state = Bridge.call("set_led", int(state))
    ui.send_message("led_confirm", message={"state": bool(confirmed_state)})

ui.on_message("led_toggle", on_led_toggle) # callback

# -------------------------------------------------------------------------------------
# Heartbeat / Failsafe function
# -------------------------------------------------------------------------------------
def on_heartbeat(client, data):
    counter = data.get("counter")
    Bridge.call("heartbeat", counter)

ui.on_message("heartbeat", on_heartbeat) # callback

App.run()