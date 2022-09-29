## ARLOK Bill Of Materials

> Quick link to this page: [https://tinyurl.com/shieldarlok](https://tinyurl.com/shieldarlok)  

### Summary

1) [Electronics - PCB](#pcb)
2) [Electronics - Shield Components, detailed list](#shield)
3) [Electronics - Shield Components, shopping list](#shieldc)
4) [Electronics - External components](#ext)
5) [Mechanics   - 3D-printed parts](#3d)
6) [Mechanics   - Components](#mech)
7) [🇮🇹 All Parts - Links to products only for Italian Users](#ita)

### <a name="pcb"></a>1) Electronics - PCB

Step 1: Subscribe to PCBWay using my invite link:
        https://www.tinyurl.com/pcbwaysz

Step 2: Order the ARLOK shield PCB from the following link:
        https://tinyurl.com/arlokshield
        
> If you don't want to buy the Arlok PCB, you can use an Arduino Uno protoshield and make your own shield connecting external components (servo, ultrasonic sensor, display ecc) to the Arduino pins following the [schematic](arlok_schematic.png) and/or the [connection table](connections.md).

### <a name="shield"></a>2) Electronics - Shield Components (detailed)

| Part         | Value                                          | Notes                            |
|--------------|------------------------------------------------|----------------------------------|
| C1           | 100nF multilayer                               | pitch 5mm                        |
| C2           | 100nF multilayer                               | pitch 5mm                        |
| C3           | 1000uF 16V electrolytic                        | pitch 3.5mm dia 8mm              |
| C4           | 100nF multilayer                               | pitch 5mm                        |
| C5           | 100nF multilayer                               | pitch 5mm                        |
| C6           | 100nF multilayer                               | pitch 5mm                        |
| D1           | 1N400x  (good 1N4001, 1N4007 ecc)              |                                  |
| R1           | 22KΩ ¼W                                        |                                  |
| R2           | 15KΩ ¼W                                        |                                  |
| R3           | 330Ω ¼W                                        |                                  |
| R servo *    | 4x 22KΩ ¼W 1%                                  | ONLY for servo modification      |
| P1           | tactile switch 6x6mm (long button)             |                                  |
| P2           | tactile switch 6x6mm (long button)             |                                  |
| RESET        | tactile switch 6x6mm                           |                                  |
| VR1          | 10KΩ trimmer                                   | Type PT10LV10 (good 5K÷20K)      |
| L1           | led 3mm                                        |                                  |
| H1 **        | male pinheader 10pin                           | Arduino header - solder on top   |
| H2 **        | male pinheader 8pin                            | Arduino header - solder on top   |
| H3 **        | male pinheader 5pin                            | Arduino header - solder on top   |
| H4 **        | male pinheader 4pin                            | Arduino header - solder on top   |
| EXT (EXT1)   | male pinheader 7pin                            |                                  |
| EXT2 (A1)    | male pinheader 3pin                            |                                  |
| EXT3 (A2)    | male pinheader 3pin                            |                                  |
| EXT4 (A3)    | male pinheader 3pin                            |                                  |
| HC-SR04      | male pinheader 4pin                            |                                  |
| I2C          | male pinheader 4pin (optional)                 |                                  |
| J1 (COMM)    | female pinheader 6pin                          |                                  |
| JP1          | male pinheader 3pin + jumper                   |                                  |
| JSW (POWER)  | male pinheader 2pin + jumper OR 2.54mm switch  |                                  |
| LEFT_SERVO   | male pinheader 3pin                            |                                  |
| RIGHT_SERVO  | male pinheader 3pin                            |                                  |
| OLED         | female pinheader 4pin                          |                                  |
| X1           | Screw Terminal 2pin                            | Pitch 5mm                        |
| X2           | Screw Terminal 2pin                            | Pitch 5mm                        |
| GROVE        | GROVE male header (optional)                   |                                  |

(*) only needed if you have (bought) standard analog servos not capable of 360° turning  
(**) standard headers are 11mm long: this are good if you use Cytron MakerUNO board. If you want to use a standard Arduino UNO, 11mm headers are not good, since the USB connector will touch under Arlok shield, so in this case 15mm headers are needed

### <a name="shieldc"></a>2) Electronics - Shield Components (shopping list)

| Qt. | Part                                                          |
|-----|---------------------------------------------------------------|
|  5  | 100nF multilayer capacitor,  pitch 5mm                        |
|  1  | 1000uF 16V electrolytic capacitor, pitch 3.5mm dia 8mm        |
|  1  | 1N400x diode                                                  |
|  5  | 22KΩ ¼W 1% resistor                                           |
|  1  | 15KΩ ¼W resistor                                              |
|  1  | 330Ω ¼W resistor                                              |
|  2  | tactile switch 6x6mm, long button                             |
|  1  | tactile switch 6x6mm                                          |
|  1  | 10KΩ trimmer, Type PT10LV10 (10x10mm)                         |
|  1  | LED 3mm                                                       |
|  2  | Screw terminal, pitch 5mm                                     | 
|  2  | 40pin male headers (needed 60pin)                             |
|  1  | female header (needed 6+4 pin)                                |
|  1  | jumper block, pitch 2.54mm                                    |
|  1  | PCB lever switch, pitch 2.54mm (or 2 pin male header+jumper)  |
 

### <a name="ext"></a>3) Electronics - External components

| Qt.          | Description                                                              |
|--------------|--------------------------------------------------------------------------|
| 1x           | Cytron MakerUNO board                                                    |
| 2x           | Servo MG996R modded for continuos rotation OR Servo having 360° rotation |
| 1x           | HC-SR04 Ultrasonic sensor                                                |
| 1x           | Bluetooth module HC-05 (or HC-06) - Needed for Bluetooth remote example  |
| 1x           | Cytron MakerLine board - Needed for Line Follower example                |
| 1x           | OLED display module I2C (4pin) 0.96"                                     |
| 1x           | Battery Holder for 4AA batteries                                         |
| 1x           | Battery Holder for 3AA batteries                                         |
| 1x           | Round pushbutton with retain or lever switch (*)                         |
| 1x           | 4pin Female/Female Dupont cable (~15cm) (**)                             |
| 7x           | AA 1.5V Batteries (***)                                                  |

(*)  Print the `arlok_pillar_hole_xx.stl` according the pushbutton diameter  

(**) Used for connecting ultrasonic module to PCB, you can use also 4 separate F/F jumper
     cables or make your own cable using connector you prefer.
  
(***) Not adviced to use NiCd or NiMH batteries, since voltage of those batteries is 1.2V. 
     Eventually you can use only 4NiMH batteries in the 4AA battery holder and don't use the 
     3AA battery holder: then you can power all robot using the 4AA. In this case don't mount
     D1 (put a piece of wire and pay attention to power orientation), put the power jumper JP1
     in VSERVO position and keep the fingers crossed: the servo will absorb more current and
     malfunction (such as resets on board or on the bluetooh module) can occur. This solution
     is NOT tested! There is also a mod for using one LiPo Battery but it's at your own risk,
     read more here: [LiPo Mod](lipo_mod.md)

### <a name="3d"></a>4) Mechanics - 3D-printed parts

Please see in the [STL folder](../cad/stl)

### <a name="mech"></a>5) Mechanics - Components

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

### <a name="ita"></a>6) All Parts - Links to products only for Italian Users

Solo per gli utenti italiani: ho preparato un Google Spreadsheet con l'elenco di tutte le parti e i link dove acquistarli, il link è indicato più in basso. nello spreadsheet c'è l'elenco completo dei materiali standard, tranne che per il PCB dello Shield, per il quale potete vedere al [punto 1](#pcb) di questo documento.

I link verso FuturaShop e verso Amazon contengono un codice di affiliazione: per voi il prezzo rimane lo stesso sia con che senza codice (potete verificare facilmente), ma con l'affiliazione guadagno dei crediti (su Futura) o buoni regalo (su Amazon) che posso utilizzare per comprare altro materiale presso di loro. Ci tengo a precisare, quindi, che ho scelto che i codici non mi vengano convertiti in denaro proprio perchè utilizzo questi crediti per ottenere altri materiali con cui lavorare sui miei progetti, per cui acquistando da quei link contribuite a sostenere questo lavoro.  

In linea di massima è più conveniente per voi acquistare i pezzi singoli su FuturaShop dal momento che per molte cose, su Amazon, è possibile acquistare solo bundle di più pezzi (ad esempio non è possibile acquistare un singolo portabatterie su Amazon ma solo un kit con più pezzi, e così anche per display, sensore ultrasuoni ecc), mentre su Futura è possibile acquistare il pezzo singolo risparmiando tanto.

Il link allo spreadsheet è il seguente:  [https://docs.google.com/[...]](https://docs.google.com/spreadsheets/d/1E60JlRyjGpX6OEBXnhZLZwZUzDe8-Zud6jBREFa6QfA/)

> Link abbreviato allo spreadsheet: [https://tinyurl.com/bomarlok](https://tinyurl.com/bomarlok)

Se volete risparmiare: Il modulo Bluetooth è un optional, è necessario però se volete realizzare l'esempio del robot controllato da remoto col cellulare, in alternativa potete prendere l'HC-06 che costa leggermente di meno. Il Modulo MakerLine è un optional, è necessario se volete realizzare l'esempio del line-follower. Il display OLED è un optional ma è consigliato perchè torna utile anche come sistema di debug e durante la taratura dei servocomandi. Considero il modulo ultrasuoni come sensore di base per realizzare almeno l'esempio explorer.  

Riguardo alle viti da utilizzare: le 12 viti con la parte filettata da 12mm dovrebbero essere preferibilmente del tipo TCEI per poterle stringere con una chiave a brugola a L dato che si trovano in posti in cui non è facile mettere un giravite dritto, ma potete usare il tipo che preferite purchè non a testa svasata. Le 8 viti da 6mm servono per fissare la Maker UNO al telaio usando i distanziali: potreste, in alternativa usare del biadesivo dato che la MakerUno sotto è liscia, oppure potete usare delle viti a piacere purchè non a testa svasata. Le due viti da 8mm a testa svasata devono essere necessariamente a testa svasata perchè questo consente alla testa di "scomparire" nel portabatterie senza essere toccate dalla batterie. [Qui è presente una foto delle viti consigliate](../media/arlok_screws_ita.jpg).

Per alcune piccole parti, come resistenze, condensatori, viti, dadi ecc, purtroppo non è possibile acquistare nè su Amazon, nè su FuturaShop, il singolo componente, per cui ho messo dei link che puntano a kit con più componenti che potete tenere come scorta. Oppure potete cercare quelle parti su altri siti di vendita online. Solo il Trimmer è da cercare su altri siti.
