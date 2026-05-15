## Explorer TOF

Arlok moves forward, when he see an obstacle will make a sound (if you're using a MakerUno board), stop, move back, then turn random left or right and continue.  In this case a TOF sensor is used, model **VL53L0XV2**.

This sensor communicate over I2C: you can attach TOF sensor wires on I2C pad on top of the PCB (grove style or dupont). Close the jumper called "Grove I2C VCC select" between center pad and 5V for having 5V on both grove and dupont connector.

The TOF sensor will replace the ultrasonic one, you must print the <kbd>ArlokV2 - TOF Mask (single)</kbd> part for attaching the TOF sensor in front of Arlok: this part it's only compatible with the V2 chassis version.

For using the TOF sensor you must install the VL53L0X library by Pololu (tested the 1.3.1 version).

Uncomment the row <kbd>#define LIPO</kbd> if you're using a 18650 and you want to show the battery voltage on the display second Row: in this case connect the positive pole of the battery (after the power switch) directly to the pin A2: this pin is defined by <kbd>#define LIPO_PIN</kbd>.

### Motors Setup

See [motors setup procedure](../motors_setup.md)