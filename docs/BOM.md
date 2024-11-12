## ARLOK Bill Of Materials

> Quick link to this page: [https://tinyurl.com/shieldarlok](https://tinyurl.com/shieldarlok)  

### Summary

1) [Electronics - PCB](#pcb)
2) [Electronics - Shield Components, detailed list](#shield)
3) [Electronics - Shield Components, shopping list](#shieldc)
4) [Electronics - External components](#ext)
5) [Mechanics   - 3D-printed parts](#3d)
6) [Mechanics   - Components](#mech)
7) [Adviced Arduino UNO R3 compatible Boards](#boards)
8) [Differencies between REV1 and first rev PCB](#diffrev1)

### <a name="pcb"></a>1) Electronics - PCB

Step 1: Subscribe to PCBWay using my invite link:
        https://www.tinyurl.com/pcbwaysz

Step 2: Order the ARLOK shield REV1 PCB from the following link:
        [https://tinyurl.com/arlokshieldr1](https://tinyurl.com/arlokshieldr1)
        
> If you don't want to buy the Arlok PCB, you can use an Arduino Uno protoshield and make your own shield connecting external components (servo, ultrasonic sensor, display ecc) to the Arduino pins following the [schematic](arlok_schematic_rev1.png) and/or the [connection table](connections.md).

### <a name="shield"></a>2) Electronics - Shield REV1 Components (detailed)

> You can download the following [list in PDF format](./pdfs/arlok_shield_BOM.pdf)

| Part         | Value                                          | Notes                            |
|--------------|------------------------------------------------|----------------------------------|
| C1           | 100nF multilayer                               | 5mm pitch                        |
| C2           | 100nF multilayer                               | 5mm pitch                        |
| C3           | 1000uF 16V electrolytic                        | 3.5mm pitch - 8mm dia.           |
| C4           | 100nF multilayer                               | 5mm pitch                        |
| C5           | 100nF multilayer                               | 5mm pitch                        |
| C6           | 100nF multilayer                               | 5mm pitch                        |
| C7           | 220uF 16V electrolytic                         | 2.5mm pitch - 6mm dia.           |
| D1           | 1N4007                                         | good any 1N400x                  |
| R1           | 22KΩ ¼W                                        | red - red - orange               |
| R2           | 15KΩ ¼W                                        | brown - green - orange           |
| R3           | 330Ω ¼W                                        | orange - orange - brown          |
| P1           | tactile switch                                 | 6x6mm (adviced long button)      |
| P2           | tactile switch                                 | 6x6mm (adviced long button)      |
| RESET        | tactile switch                                 | 6x6mm                            |
| VR1          | 5kΩ ÷ 20kΩ trimmer                             | 6x6mm                            |
| L1           | led 3mm                                        |                                  |
| H1 (*)       | male pinheader 10pin                           | Arduino header - solder on top   |
| H2 (*)       | male pinheader 8pin                            | Arduino header - solder on top   |
| H3 (*)        | male pinheader 5pin                            | Arduino header - solder on top   |
| H4 (*)        | male pinheader 4pin                            | Arduino header - solder on top   |
| EXT (EXT1)   | male pinheader 7pin                            |                                  |
| EXT2 (A1)    | male pinheader 3pin                            |                                  |
| EXT3 (A2)    | male pinheader 3pin                            |                                  |
| EXT4 (A3)    | male pinheader 3pin                            |                                  |
| HC-SR04      | male pinheader 4pin                            |                                  |
| I2C          | male pinheader 4pin                            | optional                         |
| J1 (COMM)    | female pinheader 6pin                          |                                  |
| JP1          | male pinheader 3pin + jumper                   |                                  |
| JSW (POWER)  | male pinheader 2pin + jumper                   | or 2.54mm pitch lever switch     |
| LEFT_SERVO   | male pinheader 3pin                            |                                  |
| RIGHT_SERVO  | male pinheader 3pin                            |                                  |
| OLED         | female pinheader 4pin                          |                                  |
| X1           | Screw Terminal 2pin                            | 5mm pitch                        |
| X2           | Screw Terminal 2pin                            | 5mm pitch                        |
| GROVE        | GROVE male header                              | optional                         |

> (*) Standard headers are 11mm long: those are good if you use one of the Adviced Boards (see below). If you want to use a standard Arduino UNO, 11mm headers are not good, since the USB connector will touch under Arlok shield, so in this case 15mm headers are needed or you can use special Arduino Headers

> Note: if you must mod the servos for the continuous rotation, you need further 4 2.2KΩ ¼W resistors, adviced at 1% tolerance

### <a name="shieldc"></a>3) Electronics - Shield REV1 Components (shopping list)

| Qt. | Part                                                          |
|-----|---------------------------------------------------------------|
|  5  | 100nF multilayer capacitor,  pitch 5mm                        |
|  1  | 1000uF 16V electrolytic capacitor, pitch 3.5mm dia 8mm        |
|  1  | 220uF 16V electrolytic capacitor, pitch 2.5mm dia 6mm         |
|  1  | 1N400x diode                                                  |
|  1* | 22KΩ ¼W 1% resistor                                           |
|  1  | 15KΩ ¼W resistor                                              |
|  1  | 330Ω ¼W resistor                                              |
|  2  | tactile switch 6x6mm, long button                             |
|  1  | tactile switch 6x6mm                                          |
|  1  | 5kΩ ÷ 20kΩ trimmer (6x6mm)                                    |
|  1  | LED 3mm                                                       |
|  2  | Screw terminal, pitch 5mm                                     | 
|  2  | 40pin male headers (needed 60pin)                             |
|  1  | female header (needed 6+4 pin)                                |
|  1  | jumper block, pitch 2.54mm                                    |
|  1  | PCB lever switch, pitch 2.54mm (**)                           |

> (*) If you must mod the servos for the continuous rotation, you need further 4 22KΩ ¼W resistors, adviced at 1% tolerance
> (**) Or 2 pin-male header + jumper block

### <a name="ext"></a>4) Electronics - External components

| Qt.          | Description                                                              |
|--------------|--------------------------------------------------------------------------|
| 1x           | Adviced Arduino UNO compatible board (*)                                 |
| 2x           | Servo MG996R modded for continuos rotation OR Servo having 360° rotation |
| 1x           | HC-SR04 Ultrasonic sensor                                                |
| 1x           | Bluetooth module HC-05 (or HC-06) - Needed for Bluetooth remote example  |
| 1x           | Cytron MakerLine board - Needed for Line Follower example                |
| 1x           | OLED display module I2C (4pin) 0.96"                                     |
| 1x           | Battery Holder for 4AA batteries                                         |
| 1x           | Battery Holder for 3AA batteries                                         |
| 1x           | Round pushbutton with retain or lever switch (**)                        |
| 1x           | 4pin Female/Female Dupont cable (~15cm) (***)                            |
| 7x           | AA 1.5V Batteries (****)                                                 |

(*) See list below

(**)  Print the `arlok_pillar_hole_xx.stl` according the pushbutton diameter  

(***) Used for connecting ultrasonic module to PCB, you can use also 4 separate F/F jumper
     cables or make your own cable using connector you prefer.
  
(****) Not adviced to use NiCd or NiMH batteries, since voltage of those batteries is 1.2V. There is also a mod for using one LiPo Battery but it's at your own risk
     read more here: [LiPo Mod](lipo_mod.md)

### <a name="3d"></a>5) Mechanics - 3D-printed parts

Please see in the [STL folder](../cad/stl)

### <a name="mech"></a>6) Mechanics - Components

| Qt.          | Description                                                                  |
|--------------|------------------------------------------------------------------------------|
| 12x          | M3 screw, Allen bolt socket cap, 12mm (length of threaded part - 15mm total) |
| 8x           | M3 screw, Allen bolt socket cap, 6mm (length of threaded part - 8mm total)   |
| 14x          | M3 washers (optional)                                                        |
| 12x          | M3 nuts                                                                      |
| 2x           | M3 screw, Countersunk, 8mm (length of threaded part, 10mm total)             |
| 4x           | Hex spacer Female/Female 8 or 10mm length                                    |
| 1x           | Tamiya BallCaster model 70144 (*)                                            |
| 2x           | Rubber O-Ring, 70mm internal diameter, 2-3mm width (**)                      |

[Here is a picture showing screws](../media/arlok_screws.jpg). Same picture is available [in italian too](../media/arlok_screws_ita.jpg).

(*) when you buy the Tamiya 70144 ballcaster kit, there are parts for making 2 ballcasters.
    Maybe you can share the extra ballcaster part with a friend so he can build an Arlok too.
    Alternatively you can 3D-print the [Ball Caster V2 on Thingiverse](https://www.thingiverse.com/thing:1408935) in the height of 30mm (you need [OpenScad](https://openscad.org/) for editing the .scad file and change the height)

(**) There are some kinds of tires that can be 3D-Printed using TPU. If your 3D printer can handle TPU, try
     first to print them yourself: see in [STL folder](../cad/stl) for the Tires.
	 
### <a name="boards"></a>7) Adviced Arduino UNO R3 compatible boards

Since the Arlok shield is designed using an Arduino UNO shape as reference, microcontroller boards having "tall" parts (the USB type B connector, like on the original Arduino UNO R3), cannot be used since USB connector metallic part can touch the solder side of the shield causing short circuits and then damages.  
Only way to use a genuine Arduino UNO R3 board is to assemble the shield using not-so-common long male headers (15mm at least).  
Here is a list of suitable boards don't using the USB type B connector:  
- [Keyestudio 328 Plus](https://www.keyestudio.com/products/2020-new-keyestudio-plus-development-board-with-type-c-interface-usb-cable-compatible-with-arduino-uno-r3)
- [Cytron Maker UNO](https://www.cytron.io/p-maker-uno-simplifying-arduino-for-education)
- [Arduino Make Your UNO](https://store.arduino.cc/pages/make-your-uno-kit) 
- [Seeeduino 4.2](https://www.seeedstudio.com/Seeeduino-V4-2-p-2517.html)
- [Grove Beginner Kit](https://www.seeedstudio.com/Grove-Beginner-Kit-for-Arduino-p-4549.html)

Some of those boards have a full-size barrel jack connector: this can touch the shield so is adviced to desolder it 

### <a name="diffrev1"></a>8) Differencies between REV1 and first rev PCB

- Added C7 for having a little more energy buffer for devices
- Added a via (not connected) next GND of the power header if you want to connect to the Arduino VIN pin 
- Changed silkscreen of the JSW connector from "POWER" to "LOGICS POWER" since is used only for 5V
- Added a via (not connected) next to the JSW connector if you want to use a three pins switch
- Changed VR1 from PT10LV10 (10x10mm) type to a smallest and more common 6x6mm (there is an additional via for the center pin for using a 10x10mm anyway)
- Added "A0" next VR1 silkscreen to remember where trimmer is connected 
- Enlarged the prototyping area adding further 21 vias
- Changed silkscreen for the screw terminals connector: removed the minus sign allowing writings to be more readable
- Removed the OR logo and added the "Pizza Robotics - In pizza we crust" one
