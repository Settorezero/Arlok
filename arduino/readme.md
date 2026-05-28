# Arlok Source Code for Arduino IDE

This folder contains Arduino sketches to be used with [Arduino IDE](https://www.arduino.cc/en/main/software) after installing libraries showed in the next paragraph

> Note: The [motors setup procedure](motors_setup.md) it's only implemented in the `explorer` and `explorer lipo` sketches.

## Libraries

You'll need the following libraries installable directly from Arduino IDE otherwise specified

- [Adafruit SSD1306](https://github.com/adafruit/Adafruit_SSD1306)
- [Adafruit GFX](https://github.com/adafruit/Adafruit-GFX-Library)
- [TimerOne](https://github.com/PaulStoffregen/TimerOne) 
- [Servo Timer 2](https://github.com/nabontra/ServoTimer2) - (manual install)
- [VL53L0XV2 by Pololu](https://github.com/pololu/vl53l0x-arduino)
- [U8G2](https://github.com/olikraus/u8g2)
- [Huskylens](https://github.com/HuskyLens/HUSKYLENSArduino/tree/master) - (manual install)

## Arduino IDE Setup

Even if you're using the [MakerUNO](https://makeruno.com.my/) or other Arduino UNO compatible boards, simply select _Arduino UNO_ from the board manager. Then select the correct COM port.

## Code examples

- [Explorer](./01_Explorer) : Arlok moves around avoiding obstacles detected with ultrasonic sensor
- [Explorer TOF](./02_Explorer_TOF) : Arlok moves around avoiding obstacles detected with a VL53L0XV2 TOF Sensor (requires the V2 chassis)
- [Line Follower](./03_Linefollower) : Arlok moves following a line painted on the ground
- [Bluetooth Remote](./04_Bluetooth_Remote) : You move Arlok using Bluetooth Classic with an Android phone. Source code for Android app provided too
- [Huskyklens](./05_Huskylens) : Arlok will follow a face using an Huskylens from DFRobot
