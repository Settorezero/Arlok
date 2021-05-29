/*
 * ARLOK
 * Educational Robot based on MakerUNO
 * (c)2020 Giovanni Bernardo (https://www.settorezero.com)
 * 
 * EXPLORER DEMO
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
 * CREDITS
 * 
 * Steve Garrat
 * For the idea about using HC-SR04 sonar on interrupts:
 * (https://homediyelectronics.com/projects/arduino/arduinoprogramminghcsr04withinterrupts/)
 * 
 * Nick Bontranger
 * For the library allows using servo on Timer 2
 * https://github.com/nabontra/ServoTimer2
 * 
 * Adafruit
 * Because makes a lot of useful libraries
 * 
 * LIBRARIES TO BE INSTALLED
 * 
 * - Adafruit SSD1306 by Adafruit
 * - Adafruit GFX by Adafruit
 * - TimerOne by Jesse Tane, Jérôme Despatis, Michael Polli, Dan Clemens, Paul Stoffregen
 * 
 * This one requires manual installation (copy the folder in Documents\Arduino\Libraries)
 * https://github.com/nabontra/ServoTimer2
 * 
 */

// Libraries for OLED display
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
// Library for Timer1 Interrupts
#include <TimerOne.h>
// Library for using servo on Timer 2
#include <ServoTimer2.h>
// Library for Arduino internal eeprom memory
#include <EEPROM.h>

#define ARLOK  // comment this if you're using the old AR.L.O. pcb

#ifdef ARLOK
 // ARLOK PCB defines
 #define MotorRPin 9   // signal for right servomotor
 #define MotorLPin 10  // signal for left servomotor
 #define P1 2          // pushbutton P1 on ARLOK PCB, 'button' on MakerUNO board
 #define P2 5          // pushbutton P2
 #define trigPin 4     // HC-SR04 - trigger
 #define echoPin 3     // HC-SR04 - echo
 #define buzzer 8      // buzzer on MakerUNO (you can de-activate it using the switch)
#else
 // AR.L.O. PCB defines
 #define MotorRPin 9   // signal for right servomotor
 #define MotorLPin 10  // signal for left servomotor
 #define P1 6          // pushbutton P1 on AR.L.O.
 #define P2 7          // pushbutton P2
 #define trigPin 8     // HC-SR04 - trigger
 #define echoPin 2     // HC-SR04 - echo
 //#define buzzer      // no buzzer
#endif

// stuff used by servomotors
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
#define SPEED 600                 // normal speed for forward moving (center point+speed microseconds), rise this if your robot doesn't move
#define SPEED_SLOW 125            // speed used for maneuvers, raise this if your robot cannot turn
#define TURN_TIME 600             // amount of time used for turning, change this if turning angle is not 90 degrees
#define BACK_TIME 500             // amount of time used for going backward after robot found an obstacle

// stuff used by sonar
#define TIMER_US 50               // Timer1 interrupt every 50uS
#define TICK_COUNTS 4500          // 4500*50uS = 225mS, time space between two consecutive trigger pulses
#define OBSTACLE 16               // ARLOK will stop if an obstacle is nearer than 16cm

// stuff used by oled display
#define SCREEN_WIDTH  128
#define SCREEN_HEIGHT  32
#define OLED_RESET     -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Global variables
volatile long distance = 0;       // distance measured by sonar, cm

// enum used for ARLOK/ARLO working mode
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

void setup(void) 
 {
 // sonar setup
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 // servomotors setup
 MotorL.attach(MotorLPin);
 MotorR.attach(MotorRPin);
 // pushbuttons setup
 pinMode(P1, INPUT_PULLUP);
 pinMode(P2, INPUT_PULLUP);
 // buzzer setup
 #ifdef buzzer
  pinMode(buzzer, OUTPUT);
  digitalWrite(buzzer, LOW);
 #endif
 
 move_stop(100);
 
 // interrupts
 Timer1.initialize(TIMER_US); // Initialise timer 1
 Timer1.attachInterrupt(timer1_ISR); // Attach interrupt to the timer service routine
 attachInterrupt(digitalPinToInterrupt(echoPin), sonarEcho_ISR, CHANGE); // Attach interrupt to the sensor echo input

 delay(500);
 Serial.begin(9600);  // the HC-05 in normal mode (no AT) works at 9600baud (38400 if in AT)
 randomSeed(analogRead(3));  // start-up random number generator using an unused analog input

 // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
 if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) 
  {  // Address 0x3C for 128x32
  Serial.println(F("SSD1306 allocation failed"));
  while (1);  // Don't proceed, loop forever
  }
 display.clearDisplay();
 display.setTextSize(2);
 display.setTextColor(SSD1306_WHITE, SSD1306_BLACK);

 Serial.println("ARLO(K) Startup");

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
 move_stop(100);

 // if P1 is pressed during the setup function, I'll start the setup mode
  if (digitalRead(P1) == 0) 
   {
   mode = configuration;
   Serial.println("Setup mode");
   while (digitalRead(P1) == 0) {continue;}
   }
 } // \setup()

