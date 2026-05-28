/*
 * ARLOK
 * Educational Robot based on Arduino UNO
 * (c)2020-2026 Giovanni Bernardo (https://www.settorezero.com)
 * 
 * HUSKYLENS
 *
 * https://www.github.com/settorezero/arlok
 * 
 *
 * LICENSE
 * Attribution-NonCommercial-ShareAlike 4.0 International 
 * (CC BY-NC-SA 4.0)
 * 
 * This is a human-readable summary of (and not a substitute for) the license:
 * You are free to:
 * 
 * SHARE - copy and redistribute the material in any medium or format
 * ADAPT -  remix, transform, and build upon the material
 * The licensor cannot revoke these freedoms as long as you follow the license terms.
 * Under the following terms:
 * ATTRIBUTION -  You must give appropriate credit, provide a link to the license, 
 * and indicate if changes were made. You may do so in any reasonable manner, 
 * but not in any way that suggests the licensor endorses you or your use.
 * NON COMMERCIAL -  You may not use the material for commercial purposes.
 * SHARE ALIKE -  If you remix, transform, or build upon the material,
 * you must distribute your contributions under the same license as the original.
 * NO ADDITIONAL RESTRICTIONS - You may not apply legal terms or technological 
 * measures that legally restrict others from doing anything the license permits.
 * 
 * Warranties
 * The Licensor offers the Licensed Material as-is and as-available, and makes
 * no representations or warranties of any kind concerning the Licensed Material, 
 * whether express, implied, statutory, or other. This includes, without limitation, 
 * warranties of title, merchantability, fitness for a particular purpose, 
 * non-infringement, absence of latent or other defects, accuracy, or the presence
 * or absence of errors, whether or not known or discoverable. Where disclaimers 
 * of warranties are not allowed in full or in part, this disclaimer may not apply to You.
 * 
 * Please read the Full License text at the following link:
 * https://creativecommons.org/licenses/by-nc-sa/4.0/legalcode
 *  
 * LIBRARIES TO INSTALL:
 * - U8G2 by Olikraus
 * - Huskylens
 * - TimerOne by Jesse Tane, Jérôme Despatis, Michael Polli, Dan Clemens, Paul Stoffregen
 * - ServoTimer2 : This one requires manual installation (copy the folder in Documents\Arduino\Libraries) => https://github.com/nabontra/ServoTimer2
  */

#include "HUSKYLENS.h" // install manually: https://github.com/HuskyLens/HUSKYLENSArduino/tree/master
#include <U8x8lib.h>   // https://github.com/olikraus/u8g2
#include <TimerOne.h>
#include <ServoTimer2.h>
#include <EEPROM.h>

U8X8_SSD1306_128X32_UNIVISION_HW_I2C u8x8(U8X8_PIN_NONE);
HUSKYLENS huskylens; //HUSKYLENS Green => SDA; Blue => SCL

// ****************** LIPO BATTERY STUFF
// #define LIPO // uncomment if you're using the LiPo battery
#define LIPO_PIN    A2  // analog pin where the 18650 is attached for checking voltage
#define BAT_AVG     32  // averages on battery readings
#define BAT_DIV     .005180840664F // .00488758553274F

// ****************** GPIO DEFINITIONS
#define MotorRPin   9   // signal for right servomotor
#define MotorLPin   10  // signal for left servomotor
#define P1          2   // pushbutton P1 on ARLOK PCB ('button' on MakerUNO board)
#define P2          5   // pushbutton P2
#define trigPin     4   // HC-SR04 - trigger
#define echoPin     3   // HC-SR04 - echo
#define buzzer      8   // buzzer on MakerUNO
#define linemodule  A1  // line follower module

// ****************** SERVO STUFF
ServoTimer2 MotorL;               // left servomotor object
ServoTimer2 MotorR;               // right servomotor object
uint16_t servoL_center = 1500;    // default value for left servomotor center point
uint16_t servoR_center = 1500;    // default value for right servomotor center point
uint16_t servoL_balanced;         // left servomotor balanced center point
uint16_t servoR_balanced;         // right servomotor balanced center point
int16_t servo_balance = 0;        // default value for servomotors balancing of the center point
uint8_t servoL_eeprom = 0;        // eeprom memory location for storing point zero of left servomotor
uint8_t servoR_eeprom = 2;        // eeprom memory location for storing point zero of right servomotor
uint8_t servo_balance_eeprom = 4; // eeprom memory location for storing the balacing of servomotors

// CHECK/CHANGE THOSE VALUES IF YOU'VE PROBLEMS with Robot movements!
#define SPEED       50           // normal speed for forward moving (center point+speed microseconds), rise this if your robot doesn't move
#define ACCEL_STEP   1           // increment ramp
#define SPEED_SLOW  20           // speed used for maneuvers, raise this if your robot cannot turn
#define TURN_TIME   5           // amount of time used for turning, change this if turning angle is not 90 degrees
#define BACK_TIME   50           // amount of time used for going backward after robot found an obstacle

