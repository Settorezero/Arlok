## Modifica servocomandi

Questa è una guida per eseguire la modifica di un normale servocomando RC in modo da trasformarlo in un servo a rotazione continua. Questa procedura **not è necessaria** se hai già un servo a 360°.  
[Qui c'è un video](https://www.youtube.com/watch?v=_Ubauj75d9E) che illustra questa procedura.

Materiale necessario:

- 4 resistenze 22KΩ ¼W 1%
- un piccolo bisturi/taglierino (se hai un servo con ingranaggi di plastica) o una pinza (se hai un servo con ingranaggi metallici)
- un piccolo cacciavite a croce
- saldatore
- aspirastagno

gira il servocomando dalla parte delle 4 viti di chiusura nella parte bassa:

![servo mod](../media/instructions/servo_mod/servo_mod_001.jpg)

Svita le viti:

![servo mod](../media/instructions/servo_mod/servo_mod_002.jpg)

Apri la scatola del servocomando:

![servo mod](../media/instructions/servo_mod/servo_mod_003.jpg)

Visualizza gli ingranaggi:

![servo mod](../media/instructions/servo_mod/servo_mod_004.jpg)

Estrai l'ingranaggio del mozzo e il cuscinetto a sfera su di esso:

![servo mod](../media/instructions/servo_mod/servo_mod_005.jpg)

Guarda questo ingraggio: ha un nottolino al di sopra, nei servo con ingranaggi metallici, come il MG996R, è metallico:

![servo mod](../media/instructions/servo_mod/servo_mod_006.jpg)

Quel nottolino serve a bloccare la rotazione continua dell'ingranaggio: bisogna rimuoverlo. Nei servo in plastica puoi tagliarlo con il bisturi (ma questa procedura non è reversibile!): fai con estrema cura senza applicare troppa forza altrimenti rischi di rompere l'ingranaggio!
Nei servo metallici il nottolino può essere estratto con una pinza dato che, generalmente, viene inserito a pressione in un foro:

![servo mod](../media/instructions/servo_mod/servo_mod_007.jpg)

Estrai il circuito stampato del servocomando:

![servo mod](../media/instructions/servo_mod/servo_mod_008.jpg)

Nella parte superiore del servocomando spunta fuori l'alberino del potenziometro: devi premerlo con delicatezza verso il basso per far fuoriuscire il potenziometro:

![servo mod](../media/instructions/servo_mod/servo_mod_009.jpg)

Devi avere PCB e potenziometro a portata di mano:

![servo mod](../media/instructions/servo_mod/servo_mod_010.jpg)

Dissalda i cavetti (o i terminali) del potenziometro:

![servo mod](../media/instructions/servo_mod/servo_mod_011.jpg)

Prendi le resistenze da 22KΩ 1% e arrangiale in questo modo:

![servo mod](../media/instructions/servo_mod/servo_mod_012.jpg)

Metti le resistenze nei pad che erano riservati al potenziometro. In questo modo il controller del potenziometro crederà che il servo si trova sempre in posizione centrale per cui non smetterà mai di far girare il motore (a meno che non gli inviamo il segnale di posizione centrale):

![servo mod](../media/instructions/servo_mod/servo_mod_013.jpg)

Rimonta il servo. Fai lo stesso con l'altro servo.