void loop() 
 {
 static boolean juststarted=true;
 while (mode==configuration) config_menu();

 display.setTextSize(2);
 display.setCursor(0, 0);

 if (juststarted) 
    {
    move_stop(100);
    display.println("WAIT");
    display.display();
    move_stop(1000); // servomotors stopped giving time to sonar to get stable
    juststarted = false;
    }
 display.println("EXPLORER");
 if (distance > 3000) 
    {
    display.print("go ahead!");
    } 
 else 
    {
    display.print(distance);
    display.print("cm       ");
    }
 display.display();

 // distance is greater than obstacle
 if (distance > OBSTACLE)
    {
    move_forward(SPEED);
    } 
 else 
    {
	  // this function will generate a random number: 0 or 1
    // syntax: min(inclusive), max(exclusive)	
    uint8_t randomNum=random(0, 2); 
    // deceleration
    move_forward(SPEED - 50);
    delay(40);
    move_forward(SPEED - 100);
    sound(); // about 120ms delay
    //delay(80);
    move_forward(SPEED - 150);
    delay(80);
    // stop
    Serial.println("stop");
    move_stop(100);
    move_backward(BACK_TIME);
    move_stop(100);

    if (randomNum) 
	    {
      move_right(TURN_TIME);
      } 
	  else 
	    {
      move_left(TURN_TIME);
      }
    move_stop(100);
    }
 } // \loop

void config_menu(void) 
 {
 static config_pages actual_page=left_motor;
 static bool splash = true;

 if (splash) 
    {
    display.setCursor(0, 0);
    display.println("SETUP");
    display.display();
    delay(2000);
    display.clearDisplay();
    display.setCursor(0, 0);
    display.display();
    splash = false;
    delay(1000);
    }

 uint16_t val = analogRead(0);
 // mapping 0-1023 to 500-2500
 uint16_t pos = map(val, 0, 1023, 500, 2500);
 // mapping 0-1023 to SPEED, -SPEED
 int16_t balance_pos = map(val, 0, 1023, SPEED, -SPEED);
 String pre_balance_txt = balance_pos > 0 ? "   " : "L< ";
 String post_balance_txt = balance_pos < 0 ? "   " : " >R";

 switch (actual_page) 
    {
    case left_motor:  // left servomotor setup
      display.setCursor(0, 0);
      display.setTextSize(1);
      display.print("LEFT MOTOR (");
      display.print(servoL_center);
      display.println(")");
      display.setTextSize(2);
      display.print(pos);
      display.print("  ");
      display.println();
      display.setTextSize(1);
      display.print("P1: save P2: next");
      display.display();
      MotorL.write(pos);
      break;

    case right_motor:  // right servomotor setup
      display.setCursor(0, 0);
      display.setTextSize(1);
      display.print("RIGHT MOTOR (");
      display.print(servoR_center);
      display.println(")");
      display.setTextSize(2);
      display.print(pos);
      display.print("  ");
      display.println();
      display.setTextSize(1);
      display.print("P1: save P2: next");
      display.display();
      MotorR.write(pos);
      break;

    case balance:  // balancing setup
      display.clearDisplay();
      display.setCursor(0, 0);
      display.setTextSize(1);
      display.print("SERVOS BALANCE (");
      display.print(servo_balance);
      display.println(")");
      display.setTextSize(2);
      display.print(pre_balance_txt);
      display.print(balance_pos);
      display.println(post_balance_txt);
      display.setTextSize(1);
      display.print("P1: save P2: next");
      display.display();
      MotorL.write(servoL_center);
      MotorR.write(servoR_center);
      break;

    case config_end:
      display.setTextSize(2);
      display.setCursor(0, 0);
      display.println("P1: Exit");
      display.println("P2: Return to Setup");
      display.display();
      break;
    }  // switch

 // P1 pressed: confirm value or exit from menu
 if (digitalRead(P1) == 0) 
    {
    delay(50);
    if (digitalRead(P1)==0) 
	      {
        while (digitalRead(P1) == 0) {continue;}
        switch (actual_page)
		        {
            case left_motor:
              servoL_center = pos;
              // I must split the 16bit value in two bytes
              // and save values in 2 different EEPROM locations
              EEPROM.update(servoL_eeprom, (uint8_t)(pos >> 8));
              delay(4);  // an eeprom.write takes 3.3mS
              EEPROM.update(servoL_eeprom + 1, (uint8_t)(pos & 0x00FF));
              delay(4);
              Serial.print("Left zero: ");
              Serial.println(pos);
              break;

            case right_motor:
              servoR_center = pos;
              // I must split the 16bit value in two bytes
              // and save values in 2 different EEPROM locations
              EEPROM.update(servoR_eeprom, (uint8_t)(pos >> 8));
              delay(4);  // an eeprom.write takes 3.3mS
              EEPROM.update(servoR_eeprom + 1, (uint8_t)(pos & 0x00FF));
              delay(4);
              Serial.print("Right zero: ");
              Serial.println(pos);
              break;

            case balance:
              servo_balance = balance_pos;
              EEPROM.update(servo_balance_eeprom, (balance_pos >> 8));
              delay(4);  // an eeprom.write takes 3.3mS
              EEPROM.update(servo_balance_eeprom + 1, (balance_pos & 0x00FF));
              delay(4);  // an eeprom.write takes 3.3mS
              Serial.print("Balance pos: ");
              Serial.println(balance_pos);
              balance_servos();
              break;

            case config_end:
              // exit from menu
              mode = normal;
              display.clearDisplay();
              display.display();
              Serial.println("Config exit");
              return;
            break;
            } // \switch actual_page
        } // \P1 pressed for sure
    } // \P1 pressed

 // P2 pressed: change the page
 if (digitalRead(P2) == 0) 
    {
    delay(50);
    if (digitalRead(P2) == 0) 
	    {
        while (digitalRead(P2) == 0) {continue;}
        // the C++ deals with enums as an independent type
        // so we must convert it in an integer if we want to use the ++ operator
        uint8_t tmp = (uint8_t)actual_page;
        tmp++;
        if (tmp > (uint8_t)config_end) tmp = 0;
        actual_page = (config_pages)tmp;
        display.clearDisplay();
        display.display();
        delay(10);
        } // \P2 pressed for sure
    } // \P2 pressed
 } // \config_menu()

