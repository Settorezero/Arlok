# Arlok  
## Arduino Robot with MakerUNO - 3D-print it yourself!
![Arlok Front View](./media/arlok_front_view_16_9.jpg)

Arlok is the second version of [AR.L.O.](https://github.com/Cyb3rn0id/AR.L.O.) made to be compatible with the [MakerUNO](https://makeruno.com.my/) board.  

## Buy a PCB  
Making the PCB on PCBWay will support my work, but you need to subscribe to PCBWay first: you can do it using [my invite link](https://www.pcbway.com/setinvite.aspx?inviteid=355653&from=settorezero2020).  
The you can let you make the [PCB on PCBWay](https://www.pcbway.com/project/shareproject/ARLOK_arduino_robot.html)

## Print it by yourself!
In the [STL folder](./stl) are located all parts you can 3Dprint by yourself. An [exploded view](./media/arlok_3d_exploded.stl) shows how parts have to be placed.

## Code examples
See in the [Arduino folder](./arduino) for code examples

## Connections

| Arduino PIN | AR.L.O. (Arduino UNO) | ARLOK (MakerUNO)                          | Notes                   |
|-------------|-----------------------|-------------------------------------------|-------------------------|
| A0          | Trimmer VR1           | Trimmer VR1                               |                         |
| A1          |                       |                                           |                         |
| A2          |                       |                                           |                         |
| A3          |                       |                                           |                         |
| A4          | Don't use if OLED!    | Not available                             | Shared with SDA         |
| A5          | Don't use if OLED!    | Not available                             | Shared with SCL         |
| D0          | UART RX > COMM RX     | UART TX > COMM RX                         |                         |
| D1          | UART TX > COMM TX     | UART TX > COMM TX                         | Through voltage divider |
| D2          | Sonar - Echo          | Pushbutton 1 ('button' on MakerUNO board) |                         |
| D3          |                       | Sonar - Echo                              |                         |
| D4          |                       | Sonar - Trigger                           |                         |
| D5          |                       | Pushbutton 2                              |                         |
| D6          | Pushbutton 1          |                                           |                         |
| D7          | Pushbutton 2          |                                           |                         |
| D8          | Sonar - Trigger       | Buzzer on MakerUNO board                  |                         |
| D9          | ServoMotor - Right    | ServoMotor - Right                        |                         |
| D10         | ServoMotor - Left     | ServoMotor - Left                         |                         |
| D11         |                       |                                           |                         |
| D12         |                       |                                           |                         |
| D13         |                       |                                           |                         |
| D14         |                       |                                           |                         |
| SDA         | OLED SDA              | OLED SDA + Grove                          | Shared with A4          |
| SCL         | OLED SCL              | OLED SCL + Grove                          | Shared with A5          |
