## ARLOK troubleshooting

How to resolve common problems with ARLOK

> Quick link to this page: [https://tinyurl.com/troubleshootingarlok](https://tinyurl.com/troubleshootingarlok)

1) [ARLOK doesn't turn or doesn't move](#movement)
2) [ARLOK make too little or too big movement while turning](#turning)

### <a name="movement"></a> ARLOK doesn't turn or doesn't move

Servos are driven by an impulse. Don't forget we're using modified servos, so an impulse of about 1500mS means servo stopped (a normal servo will turn to 90 degrees), an impulse less than 1500mS will make servo moving to a direction, an impulse greater than 1500mS will make servo moving in opposite direction.   

ARLOK movement is based on a central position (default 1500mS, the setup procedure is used for modifying this value) ± a constant value: ARLOK moves forward or backward using an impulse of (1500mS ± `SPEED`) or turns left or right using an impulse of (1500mS ± `SPEED_SLOW`).  

`SPEED` and `SPEED_SLOW` are defined in the source code, by default:

```
#define SPEED  200 // normal speed for forward moving (center point+speed microseconds)
#define SPEED_SLOW 50 // speed used for maneuvers
```

If ARLOK cannot move forward or backwars then raise the value assigned to 
`SPEED`, example:

```
#define SPEED  500
```

If ARLOK cannot turn left or right raise the value assigned to `SPEED_SLOW`, example:

```
#define SPEED_SLOW  200
```

### <a name="turning"></a> ARLOK make too little or too big movement while turning

The amount of movement during a turn is defined by the `TURN_TIME` value. This value is expressed in milliseconds. By default this value is 1000 (1 second = ARLOK will make the movement to left of right for 1 second):

```
#define TURN_TIME 1000 // amount of time used for turning
```

If movement of a turn is less than 90 degree, raise this value. Example:

```
#define TURN_TIME 1200 
```

If movement of a turn is greater than 90 degree, lower this value. Example:

```
#define TURN_TIME 800 
```