#define OBJECT_WIDTH 90        // object width for not move forward or backward
#define OBJECT_WIDTH_TOLERANCE 20

int currentSpeed = 0;              // actual speed, variable used for creating an acceleration ramp

// enum used for ARLOK working mode
enum arlok_mode 
 {
 configuration,
 normal
 };
arlok_mode mode=normal;  // actual mode

// enum used for config menu pages on display
enum config_pages 
 {
 left_motor = 0,
 right_motor = 1,
 balance = 2,
 config_end = 3
 };

void printResult(HUSKYLENSResult result);

void setup() 
  {
  // sonar setup
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  // pushbuttons setup
  pinMode(P1, INPUT_PULLUP);
  pinMode(P2, INPUT_PULLUP);
  // buzzer setup
  #ifdef buzzer
   pinMode(buzzer, OUTPUT);
   digitalWrite(buzzer, LOW);
  #endif

  // display init
  u8x8.setI2CAddress(0x78);
  u8x8.begin();
  u8x8.setPowerSave(0);
  u8x8.setFlipMode(0);
  u8x8.setFont(u8x8_font_chroma48medium8_r);
  u8x8.drawString(0,0,"HUSKYLENS ARLOK");
    
  // center values used for servomotors, loaded from eeprom
  // if in the eeprom are saved values out of the range 500-2500, 1500 will be used
  // (this happens when eeprom memory was never used since contains 0xFFFF value)
  uint16_t LV = EEPROM.read(servoL_eeprom) << 8;
  LV |= EEPROM.read(servoL_eeprom + 1);
  uint16_t RV = EEPROM.read(servoR_eeprom) << 8;
  RV |= EEPROM.read(servoR_eeprom + 1);
  if (LV < 2501 && LV > 499) servoL_center = LV;
  if (RV < 2501 && RV > 499) servoR_center = RV;
  // balance value used for fine tuning of differences in speed of the servomotors
  // the range is based on the value set in the SPEED constant
  int16_t BL = EEPROM.read(servo_balance_eeprom) << 8;
  BL |= EEPROM.read(servo_balance_eeprom + 1);
  if (BL > -SPEED && BL < SPEED) servo_balance = BL;
  balance_servos();
  MotorL.attach(MotorLPin);
  MotorR.attach(MotorRPin);
  move_stop(1);

  // if P1 is pressed during the setup function, I'll start the setup mode
  if (digitalRead(P1) == 0) 
   {
   mode = configuration;
   while (digitalRead(P1) == 0) {continue;}
   }
  
  Serial.begin(115200);
  Wire.begin();
  delay(500);
  while (!huskylens.begin(Wire))
    {
    delay(500);
    // maybe protocol not set on I2C
    u8x8.drawString(0,1,"Check Protocol");
    delay(100);
    }
 
 // Set custom names for learned objects
 huskylens.setCustomName("HAROLD\0" , 1);
 huskylens.setCustomName("MR.BEAN\0", 2);
 }

void loop() 
  {
  volatile int x,y,w,h; // position and dimensions of detected object
  char buf[4]; // buffer used for the display
  static bool juststarted=true;

  #ifdef LIPO
   // read battery
   static uint8_t bat_count=0;
   static float bat_val=0;
   static float bat_now=0;
   bat_val+=analogRead(LIPO_PIN);
   bat_count++;
   if (bat_count==BAT_AVG) // print battery value
     {
     bat_val/=BAT_AVG;
     bat_now=bat_val*BAT_DIV;
     bat_val=0;
     bat_count=0;
     dtostrf(bat_now, 4, 2, buf);
     u8x8.drawString(0,3,"Battery:");
     u8x8.drawString(8,3,buf);
     u8x8.drawString(12,3,"V");
     }
  #endif 
  
  if (!huskylens.request()) {} 
  else if(!huskylens.isLearned()) {}
  else if(!huskylens.available())
    {
    // not detected
    u8x8.drawString(0,1,"I can't see     ");
    u8x8.drawString(0,2,"anything...     ");
    move_stop(1);
    }
  else // Huskylens detected a block
    {
    while (huskylens.available())
        {
        HUSKYLENSResult result = huskylens.read();
        //printResult(result);
        if (result.command == COMMAND_RETURN_BLOCK) // block detected
          {
          u8x8.drawString(0,2,"X:");
          u8x8.drawString(6,2,"W:");
          sprintf(buf,"%03i ",result.xCenter);
          u8x8.drawString(2,2,buf);
          sprintf(buf,"%03i ",result.width);
          u8x8.drawString(8,2,buf);
 
          // ID1 is the Hide The Pain Harold face => follow him
          if (result.ID==1) 
            {
            u8x8.drawString(0,1,"HIDE THE PAIN! ");
            // 0-320
            if (result.xCenter<110) // object is on the left
             {
             currentSpeed=0;
             move_left(10);
             }
            else if (result.xCenter>210) // object is on the right
             {
             currentSpeed=0;
             move_right(10);
             }
            else // object is at center
             {
             if (result.width<OBJECT_WIDTH) // object is far away, move forward
               {
               // ramp
               if (currentSpeed < SPEED)
                  {
                  currentSpeed+=ACCEL_STEP;
                  if (currentSpeed > SPEED) currentSpeed = SPEED;
                  }
                move_forward(currentSpeed);
               }
             else if (result.width>OBJECT_WIDTH+OBJECT_WIDTH_TOLERANCE) // object is near, move backward
               {
               currentSpeed=0;
               move_backward(30); 
               }
             else
               {
               move_stop(1);
               }
             }
			      // END ID1 detected
            }

          // ID2 is Mr. Bean
          else if (result.ID==2) 
            {
            u8x8.drawString(0,1,"MR. BEAN       ");
            move_stop(1);
            }

          else // other IDs...
            {
            u8x8.drawString(0,1,"Who is this?  ");
            move_stop(1);   
            }
          } // block detected
        } // while huskylens available
     } // available
  } // loop

