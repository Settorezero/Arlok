### ARLOK troubleshooting

How to resolve common problems with ARLOK

#### ARLOK doesn't turn

Servos are driven by an impulse. Don't forget we're using modified servos, so an impulse of about 1500mS means servo stopped (normal servo turns to 90 degrees), an impulse less than 1500mS make servo moving to a direction, an impulse greater than 1500mS make servo moving in opposite direction. ARLOK moves forward or backward using an impulse of (1500mS ± `SPEED`) or turns to left or right using an impulse of (1500mS ± `SPEED_SLOW`).  
`SPEED` and `SPEED_SLOW` are defined in the source code, by default:
```
#define SPEED  200 // normal speed for forward moving (center point+speed microseconds)
#define SPEED_SLOW 50 // speed used for maneuvers
```
raise `SPEED_SLOW` to an higher value for making ARLOK turn correctly.


#### ARLOK make too little turn

The amount of turning left or right is defined by `TURN_TIME` expressed in milliseconds, raise that value if turn is less than 90 degree.