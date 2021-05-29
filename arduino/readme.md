# Arlok Source Code for Arduino IDE
  
This folder contains Arduino sketches to be used with [Arduino IDE](https://www.arduino.cc/en/main/software).  
Note: The setup procedure is only implemented in the `explorer` sketch.

## Libraries
  
You need to install the following base libraries:  

- [Adafruit SSD1306](https://github.com/adafruit/Adafruit_SSD1306)
- [Adafruit GFX](https://github.com/adafruit/Adafruit-GFX-Library)
- [TimerOne](https://github.com/PaulStoffregen/TimerOne)
- [Servo Timer 2](https://github.com/nabontra/ServoTimer2)

## Arduino IDE Setup
  
Even if you're using the [MakerUNO](https://makeruno.com.my/) simply select _Arduino UNO_ from the board manager. Then select the correct COM port.

## Code examples

- [Explorer](./explorer) : Arlok moves around avoiding obstacles
- [Bluetooth Remote](./bluetooth) : You move Arlok using Bluetooth Classic with an Android phone
- [Line Follower](./linefollower) : Arlok moves following a line painted on the ground

## Work in progress
- Artificial vision example[see video](https://www.youtube.com/watch?v=Ag7VS_6hT9I), [code on Bobboteck repo](https://github.com/bobboteck/ArloPixetto)
