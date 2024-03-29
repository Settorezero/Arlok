## Istruzioni montaggio ARLOK in italiano

> Link rapido a questa pagina: [https://tinyurl.com/arlokmontaggio](https://tinyurl.com/arlokmontaggio)  

> Le misure delle viti sono espresse in millimetri e si riferiscono alla lunghezza della sola parte filettata, quindi testa esclusa

> ATTENZIONE: Questa guida passo-passo è stata pensata per il funzionamento di Arlok con le batterie AA dal momento che è il sistema più sicuro, ma ci sono [altri modi per far funzionare il robot](powering.md). Puoi anche, in seguito, [passare dalle batterie AA ad una 18650(lipo_mod_ita.md).

E' anche presente un [video su youtube](https://youtu.be/yHwYimkA6Dw) che illustra il montaggio passo-passo: si consiglia vivamente di vedere il video.

![Arlok Parts](../media/arlok_parts.jpg)  

### Fasi preliminari

- Avete acquistato due servocomandi che ruotano a 360° oppure avete già modificato due normali servocomandi analogici per avere la rotazione continua (vedi [modifica dei servocomandi](servo_mod_ita.md) oppure [vedi questo video su youtube](https://www.youtube.com/watch?v=_Ubauj75d9E) )
- Avete già assemblato lo shield di Arlok
- Procuratevi alcune piccole fascette: torneranno utili per l'organizzazione dei cavi e per avere un risultato più pulito.

Aprite eventualmente la [Vista esplosa di ARLOK](./media/arlok_3d_exploded.stl) in una nuova finestra: vi tornerà molto utile per vedere come vanno posizionati ed orientati i pezzi.

Prendete la base (`arlok_plate_bottom`): la parte frontale-superiore è quella con la freccia e i due slot laterali. La freccia indica dove è posizionata la "faccia" del robot, ovvero quella con le capsule ultrasuoni.

![Base Arlok](../media/instructions/plate_bottom_overview.png)

Gli incavi a forma di C o i fori più grandi possono essere utilizzati per far passare i vari cavi.

Gli step contrassegnati con un asterisco sono quelli che riguardano la sezione di alimentazione: sono illustrati gli step standard che prevedono l'utilizzo di batterie AA, che sono sicure. Se invece vuoi alimentare Arlok utilizzando una cella Lipo, c'è una guida a parte: [modifica per utilizzo 18650](lipo_mod_ita.md), per cui gli step con asterisco vanno saltati oppure eseguiti parzialmente facendo riferimento alla guida a parte.


### STEP 1 *

Agganciare il portabatterie per le 3 stilo sulla parte inferiore del piatto utilizzando 2 viti M3 da 8mm con testa svasata.  
La testa delle viti va chiaramente nel portabatterie e la vite fuoriesce sul lato superiore della base. Il portabatterie ha difatti i fori fatti per ospitare una vite a testa svasata che, entrando nell'incavo, non urta sulle batterie. Fissate le viti utilizzando due rondelline e 2 dadi M3.  
- Queste batterie sono utilizzate esclusivamente per alimentare la logica (ovvero la board Arduino ed eventuali accessori)  

### STEP 2
Posizionare i servocomandi negli appositi incavi presenti nella parte superiore della base. I servocomandi vanno orientati con l'asse di uscita rivolto in aventi.

![Posizionamento Servocomandi](../media/instructions/servo_alignment.png)

Posizionare le staffe di bloccaggio dei servo al di sopra dei servo. (`arlok_servo_bracket`). Le "ali" di fissaggio dei servo vanno appoggiate sulla parte piatta delle staffe, senza usare viti. Le staffe vanno fissate sulla base utilizzando 4 viti M3 da 12mm a testa esagonale incavata. Nella parte inferiore avvitare con 4 dadi M3, utilizzare le rondelle.

Utilizzando un po' di nastro carta, annotare sui connettori dei servo qual'è il destro e qual'è il sinistro in modo da non commettere errori quando andremo a collegare i connettori dei servo sul PCB.

### STEP 3
Montare il Ball-Caster Tamiya 70144 seguendo le istruzioni presenti nella confezione dello stesso. Bisogna montare il Ball-Caster nella versione da 25mm 

![Tamiya 70144 Ball-Caster](../media/instructions/ball_caster_25mm.png)

[Qui ci sono, eventualmente, le istruzioni complete del ball-caster](../media/instructions/ball_caster_instructions.png)

### STEP 4
Collegare il ball-caster alla base. Il ball caster va nella parte posteriore lato inferiore. Utilizzare 2 viti M3 12mm nei due buchi più vicini al centro lasciando liberi i 2 buchi posteriori: in questi buchi andrà difatti montato anche il pilastrino posteriore, per cui per ora vanno lasciati liberi. Utilizzare 2 dei dadi forniti col ball-caster.

![Viti ball-caster](../media/instructions/ballcaster_first_screws.png)

Le viti vanno messe dall'alto verso il basso: avvitare in basso utilizzando 2 dadi M3.

### STEP 5
Montare il pilastrino posteriore (`arlok_pillar_hole_##`): è quello con il foro all'interno del quale va messo l'interruttore. Il foro va orientato verso il basso. Per fissare il pilastrino dovete utilizzare 2 delle viti più lunghe fornite insieme al ball caster (queste viti hanno la parte filettata lunga circa 14.5mm): le viti vanno infilate da pilastrino verso il basso e devono attraversare base e ball-caster ed essere quindi avvitate con 2 dadi dal lato del ball-caster. Qui non vanno utilizzate rondelle. Utilizzate 2 dadi forniti col ball-caster.

### STEP 6 *
Saldare 2 piccoli spezzoni di cavo ai terminali dell'interruttore che avete scelto. Infilare l'interruttore nel foro del pilastrino posteriore e fissarlo col dado fornito insieme all'interruttore stesso. Assicuratevi che l'interruttore sia in posizione OFF, magari utilizzando un tester in modalità "continuità": poggiando i puntali ai terminali dell'interruttore non deve suonare (OFF), se il tester suona vuol dire che il pulsante è ON.

### STEP 7
Montare il pilastrino per il sensore ultrasuoni (`arlok_pillar_sonar`) nella parte frontale: utilizzare 2 viti M3 12mm a testa esagonale incassata dal pilastrino verso il basso. Avvitare in basso con 2 dadi M3 e rondelle.

### STEP 8
Assemblate un cavetto sul sensore ultrasuoni seguendo questa video-guida: [https://youtu.be/iF_R0xU8K-4](https://youtu.be/iF_R0xU8K-4). Oppure, se non volete fare modifiche al sensore ultrasuoni, collgatelo allo shield utilizzando 4 normali cavetti jumper femmina/femmina di circa 12cm.

### STEP 9
Innestare il sensore ultrasuoni nel pilastrino frontale con l'header rivolto in basso.

### STEP 10
Prendere la piastra superiore (`arlok_plate_top`). La parte superiore-frontale è quella con la scritta ARLOK. Mettere 4 viti M3 6mm nei fori più al centro disposti secondo il layout di Arduino. Le viti vanno messe dal basso verso l'alto e nella parte superiore, filettata, vanno avvitati 4 distanziali esagonali femmina/femmina da 8 o 10mm.

### STEP 11
Appoggiare il portabatterie per le 4 stilo al di sopra delle staffe dei servocomandi: non è necessario fissarlo/incollarlo perchè rimarrà in posizione grazie alle ali laterali della base superiore. Collegare uno dei due fili dell'interruttore al filo nero del portabatterie e isolare il punto di giunzione. Se non l'avete fatto prima: assicuratevi che l'interruttore sia in posizione OFF. Mettere quindi le 4 batterie.

### STEP 12
Posizionare la piastra superiore con la scritta `ARLOK` va rivolta in avanti, ovvero in direzione delle capsule ultrasuoni. Far passare 4 viti M3 da 12mm dai fori in cima ai pilastrini attraverso la piastra, fissare le viti nella parte superiore con rondella e dado. Se le capsule ultrasuoni danno fastidio durante il passaggio delle viti nel pilastro anteriore, premerle verso dentro in modo da farle andare a filo e riportarle al di fuori una volta terminato il fissaggio.

### STEP 13
Posizionare la board Arduino sui distanziali e bloccarla con 4 viti M3 6mm.

### STEP 14 *
- Innestare lo shield di ARLOK sulla board Arduino
- Mettere il jumper `JP1` in posizione `VDD` (questo fa in modo che la logica sia alimentata dalle 3 batterie AA sul fondo del robot)
- Collegare i fili del sensore ultrasuoni sull'header contrassegnato come `HC-SR04` rispettando i segnali
- Collegare i connettori dei due servocomandi sugli headers rispettando l'orientamento LEFT (sinistro) / RIGHT (destro) e il colore dei fili (giallo o arandio=`S`, rosso=`+`, nero o marrone=`-`)
- Spostare l'interruttorino `POWER` dello shield verso il logo OR (=posizione OFF se lo avete saldato correttamente, ovvero senza coprire la scritta RESET)
- Mettere 3 batterie AA nel portabatterie inferiore
- Mettere i 2 fili dal portabatterie inferiore (3AA) nel terminale a vite contrassegnato come `VDD` : il filo rosso va in `+`. Se vedete il led `L1` accendersi, spostare l'interruttore `POWER` sullo shield nella direzione opposta in cui si trova
- Mettere i 2 fili dal portabatterie da 4 AA nel connettore a vite `VSERVO` : il filo rosso va in `+`. Se vedete i servocomandi muoversi o fare rumore, mettere l'interruttore sul pilastrino nella posizione opposta a quella in cui si trova.

### STEP 15
- Appoggiare le squadrette tonde dei servo nell'incavo della ruota con il perno verso il lato opposto. Guardare l'immagine per non sbagliare:

![orientamento servo](../media/instructions/arlok_servo_hub_orientation.png)  
![orientamento servo](../media/instructions/arlok_servo_hub_orientation2.png)

- Le squadrette vanno fissate alle ruote utilizzando 2 delle piccole viti autofilettanti fornite con i servo. dall'esterno della ruota verso l'interno. La ruota ha già 4 piccoli buchini: usarne solo 2 posti a 180°. Bisogna applicare molta forza con un buon cacciavite per fare in modo che le viti si creino la filettatura nella plastica della ruota e della squadretta. La parte di vite che fuoriesce in genere non da problemi, ma se è troppo lunga e rischia di toccare sul servo, meglio tagliarla.
- Collegare quindi le ruote ai servo innestando il perno della squdretta sul perno del servo e fissarla utilizzando una vite, fornita coi servo, al centro della squadretta. 

### STEP 16
Posizionare gli O-Ring (o gli pneumatici stampati in 3D) sulle ruote.

### STEP 17
Caricare per primo il programma [explorer](../arduino/explorer). Come da descrizione riportata nel readme eseguire prima la procedura di setup per i servo: [potete seguire questo video](https://youtu.be/qzJxrcuSvpU).
