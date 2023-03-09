## Elenco componenti ARLOK

> Link rapido a questa pagina: [https://tinyurl.com/bomarlokita](https://tinyurl.com/bomarlokita)  

Un elenco componenti con il link dove acquistarli è presente qui: [https://tinyurl.com/bomarlok](https://tinyurl.com/bomarlok)

### Indice

1) [Parte Elettronica - PCB](#pcb)
2) [Parte Elettronica - Componenti PCB rev.1, in dettaglio](#shield)
3) [Parte Elettronica - Componenti PCB rev.1, lista della spesa](#shieldc)
4) [Parte Elettronica - Componenti esterni](#ext)
5) [Parte Meccanica - Pezzi da stampare in 3D](#3d)
6) [Parte Meccanica - Altro](#mech)
7) [Schede compatibili Arduino UNO R3 consigliate](#boards)
8) [Differenze tra PCB REV1 e prima release](#diffrev1)

### <a name="pcb"></a>1) Parte Elettronica - PCB

Step 1: Iscriviti a PCBWay utilizzando il mio link di invito:
        https://www.tinyurl.com/pcbwaysz

Step 2: Ordina lo Shield di Arlok, revisione 1, utilizzando questo link:
        [https://tinyurl.com/arlokshieldr1](https://tinyurl.com/arlokshieldr1)
        
> Se non vuoi comprare il PCB di Arlok, potresti anche utilizzare un protoshield per Arduino UNO facendo tu i collegamenti seguendo lo [schema elettrico](arlok_schematic_rev1.png) e/o la [tabella delle connessioni](connections.md).

### <a name="shield"></a>2) Parte Elettronica - Componenti PCB rev.1, dettaglio

> Puoi anche scaricare questo elenco dal seguente link: [Elenco componenti in formato PDF](./pdfs/arlok_shield_BOM.pdf)

| Componente   | Valore                                         | Note                              |
|--------------|------------------------------------------------|-----------------------------------|
| C1           | 100nF multilayer                               | passo 5mm                         |
| C2           | 100nF multilayer                               | passo 5mm                         |
| C3           | 1000uF 16V electrolytic                        | passo 3.5mm - dia. 8mm            |
| C4           | 100nF multilayer                               | passo 5mm                         |
| C5           | 100nF multilayer                               | passo 5mm                         |
| C6           | 100nF multilayer                               | passo 5mm                         |
| C7           | 220uF 16V elettrolitico                        | passo 2.5mm - dia. 6mm            |
| D1           | 1N4007                                         | va bene un qualsiasi 1N400x       |
| R1           | 22KΩ ¼W                                        | rosso - rosso - arancio           |
| R2           | 15KΩ ¼W                                        | marrone - verde - arancio         |
| R3           | 330Ω ¼W                                        | arancio - arancio - marrone       |
| P1           | pulsantino da pcb                              | 6x6mm (consigliato pulsante alto) |
| P2           | pulsantino da pcb                              | 6x6mm (consigliato pulsante alto) |
| RESET        | pulsantino da pcb                              | 6x6mm                             |
| VR1          | trimmer 5kΩ ÷ 20kΩ                             | 6x6mm                             |
| L1           | led 3mm                                        |                                   |
| H1 (*)       | pinheader maschio 10pin                        | Header Arduino - saldare da sopra |
| H2 (*)       | pinheader maschio  8pin                        | Header Arduino - saldare da sopra |
| H3 (*)       | pinheader maschio  5pin                        | Header Arduino - saldare da sopra |
| H4 (*)       | pinheader maschio  4pin                        | Header Arduino - saldare da sopra |
| EXT (EXT1)   | pinheader maschio  7pin                        |                                   |
| EXT2 (A1)    | pinheader maschio  3pin                        |                                   |
| EXT3 (A2)    | pinheader maschio  3pin                        |                                   |
| EXT4 (A3)    | pinheader maschio  3pin                        |                                   |
| HC-SR04      | pinheader maschio  4pin                        |                                   |
| I2C          | pinheader maschio  4pin                        | opzionale                         |
| J1 (COMM)    | pinheader femmina  6pin                        |                                   |
| JP1          | pinheader maschio  3pin + jumper               |                                   |
| JSW (POWER)  | pinheader maschio  2pin + jumper               | o interruttore a slitta passo 2.54mm |
| LEFT_SERVO   | pinheader maschio  3pin                        |                                   |
| RIGHT_SERVO  | pinheader maschio  3pin                        |                                   |
| OLED         | pinheader maschio  4pin                        |                                   |
| X1           | Terminale a vite   2pin                        | 5mm pitch                         |
| X2           | Termninale a vite  2pin                        | 5mm pitch                         |
| GROVE        | Connettore GROVE maschio da PCB                | opzionale                         |

> (*) Gli headers maschio standard sono lunghi 11mm : questi vanno bene soltanto se utilizzi una delle board Aduino UNO compatibili consigliate (vedi più in basso). Se vuoi utilizzare un Arduino UNO standard, gli headers da 11mm non vanno bene perchè il connettore USB tocca sulle saldature del PCB; in questo caso devi utilizzare degli header maschio da 15mm (più difficili da trovare) oppure gli header Arduino standard (passanti, femmina sopra e maschio sotto)  
> Nota: se devi eseguire la modifica dei servocomandi per la rotazione continua, sono necessarie altre 4 resistenze 22KΩ ¼W, possibilmente all'1% di tolleranza

### <a name="shieldc"></a>3) Parte Elettronica - Componenti PCB rev.1, lista della spesa

| Qt. | Componente                                                    |
|-----|---------------------------------------------------------------|
|  5  | Condensatore multilayer 100nF, passo 5mm                      |
|  1  | Condensatore elettrolitico 1000uF 16V, passo 3.5mm dia. 8mm   |
|  1  | Condensatore elettrolitico 220uF 16V, passo 2.5mm dia. 6mm    |
|  1  | Diodo 1N400x                                                  |
|  1* | Resistenza 22KΩ ¼W                                            |
|  1  | Resistenza 15KΩ ¼W                                            |
|  1  | Resistenza 330Ω ¼W                                            |
|  2  | Pulsante da pcb 6x6mm, asta lunga                             |
|  1  | Pulsante da pcb 6x6mm                                         |
|  1  | Trimmer 5kΩ ÷ 20kΩ  formato 6x6mm                             |
|  1  | LED 3mm                                                       |
|  2  | Terminale a vite da PCB, passo 5mm                            | 
|  2  | Header maschio da 40pin (da dividere in pezzi)                |
|  1  | Header femmina da 40pin (da tagliare in pezzi)                |
|  1  | Blocchetto jumper passo 2.54mm                                |
|  1  | Interruttore a levetta da PCB, passo 2.54mm (**)              |
 
> (*) se devi eseguire la modifica dei servocomandi per la rotazione continua, sono necessarie altre 4 resistenze 22KΩ ¼W, possibilmente all'1% di tolleranza
> (**) oppure un blocchetto jumper, e utilizzi due pinheader maschio + il blocchetto jumper come se fosse un interruttore

### <a name="ext"></a>4) Parte Elettronica - Componenti esterni

| Qt.          | Descrizione                                                              |
|--------------|--------------------------------------------------------------------------|
| 1x           | Board Arduino UNO compatibile consigliata (*)                            |
| 2x           | Servocomando MG996R modificato a 360° o servo a rotazione continua       |
| 1x           | Sensore Ultrasuoni HC-SR04                                               |
| 1x           | Modulo Bluetooth HC-05 (or HC-06) - Per esempio Bluetooth                |
| 1x           | Modulo Cytron MakerLine - Per esempio Line Follower                      |
| 1x           | Display OLED 0.96" I2C                                                   |
| 1x           | Portabatterie per 4AA                                                    |
| 1x           | Portabatterie per 3AA                                                    |
| 1x           | Pulsante rotondo a ritenuta o interruttore a levetta (**)                |
| 1x           | Cavo dupont femmina/femmina a 4 pin (~15cm) (***)                        |
| 7x           | Batteria AA 1.5V (****)                                                  |

(*) Vedi lista più in basso

(**)  Ricordati di stampare in 3D il pezzo `arlok_pillar_hole_xx.stl` in base al diametro dell'interruttore che acquisti

(***) Questo è usato per collegare il modulo ultrasuoni al PCB: puoi anche usare 4 cavetti jumper F/F, oppure rimuovi gli header e saldi dei fili... fa come preferisci
  
(****) Non è consigliato utilizzare batterie NiCd o NiMH batteries dato che la tensione di queste batterie è 1.2V, quindi troppo bassa e può causare malfunzionamenti. In alternativa potresti seguire la guida per fare la [modifica con le batterie LiPo](lipo_mod_ita.md)

### <a name="3d"></a>5) Parte Meccanica - Pezzi da stampare in 3D

Guarda nella [cartella STL](../cad/stl)

### <a name="mech"></a>6) Parte Meccanica - Altro

| Qt.          | Descrizione                                                                  |
|--------------|------------------------------------------------------------------------------|
| 12x          | Vite M3 12mm (lunghezza filetto, ~15mm in totale)                            |
| 8x           | Vite M3 screw 6mm (lunghezza filetto, ~8mm in totale)                        |
| 14x          | Rondella M3 (opzionale ma consigliate)                                       |
| 12x          | Dado M3                                                                      |
| 2x           | Vite M3, testa svasata, 8mm (lunghezza filetto,~10mm in totale)              |
| 4x           | Distanziale esagonale F/F 8 o 10mm                                           |
| 1x           | Ballcaster Tamiya modello 70144 (*)                                          |
| 2x           | O-Ring, 70mm diametro interno, spessore 2-3mm (**)                           |

[Qui c'è una fotografia che illustra le viti necessarie](../media/arlok_screws_ita.jpg).

(*) Quando acquisti il ballcaster Tamiya 70144, ci sono pezzi per costruire 2 ball caster: potresti costruire un altro Arlok o darlo ad un amico così che lo costruisca anche lui!
    In alternativa puoi stampare in 3D il [Ball Caster V2 su Thingiverse](https://www.thingiverse.com/thing:1408935) con una'altezza di 30mm (Devi però saper usare [OpenScad](https://openscad.org/) per modificare il file .scad)

(**) In alternativa, se la tua stampante è in grado di stampare il TPU potresti anche stampare un modello di pneumatico tra quelli messi a disposizione nella [cartella STL](../cad/stl).
	 
### <a name="boards"></a>7) Schede compatibili Arduino UNO R3 consigliate

Dal momento che lo shield di Arlok è stato disegnato utilizzando una normale board Arduino UNO come base, schede aventi componenti "alti" (come il connettore USB tipo B della Arduino UNO R3 originale), non possono essere utilizzate altrimenti "toccano" nella parte inferiore dello shield causando corto-circuiti e quindi notevoli danni.
L'unico modo di utilizzare una scheda Arduino UNO R3 originale è quello di assemblare lo shield utilizzando degli header maschio da 15mm (non tanto comuni) oppure gli header passanti tipici di Arduino.
Qui invece c'è un elenco di board "basse", compatibili, che non utilizzano il connettore USB-B
- [Keyestudio 328 Plus](https://amzn.to/3EVcUJO)
- [Cytron Maker UNO](https://www.cytron.io/p-maker-uno-simplifying-arduino-for-education)
- [Arduino Make Your UNO](https://store.arduino.cc/pages/make-your-uno-kit) 
- [Seeeduino 4.2](https://www.seeedstudio.com/Seeeduino-V4-2-p-2517.html)
- [Grove Beginner Kit](https://www.seeedstudio.com/Grove-Beginner-Kit-for-Arduino-p-4549.html)

Alcune delle schede elencate hanno il connettore di alimentazione di tipo Barrel Jack che pure è alto e può toccare sotto allo shield: il connettore in genere è di plastica quindi non causa corto circuiti, ma per sicurezza cerca di limare un po' le saldature sotto lo shield che possono toccare sul connettore e metti un pezzetto di nastro isolante per sicurezza.

### <a name="diffrev1"></a>8) Differenze tra PCB REV1 e prima release

- Aggiunto C7 per avere un po' di scorta di energia in più per componenti esterni
- Aggiunto un via (non collegato) vicino al GND dell'header di alimentazione, in caso fosse necessario riportare sullo shield la tensione VIN di Arduino
- Cambiata la serigrafia del connettore JSW da "POWER" a "LOGICS POWER" per non creare confusione dato che è utilizzato solo per la tensione dei 5V
- Aggiunto un via (not collegato) affianco al connettore JSW se vuoi utilizzare un interruttore a slitta a 3 pin (=un deviatore)
- Cambiato il trimmer VR1 dal tipo PT10LV10 (10x10mm) ad un tipo più piccolo (6x6mm)e facile da trovare. Ad ogni modo c'è comunque un via aggiuntivo collegato al pin centrale se hai già/vuoi utilizzare un trimmer da 10x10mm
- Aggiunta la serigrafia "A0" affianco a VR1 per ricordarsi dove è collegato il trimmer
- Estesa l'area di prototipazione (sono stati aggiunti altri 21 vias)
- Cambiata la serigrafia dei connettori a vite: è stato tolto il segno "-" e le scritte sono più leggibili
- Rimosso il logo OR e aggiunto quello di "Pizza Robotics - In pizza we crust" one
