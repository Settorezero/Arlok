/*
 * Name          : linefollower.ino
 * @author       : Roberto D'Amico (@bobboteck)
 * Last modified : 11.12.2020
 * Revision      : 1.0.0
 *
 * Modification History:
 * Date         Version     Modified By		Description
 * 2020-12-11	1.0.0		Roberto D'Amico	Use ARLOK as Line Follower Robot, see readme file for detail
 * 
 * MIT License
 * 
 * Copyright (c) 2020 Roberto D'Amico (@bobboteck)
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * This file is part of the ARLOK Project (https://github.com/settorezero/arlok).
 *
 * CREDITS
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
// Library local for control the Motors
#include "Motors.hpp"

// Arduino used pins
#define MotorRPin   9   // signal for right servomotor
#define MotorLPin   10  // signal for left servomotor
//#define P1          2   // pushbutton P1 on ARLOK PCB, 'button' on MakerUNO board
//#define P2          5   // pushbutton P2
//#define trigPin     4   // HC-SR04 - trigger
//#define echoPin     3   // HC-SR04 - echo
//#define buzzer      8   // buzzer on MakerUNO (you can de-activate it using the switch)	

#define SPEED_MAX   200 // normal speed for forward moving (center point+speed microseconds)
#define SPEED_SLOW  50  // speed used for maneuvers

// stuff used by oled display
#define SCREEN_WIDTH    128
#define SCREEN_HEIGHT   32
#define OLED_RESET      -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

Motors ArloMotors(MotorRPin, MotorLPin);

static const int sensorPin = A2;	// select the input pin for the potentiometer
static const int lineCenter = 500;	// Sensor value for line positioned at center
static const int deltaCenter = 100;

void setup()
{
    ArloMotors.EnableMotors();
    ArloMotors.Stop();

    Serial.begin(9600);

    // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
    if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) 
    { // Address 0x3C for 128x32
        Serial.println(F("SSD1306 allocation failed"));
        while(1); // Don't proceed, loop forever
    }
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE,SSD1306_BLACK);

    display.println("ARLOK");
    display.println("LineFollower");
    delay(1000);
}

void loop()
{
    display.clearDisplay();
    display.setTextSize(2);
    display.setCursor(0,0);
    display.print("Line ");

    // read the value from the Line sensor
    int linePosition = analogRead(sensorPin);
    Serial.print(linePosition); 
    display.println(linePosition);

    if(linePosition > 950)  // when all sensors "see" the line
    {
        display.print("----------");
        //Motors.Stop();
    }
    else if(linePosition < 50)  // when all sensors NOT "see" the line
    {
        display.print("??????????");
        ArloMotors.Forward(SPEED_MAX/6);
    }
    else    // one or more sensors "see" the line
    {
        // calculate offset from the center of sensor
        int centerOffSet = linePosition - lineCenter;
        // if centerOffSet is into the center death zone go forward
        if(abs(centerOffSet) <= deltaCenter)
        {
            display.print("    ||    ");
            ArloMotors.Forward(SPEED_MAX/6);
        }
        else
        {
            int motorLeftSpeed = SPEED_MAX;
            int motorRightSpeed = SPEED_MAX;

            if(centerOffSet < 0)
            {
                display.print("  > ..    ");
                motorLeftSpeed = abs((abs(centerOffSet) - 100) - 200);
            }
            else
            {
                display.print("    .. <  ");
                motorRightSpeed = abs((centerOffSet - 100) - 200);
            }

            Serial.print(" ");
            Serial.print(motorLeftSpeed); 
            Serial.print(" ");
            Serial.print(motorRightSpeed);
            ArloMotors.Forward(motorLeftSpeed / 6, motorRightSpeed / 6);
        }
    }

    display.display();
    Serial.println();
}
