# Arlok 3D Files for 3d-Printing 
This folder contains parts to be 3D-printed.  
I like to use the [Sunlu PLA+](https://amzn.to/3aG5V7i) filament.  
> Quick link to this page: [https://tinyurl.com/3dprintarlok](https://tinyurl.com/3dprintarlok)  

## Printer settings
Values in the parts table are calculated using CURA slicer with following settings:

- Layer Height: 0.2mm
- Top Layers: 5
- Bottom Layers: 5
- Wall line count: 3
- Print speed: 30mm/sec
- Infill speed: 50mm/sec
- Travel speed: 65mm/sec
- Infill density: 20%
- Generate Support: NO
- Build plate adhesion type: skirt

I use those slow settings because I've a cheap 3D-Printer and I need to print slow. Also Infill maybe is slightly oversized since pieces are pretty big. If you've a good 3D-printer you can speed-up and lower the infill.

## Parts
You can see the [ARLOK Exploded View](../media/arlok_3d_exploded.stl) for seeing how parts must be assembled.  
Part quantity in parenthesis indicates that this is an optional or an alternative part.  
Time and weight is reported for total parts if more than one is needed.

| Qt. | File                                                           | Print Time (minutes) | Weight (grams)| 
|-----|----------------------------------------------------------------|----------------------|---------------|
|  1  | [Plate Bottom](arlok_plate_bottom.stl)                         | 199 | 26 |
|  1  | [Plate Top](arlok_plate_top.stl)                               | 216 | 30 |
|  2  | [Servo Bracket](arlok_servo_bracket.stl)                       | 106 | 12 |
|  1  | [Sonar Pillar](arlok_pillar_sonar.stl)                         |  48 |  6 |
| (1) | [Sonar Pillar (round variant)](arlok_pillar_sonar_rounded.stl) |  48 |  6 |
| (1) | [6mm hole Rear Pillar](arlok_pillar_hole_06.stl)               |  40 |  6 | 
|  1  | [10mm hole Rear Pillar](arlok_pillar_hole_10.stl)              |  40 |  5 | 
| (1) | [12mm hole Rear Pillar](arlok_pillar_hole_12.stl)              |  40 |  5 | 
|  2  | [Standard Wheel](arlok_wheel.stl)                              | 178 | 28 | 
| (1) | [Eyelashes](arlok_eyelashes.stl)                               |   7 |  1 | 
| (1) | [Via Pixetto Support](arlok_via_pixetto_support.stl)           |  53 |  6 | 

Estimated total printing time for standard parts: 13H 7'  
Estimated total filament needed for standard parts: 107g (about 36meters)

## Parts description and notes

### Plate Bottom
Frontal side is the one with the 2 slotted holes on the bottom. Those slotted holes are used, eventually, for attaching the Cytron Makerline module used for the line follower example. Servos must be mounted on top placing them in the grooves and having the shaft towards the front.

### Plate Top
You'll mount the Maker UNO board on top using 4 hex spacers. The two lateral wings will hold the 4AA battery holder in place.

### Sonar Pillar
There are 2 variants: the standard, having squared edges, and the one with rounded edges, print only one of these.

### Rear Pillar
There are 3 variants that differs for the hole diameter used for the switch that detaches the 4AA batteries of the servo power. Print only 1 of these. 6mm variant will be used for the classic lever switch. 10mm variant is used for the 10mm lock pushbuttons. 12mm variant is used for the 12mm lock pushbuttons sold by FuturaShop (see [BOM in the docs folder](../docs/BOM.md)).

### Eyelashes
Those are designed to give Arlok a female look (we call she _ARLOKKA_) by attaching them on the Ultrasonic sensor capsules. Are also useful for mantaining the ultrasonic sensor in position if holes are too large.

### Via Pixetto support
This support is used for attaching a [Via Pixetto Ai Camera](https://pixetto.ai/) on top-front of ARLOK. The support is a hinge made of 2 pieces: you must use a long M3 screw and a nut. In the STL there are also 4 small spacers used for distancing the camera from the base: you must use M2 screws and nuts. Sorry but Via Pixetto example is still not ready.

### Wheel
The [Wheel](arlok_wheel.stl) is optimized to be used with the round horn that comes with the MG996 servo and for an o-ring having an internal diameter of 70mm and a section of about 2 or 3mm. A rubber O-Ring will be applied to the wheel groove for giving grip. Please don't use cyanoacrilate glue for attaching the O-Ring. The wheels will be attached to the servo Horns using 2 self-tapping screws given with the servos. Wheel is sized for giving the correct balance of the robot using the Tamiya 70144 ball caster mounted in the 27mm variant without H1 washers (so the total height of the ball caster will be 25mm).

## Notes about Wheel customization
Wheels are generated with [Openscad](https://www.openscad.org/) using [Obijuan script](https://www.thingiverse.com/thing:19940) of the Servo Wheel on Thingiverse. You can found the script also on his [Github Repo for Miniskybot](https://github.com/Obijuan/Miniskybot/). 

In the above script you can customize all wheel parameters. I've generated the default wheels using following measures:  
- external (finished) diameter: 75mm
- height: 5mm
- horn diameter: 21mm. 

See the following image for understanding servo parameters in the openscad script:  

![Servo Horn measures](../media/servo_horn_measures.jpg)