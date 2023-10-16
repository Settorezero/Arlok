## Powering

You can power Arlok with 3 different methods:
- Using 7 AA Batteries: 4 for motors, 3 for logics (safe, adviced for kids, limited autonomy)
- Using 4 AA Batteries fot both motors and logics (cheap, not adviced, limited autonomy)
- Using a single 18650 LiPo Battery with step-up converter (rechargeable, dangerous, not adviced for kids, great autonomy)

#### Using 7 AA Batteries (6V+4.5V)
This is a safe method since common batteries are used. Anyway the 4AA batteries have a limited autonomy since are used for motors and hare pretty difficult to replace since you must unscrew the top plate.
You need:
- 7 AA Batteries (not adviced NiMh rechargeable ones since are 1.2V)
- a battery holder for 4 AA batteries
- a battery holder for 3 AA batteries

![6V+4.5V powering](../media/instructions/powering/AA_6V%2B4v5.png)

The 3xAA Battery holder (4.5V) will be connected to the VDD screw terminal and will take place under the robot, near the ballcaster  
The 4xAA Battery holder (6V) will be connected to the VSERVO screw terminal through the pushbutton. This holder will take place between the top and the bottom plate  
You must put the JP1 jumper in the VDD position

#### Using 4 AA Batteries (6V)
This method is cheap but not adviced.
You need:
- 4 AA Batteries (not adviced NiMh rechargeable ones since are 1.2V)
- a battery holder for 4 AA batteries

![6V powering](../media/instructions/powering/AA_6V.png)  

The 4xAA Battery holder (6V) will be connected to the VSERVO screw terminal through the pushbutton. This holder will take place between the top and the bottom plate.  
You must put the JP1 jumper in the VSERVO position and you can close the the "logics" pad

#### Using a 18650 LiPo cell
This method is the best but not adviced for kids since LiPo cells are dangerous and need to be handled with lot of care.
You need:
- 18650 LiPo Battery with tabs
- an SX1308 Step-Up Converter (PCB signature is HW668)
- a TP4056 with protection for recharging the battery (or use the method you prefer for rechargingthe battery)
- 3D-print the [`arlok_18650_holder.stl`](../cad/stl/arlok_18650_holder.stl)
- additional 2 M3 screws, Allen bolt socket cap, 12mm (length of threaded part - 15mm total) + nuts
- some strong double-sided tape 
Notice 1: you must adjust the SX1308 for giving an output of about 5.7V FIRST THAN assembly the circuit.
Notice 2: don't recharge and power the robot at same moment!

![18650 powering](../media/instructions/powering/18650.png)

The 18650 LiPo cell will take place under the robot using the 3D-printed holder.  
TP4056 and SX1308 PCBs will be attached in the central part of the robot using double-sided tape.  
You must put the JP1 jumper in the VSERVO position and you can close the the "logics" pad.  
Now all the robot parts (logics and servos) will be powered from the same battery: Logics will be powered at about 5V and servo at about 5.7V.

For charging the battery you must:
- Turn off the button/switch on the back
- Attach outputs of the TP4056 module on the battery using alligator clips (or make and share your own design)
- Battery will be fully charged when blue led on TP4056 module turns on 