void printResult(HUSKYLENSResult result){
    if (result.command == COMMAND_RETURN_BLOCK){
        Serial.println(String()+F("Block:xCenter=")+result.xCenter+F(",yCenter=")+result.yCenter+F(",width=")+result.width+F(",height=")+result.height+F(",ID=")+result.ID);
    }
    else if (result.command == COMMAND_RETURN_ARROW){
        Serial.println(String()+F("Arrow:xOrigin=")+result.xOrigin+F(",yOrigin=")+result.yOrigin+F(",xTarget=")+result.xTarget+F(",yTarget=")+result.yTarget+F(",ID=")+result.ID);
    }
    else{
        Serial.println("Object unknown!");
    }
}

void balance_servos(void) 
 {
 if (servo_balance < 0) 
    {
    servoL_balanced = servoL_center;
    servoR_balanced = servoR_center + abs(servo_balance);
    } 
 else if (servo_balance > 0) 
    {
    servoL_balanced = servoL_center - servo_balance;
    servoR_balanced = servoR_center;
    } 
 else 
   {
   servoL_balanced = servoL_center;
   servoR_balanced = servoR_center;
   }
 } // \balance_servos()

// moves forward at 'sp' speed
void move_forward(uint16_t sp) 
 {
 MotorL.attach(MotorLPin);
 MotorR.attach(MotorRPin);
 if (sp > SPEED) sp = SPEED;
 MotorL.write(servoL_balanced + sp);
 MotorR.write(servoR_balanced - sp);
 return;
 } // \move_forward()

// moves backward at slow speed for ms milliseconds
void move_backward(long ms) 
 {
 MotorL.attach(MotorLPin);
 MotorR.attach(MotorRPin);
 long timenow = millis();
 while ((millis() - timenow) < ms) 
    {
    MotorL.write(servoL_center - SPEED_SLOW);
    MotorR.write(servoL_center + SPEED_SLOW);
    }
 return;
 } // \move_backward()

// turns right at slow speed for ms milliseconds
void move_right(long ms) 
 {
 MotorL.attach(MotorLPin);
 MotorR.attach(MotorRPin);
 long timenow = millis();
 while ((millis() - timenow) < ms) 
    {
    MotorL.write(servoL_center + SPEED_SLOW);
    MotorR.write(servoL_center + SPEED_SLOW);
    }
 return;
 } // \move_right()

// turns left at slow speed for ms milliseconds
void move_left(long ms) 
 {
  // servomotors setup
 MotorL.attach(MotorLPin);
 MotorR.attach(MotorRPin);
 long timenow = millis();
 while ((millis() - timenow) < ms) 
    {
    MotorL.write(servoL_center - SPEED_SLOW);
    MotorR.write(servoL_center - SPEED_SLOW);
    }
 return;
 } // \move_left()

// Servomotors stopped
void move_stop(long ms) 
 {
 if (ms>0) // ms value >0, don't detach servo
  {
  MotorL.attach(MotorLPin);
  MotorR.attach(MotorRPin);
  long timenow = millis();
  while ((millis() - timenow) < ms) 
   {
   MotorL.write(servoL_center);
   MotorR.write(servoR_center);
   }
  }
 else // detach servo (real stop, no signals to servos)
  {
  MotorL.detach();
  MotorR.detach();
  digitalWrite(MotorLPin, 0);
  digitalWrite(MotorRPin, 0);
  }
 return;
 } // \move_stop()
