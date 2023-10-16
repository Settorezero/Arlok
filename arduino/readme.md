# Arlok Source Code for Arduino IDE
  
This folder contains Arduino sketches to be used with [Arduino IDE](https://www.arduino.cc/en/main/software) after installing libraries showed in the next paragraph
> Note: The [motors setup procedure](motors_setup.md) it's only implemented in the `explorer` and `explorer lipo` sketches.

## Libraries
  
You need to install the following libraries:  

- [Adafruit SSD1306](https://github.com/adafruit/Adafruit_SSD1306)
- [Adafruit GFX](https://github.com/adafruit/Adafruit-GFX-Library)
- [TimerOne](https://github.com/PaulStoffregen/TimerOne)
- [Servo Timer 2](https://github.com/nabontra/ServoTimer2)

## Arduino IDE Setup
  
Even if you're using the [MakerUNO](https://makeruno.com.my/) or other Arduino UNO compatible boards, simply select _Arduino UNO_ from the board manager. Then select the correct COM port.

## Code examples

- [Explorer](./explorer) : Arlok moves around avoiding obstacles
- [Bluetooth Remote](./bluetooth) : You move Arlok using Bluetooth Classic with an Android phone. Source code for Android app provided too
- [Line Follower](./linefollower) : Arlok moves following a line painted on the ground
- [Explorer with a LiPo](./explorer_lipo) : Same as Explorer with battery voltage indication from the Lipo. See [lipo_mod](../docs/lipo_mod.md) for further infos

## Work in progress
- Artificial vision example using the DFRobot Husky Lens
