// SPDX-License-Identifier: MPL-2.0

const socket = io(`http://${window.location.host}`);
const valL = document.getElementById('val-l');
const valR = document.getElementById('val-r');

// Receive sensor value from socket and update DOM
socket.on('mcu_data', (data) => {
    document.getElementById('temperature').textContent = data.temperature.toFixed(1) + '°C';
    document.getElementById('humidity').textContent = data.humidity.toFixed(1) + '%';
    document.getElementById('elapsed').textContent = data.elapsed + 'ms';
});

// Toggle switch - send and wait response from MCU
const ledToggle = document.getElementById('led-toggle');
let pendingToggle = false; // block further clicks while waiting response

ledToggle.addEventListener('change', (evt) => {
    if (pendingToggle) {
        evt.preventDefault();
        ledToggle.checked = !ledToggle.checked;
        return;
    }
    pendingToggle = true;
    ledToggle.classList.add('pending');
    
    // Send requested value (still not confirmed)
    socket.emit('led_toggle', { state: ledToggle.checked });
});

// Update switch appearance only when MCU confirms GPIO status
socket.on('led_confirm', (data) => {
    const ledState = document.getElementById('led-state');
    ledToggle.checked = data.state;
    ledState.textContent = data.state ? '(ON)' : '(OFF)';
    ledState.classList.toggle('on', data.state);
    pendingToggle = false;
    ledToggle.classList.remove('pending');
});


// Heartbeat counter used for failsafe functions
let heartbeatCounter = 0;

function sendHeartbeat() {
    heartbeatCounter = (heartbeatCounter + 1) % 256; // 0-255, then reload
    socket.emit('heartbeat', { counter: heartbeatCounter });
    // print heartbeat value on the ui
	document.getElementById('heartbeat-value').textContent = heartbeatCounter;
}

const heartbeatInterval = setInterval(sendHeartbeat, 1000);

// clear interval if socket disconnects
socket.on('disconnect', () => clearInterval(heartbeatInterval));

// Initialize NippleJS Joystick
const joystick = nipplejs.create({
    zone: document.getElementById('joystick-zone'),
    mode: 'static',
    position: { left: '50%', top: '50%' },
    color: '#008184',
    size: 180 // Slightly larger for better control
});

// Nord       (y=1,  x=0):    L=180, R=0    ← avanti
// Sud        (y=-1, x=0):    L=0,   R=180  ← indietro  
// Est        (y=0,  x=1):    L=135, R=45   ← destra sul posto
// Nord-Est   (y=1,  x=1):    L=180, R=45   ← avanti con deriva destra
// Nord-Ovest (y=1,  x=-1):   L=135, R=180  ← avanti con deriva sinistra

joystick.on('move', (evt, data) => {
    if (!data.vector) return;
    const y = data.vector.y;
    const x = data.vector.x;

    // speed from y, steering from x
    const speed    =  y * 90;
    const steering = - x * 90;

    let left  = 90 + speed - (steering * 0.25);
    let right = 90 - speed - (steering * 0.25);

    left  = Math.max(0, Math.min(180, Math.round(left)));
    right = Math.max(0, Math.min(180, Math.round(right)));

    valL.textContent = left;
    valR.textContent = right;
    socket.emit('move_robot', { l: left, r: right, ts: Date.now() });
});

// joystick released : send stop to the socket
joystick.on('end', () => {
    valL.textContent = 90;
    valR.textContent = 90;
    socket.emit('move_robot', { l: 90, r: 90, ts: Date.now() });
    document.getElementById('joystick-zone').style.border = '3px solid red';
    setTimeout(() => {document.getElementById('joystick-zone').style.border = '';}, 300);
});