void sound(void) 
 {
 uint8_t i = 30;
 while (i--) 
    {
    #ifdef buzzer
     digitalWrite(buzzer, HIGH);  // turn on the buzzer
     delayMicroseconds(2000);
     digitalWrite(buzzer, LOW);  // turn off the buzzer
     delayMicroseconds(2000);
    #endif
    }
 } // \sound()

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

  Serial.print("ServoL_balanced:");
  Serial.println(servoL_balanced);
  Serial.print("ServoR_balanced:");
  Serial.println(servoR_balanced);
 } // \balance_servos()

// moves forward at 'sp' speed
void move_forward(uint16_t sp) 
 {
 if (sp > SPEED) sp = SPEED;
 MotorL.write(servoL_balanced + sp);
 MotorR.write(servoR_balanced - sp);
 return;
 } // \move_forward()

// moves backward at slow speed for ms milliseconds
void move_backward(long ms) 
 {
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
 long timenow = millis();
 while ((millis() - timenow) < ms) 
   {
   MotorL.write(servoL_center);
   MotorR.write(servoR_center);
   }
 return;
 } // \move_stop()

// Timer1 every 50uS : sends the pulse signal
void timer1_ISR() 
 {
 static volatile int state = 0; // actual state of pulse signal
 static volatile int trigger_time_count = 0; // countdown used to re-triggering

 if (!(--trigger_time_count)) // counting up to 225mS (defined by TICK_COUNTS)
    {
    trigger_time_count = TICK_COUNTS; // reload the counter
    state = 1; // we're ready to retrigger
    }

 switch (state) 
    {
    case 0: // does nothing: I'll wait the 225ms
      break;

    case 1: // send the pulse signal
      digitalWrite(trigPin, HIGH); // trigger pin at high level
      state = 2; // go to the next step, see you in 50uS
      break;

    case 2:  // stop the pulse signal
    default:
      digitalWrite(trigPin, LOW);  // trigger pin at low level
      state = 0;                   // do nothing, see you in 225mS
      break;
    } // \switch state
 } // \timer1_isr()

// interrupt on state change of echo pin
void sonarEcho_ISR() 
 {
 static long echo_start = 0; // time at which echo high pulse is arrived
 static long echo_end = 0; // time at which echo low pulse is arrived
 long echo_duration = 0; // echo lasting in microseconds
 switch (digitalRead(echoPin)) // check echo pin if is high or low
    {
    case HIGH: // echo just started
      echo_end = 0;
      echo_start = micros(); // save start time
      break;

    case LOW: // echo finished
      echo_end = micros(); // save end time
      if (echo_end > echo_start) // I check that there is no micros() overflow
        {
        echo_duration = echo_end - echo_start; // echo lasting, in microseconds
        distance = echo_duration / 58; // distance in cm, global variable
        }
    break;
    } // \switch echo pin
 } // \sonar echo isr

/******************************************************************************************************************
* END Of the file
* 
* if you reached this part, you're a smart person and I want you as follower of my social networks:
* 
* Facebook: https://www.facebook.com/settorezero (Italian language)
* Twitter: https://www.twitter.com/settorezero (English language)
* Instagram - my private profile: https://www.instagram.com/cyb3rn0id (english language)
* Instagram - profile of my blog: https://www.instagram.com/settorezero (italian language)
* Youtube: https://www.youtube.com/settorezero (mainly italian language, but sometimes also English language)
* 
* PLEASE SUBSCRIBE
******************************************************************************************************************/
