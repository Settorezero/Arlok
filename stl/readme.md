# Arlok 3D Files for 3d-Printing 
This folder contains parts to be 3D-printed. I Reccomend [Sunlu PLA+](https://amzn.to/3aG5V7i) filament.  

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

## Parts
You can see the [Exploded View](../images/arlok_3d_exploded.stl) for seeing how parts are to be assembled.  
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
Frontal part is the one with the 2 slotted holes on the bottom. Those holes are used, eventually, for attaching the Cytron Makerline module used for the line follower example. Servos to be mounted on top in the grooves with the shaft towards the front.

### Plate Top
You'll mount the Maker UNO board on top. The two lateral wings will hold the 4AA battery holder in place.

### Sonar Pillar
There are 2 variants: the standard, having squared edges, and the one with rounded edges, print only one of these

### Rear Pillar
There are 3 variants that differs for the hole diameter used for the switch that detaches the 4AA batteries of the servo power. Print only 1 of these. 6mm variant will be used for the classic lever switch. 10mm variant is used for the [10mm lock pushbuttons](https://amzn.to/31bjusa). 12mm variant is used for the [12mm lock pushbuttons](https://www.futurashop.it/mini-interruttore-pulsante-rosso-2846-ch32037?tracking=5f004a6ba8be7).

### Eyelashes
Those are designed to give Arlok a female look (we call she _ARLOKKA_) by attaching them on the Ultrasonic sensor capsules. Are also useful for mantaining the ultrasonic sensor in position if holes were too large.

### Via Pixetto support
This support is used for attaching a [Via Pixetto Ai Camera](https://pixetto.ai/) on top/front of ARLOK. The support is a hinge made of 2 pieces: you must use a long M3 screw and a nut. In the STL there are also 4 small spacers used for distancing the camera from the base: you must use M2 screws and nuts

## Wheel and Ball-Caster 
An O-Ring will be applied to the wheel for giving grip. The wheels will be attached to the servo Horns.  
The [Wheel](arlok_wheel.stl) is optimized to be used with the round horn that comes with the MG996 servo and for an o-ring having an internal diameter of 70-71mm and a section of about 2mm. Wheels are generated with [Openscad](https://www.openscad.org/) using [Obijuan script](https://www.thingiverse.com/thing:19940) of the Servo Wheel on Thingiverse. You can found the script also on his [Github Repo for Miniskybot](https://github.com/Obijuan/Miniskybot/). 

In the script you can customize all wheel parameters. I've generated the provided wheels with following measures: 
- external (finished) diameter: 75mm
- height: 5mm
- horn diameter: 21mm. 

See the following image for understanding servo parameters in the openscad script:  

![Servo Horn measures](../docs/servo_horn_measures.jpg)  

A Tamiya 70144 ball-caster is used as third foothold. Ball caster will be mounted in the 27mm height version but without the M1 washers, so the total height of the ball caster will be 25mm.

## About Models
Arduino model, used for sizing and holes, is from [cmspooner on Thingiverse](https://www.openscad.org/)
