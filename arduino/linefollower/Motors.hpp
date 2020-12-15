/*
 * Name          : Motors.hpp
 * @author       : Roberto D'Amico (@bobboteck)
 * Last modified : 03.08.2020
 * Revision      : 1.1.0
 *
 * Modification History:
 * Date         Version     Modified By		Description
 * 2020-08-03	1.1.0		Roberto D'Amico	Add new method Stop
 * 2020-07-30   1.0.0       Roberto D'Amico Created Library
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
#ifndef Motors_H
#define Motors_H

#include <Arduino.h>
// Library for using servo on Timer 2 (https://github.com/nabontra/ServoTimer2)
#include <ServoTimer2.h>
// Library for Arduino internal eeprom memory
#include <EEPROM.h>

class Motors
{
	private:
		static const uint16_t _SpeedMax = 200;	// Normal speed for forward moving (center point+speed microseconds)
		static const uint16_t _SppedSlow = 50;	// Speed used for maneuvers

		ServoTimer2 _MotorL;            // Left servomotor object
		ServoTimer2 _MotorR;            // Right servomotor object

		uint8_t _MotorRPin;				// Pin for Right servomotor
		uint8_t _MotorLPin;				// Pin for Left servomotor
		uint16_t _servoL_center = 1500; // Default value for left servomotor center point
		uint16_t _servoR_center = 1500; // Default value for right servomotor center point
		uint8_t _servoL_eeprom = 0;     // Eeprom memory location for storing point zero of left servomotor
		uint8_t _servoR_eeprom = 2;     // Eeprom memory location for storing point zero of right servomotor


	public:
		/**
		 * Define the pin used to drive motors and read the "zero spped" from the Arduino EEPROM
		 * 
		 * @param pinMotorRight The pin connected to the Right Motor
		 * @param pinMotorLeft The pin connected to the Left Motor
		 */
		Motors(uint8_t pinMotorRight, uint8_t pinMotorLeft);
		~Motors();

		enum Motor { left, right };

		/**
		 * Attach the Servo Motors to the correspondend Arduino PIN
		 */
		void EnableMotors();

		/**
		 * Move the Robot forward at speed indicated
		 * 
		 * @param speed The speed of motors
		 */
		void Forward(uint16_t speed);

		void Forward(uint16_t speedLeft, uint16_t speedRight);

		/**
		 * Move the Robot backwards for a ms milliseconds
		 * 
		 * @param ms The number of milliseconds
		 */
		void Backwards(long ms);

		/**
		 * Turns the Robot right at slow speed for ms milliseconds
		 * 
		 * @param ms The number of milliseconds
		 */
		void Right(long ms);

		/**
		 * Turns the Robot left at slow speed for ms milliseconds
		 * 
		 * @param ms The number of milliseconds
		 */
		void Left(long ms);

		/**
		 * Stop the Robot for ms milliseconds
		 * 
		 * @param ms The number of milliseconds
		 */
		void Stop(long ms);

		/**
		 * Stop the Robot
		 */
		void Stop();

		/**
		 * Set the pulse width in microseconds for a specific Motor
		 * 
		 * @param motor The motor for which the pulse size must be set in ServoTimer2
		 * @param pulseWidth The width of pulse
		 */
		void Write(Motor motor, int pulseWidth);

		/**
		 * Store the pulse width in microseconds, into the EEPROM, of a specific Motor for the Zero speed
		 * 
		 * @param motor The motor for which the pulse size must be set in ServoTimer2
		 * @param pulseWidth The width of pulse
		 */
		void SetZeroSpeed(Motor motor, uint16_t value);
};

#endif