## Bluetooth Remote

Arlok is moved using an app on an android device. Following steps assumes you're using an HC-06 Bluetooth Module.  
Here is a video showing this example: https://youtu.be/ISU3L3CCWP8

The only things in which HC-05 differs are:
- for going in AT command mode, you must press the button on the module during the powering
- the AT command mode baud rate of the HC-05 is 38400

![Arlok Bluetooth Remote](../../media/bt/arlok_bluetooth_remote.jpg)

### Change the Bluetooth module name

First Connect the bluetooth module to an USB adapter capable to work at 3.3V : in this phase leave the USB adapter disconnected from the computer:  

- Connect hc-06 module Vcc to usb adapter +5V
- Connect hc-06 TX to USB adapter RX
- Connect hc-06 RX to USB adapter TX
- Connect hc-06 GND to USB adapter GND
- Set the module for working at 3.3V

Note: The HC-06 module need to be powered at 5V but TX/RX levels are at 3.3V

- Connect the USB adapter to the computer
- The computer will recognize a COM port, the red led on the USB adapter flashes rapidly
- Start a Serial Terminal program
- Choose the right COM port and set the baudrate at 9600
- Open che connection to the COM port
- Send the string: AT+NAMEArlok (the terminal software must append CR and LF chars)
- The module will respond: OKsetname

![HC-06 Set Name](../../media/bt/hc06_setname.png)

- Close the connection
- Remove the power from the HC-06 Module
- Give the power to the HC-06 Module
- Take a cellular phone and turn on the bluetooth
- Search for new bluetooth devices: 'Arlok' must appear in the list

![HC-06 Bluetooth Search](../../media/bt/hc06_bt_search.jpg)

- Select Arlok and associate it
- the default pin is 1234 (if does not work, try 0000)

![HC-06 Write Pin](../../media/bt/hc06_bt_pin.jpg)

First step is complete!

### Make the App

After you've paired the Bluetooth module with the phone, you can go further:  

- Install [Bluetooth Electronics by kewlsoft](https://play.google.com/store/apps/details?id=com.keuwl.arduinobluetooth)
- Open Bluetooth Electronics
- Some example panels are showed. When you select one, a Panel number with description is showed in the lower part of the screen.
- Select the first panel 
- Click on the save icon
- Click the button 'Load from Web Link'
- Delete the default text and write: https://www.settorezero.com/abt.kwl

![Bluetooth Electronics - Load Arlok Panel](../../media/bt/kewlsoft_01.png)

- Press Load
- A prompt "This will overwrite all panels!" will show: don't care, press OK
- An error will be showed: don't care
- The panel for this Arlok demo is showed in the first slot and all other slots are empty

![Bluetooth Electronics - Arlok Panel Loaded](../../media/bt/kewlsoft_03.png)

Note: for reset the previous panel click on the gears button and select 'Reset Default'. Previous panels will be reset and Arlok panel will be deleted

### Run The App

- In the Bluetooth Electronics panel clic the 'Connect' button
- Leave 'Bluetooth Classic' selected and press the 'Next' button
- In the paired device list, 'Arlok' must be present: Select it and press 'Connect'
- In the top screen 'Connected to: Arlok (followed my MAC address)' must be showed
- Press the 'Done' button
- Select the Arlok panel and pres the 'Run' button
- Move Arlok using the 4-way pad, sound the buzzer pressing the yellow button. The 'Distance' textbox shows the distance, expressed as cm, read by the sonar

![Bluetooth Electronics - Arlok Panel Working](../../media/bt/kewlsoft_02.png)
