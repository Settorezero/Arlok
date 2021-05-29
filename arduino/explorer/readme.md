## Explorer

Arlok moves forward, when he see an obstacle will make a sound, stop, move back, then turn left or right randomn and continue.  

> For using the sketch with old AR.L.O. PCB, comment the `#define ARLOK`

### Setup

There is a video showing this procedure but, sorry, the language used is italian: [https://youtu.be/qzJxrcuSvpU](https://youtu.be/qzJxrcuSvpU)

Press <kbd>P1</kbd>, keep it pressed and then turn on the power switch, release <kbd>P1</kbd> only when you see something appear on the display.  
When you see `ARLOK SET` you can power the motors too pressing the button on the rear.

First page of setup menù will allow you to set the _zero_ point for the left motor: turn the trimmer until motor stops, then press <kbd>P1</kbd> for saving: value will be saved into the eeprom and will be showed between parenthesis near `LEFT MOTOR` writing on the first row of the display.  
Now press <kbd>P2</kbd> for going to the second page of the setup menù.  

> If you know the value showed in parenthesis is already good (example: you're entered in the setup menù only for balancing), you can directly skip this page by pressing <kbd>P2</kbd> even the motor is running (because the motor in this moment is taking the value given by the trimmer, not the one saved into the eeprom).  

Second page will allow you to do the same for the right motor. So, follow the same steps you read for the left motor.  

Third page will give you the possibility for _balancing_ motors speed. You can notice ARLOK will not move in a straight line when moves forward: this because motors have some little differencies and there are no encoders and a _PID_ system for balancing them, so this simple method has been implemented (thx @MrLoba81) for compensating a little the two motors.  

Turning trimmer to the right will give more speed to the right motor, so if ARLOK tends to go to the right when moves forward, turning trimmer to the right will give more speed to the right motor and then compensate this behaviour. If ARLOK tends to go to the left when moves forward, you must turn the trimmer to the left. Values are experimental so it's possibile you must repeat this setup procedure more than one time.