
#include <Arduino_RouterBridge.h>
#include <Arduino_HardwareServo.h>
#include <U8x8lib.h>   // https://github.com/olikraus/u8g2
#include <Wire.h>

// Servo Pin
#define SERVO_L 10
#define SERVO_R  9
// Lights pin
#define LED_PIN 7
// Center value for servo and deadzone (center±deadzone)
#define CENTER_L 89
#define CENTER_R 89
#define DEADZONE  4

HardwareServo servoL;
HardwareServo servoR;
U8X8_SSD1306_128X32_UNIVISION_HW_I2C u8x8(U8X8_PIN_NONE);

int last_command=0;
int currentLV=CENTER_L;
int currentRV=CENTER_R;
int heartbeatcounter=0;
int lastheartbeat=0;
bool htu_online=true;
bool failsafe_active = false;

// HTU21D read, no-hold master. cmd: 0xF3 = temperature, 0xF5 = humidity
float htu_read(uint8_t cmd)
  {
  Wire.beginTransmission(0x40);
  Wire.write(cmd);
  if (Wire.endTransmission() != 0) return NAN;
  delay(55);
  if (Wire.requestFrom((uint8_t)0x40, (uint8_t)3) != 3) return NAN;
  uint16_t raw = Wire.read() << 8;
  raw |= Wire.read();
  Wire.read(); // CRC ignored
  raw &= 0xFFFC;
  if (cmd == 0xF3) return -46.85 + 175.72 * raw / 65536.0;
  return -6.0 + 125.0 * raw / 65536.0;
  }

// move servos
void drive_motors(int left_val, int right_val) 
    {
    #define RAMP_UP   1
    #define RAMP_DOWN 1
      
    // deadzone for central position = stop motors
    if ((left_val > (CENTER_L-DEADZONE)) && (left_val < (CENTER_L+DEADZONE))) left_val=CENTER_L;
    if ((right_val > (CENTER_R-DEADZONE)) && (right_val < (CENTER_R+DEADZONE))) right_val=CENTER_R;
      
    // stop
    if (left_val == CENTER_L && right_val == CENTER_R) 
       {
        currentLV = CENTER_L;
        currentRV = CENTER_R;
       }
    else
      {
      // ramp left
      if (left_val > currentLV)
         {
         currentLV+=RAMP_UP;
         if (currentLV > left_val) currentLV = left_val;
         }
      else
        {
        currentLV-=RAMP_DOWN;
        if (currentLV < left_val) currentLV = left_val;
        }
    
      // ramp right
      if (right_val > currentRV)
         {
         currentRV+=RAMP_UP;
         if (currentRV > right_val) currentRV = right_val;
         }
      else
        {
        currentRV-=RAMP_DOWN;
        if (currentRV < right_val) currentRV = right_val;
        }
      }
    servoL.write(currentLV);
    servoR.write(currentRV);
    last_command=millis();
    }

// hearbeat from webserver
void heartbeat(int value)
  {
  heartbeatcounter = value;
  lastheartbeat = millis();
  failsafe_active = false; // heartbeat received: disable failsafe
  }

// stop motors, used when heartbeat stops
void stopMotors(void)
  {
  if (failsafe_active) return; // failsafe already active
  failsafe_active = true;
  currentLV = CENTER_L;
  currentRV = CENTER_R;
  servoL.write(CENTER_L);
  servoR.write(CENTER_R);
  u8x8.drawString(0,3,"FAILSAFE ACTIVE ");
  }

// set led
int setLed(int state) 
  {
  digitalWrite(LED_PIN, state);
  return digitalRead(LED_PIN);
  }

void setup() 
    {
    Monitor.begin();
    // Attach servos to Pin 10 (Left) and Pin 9 (Right)
    servoL.attach(SERVO_L);
    servoR.attach(SERVO_R);
    // Initialize in neutral position (stopped)
    servoL.write(CENTER_L);
    servoR.write(CENTER_R);
    // Lights
    pinMode(LED_PIN, OUTPUT);
    digitalWrite(LED_PIN, LOW);
    // Display init
    u8x8.setI2CAddress(0x78);
    u8x8.begin();
    u8x8.setPowerSave(0);
    u8x8.setFlipMode(0);
    u8x8.setFont(u8x8_font_chroma48medium8_r);
    u8x8.drawString(0,0,"ARLOQ");
    u8x8.drawString(0,1,"by CYB3RN0ID");
    // HTU21 init
    if (isnan(htu_read(0xF3)))
      {
      Monitor.println("HTU21 sensor Error");
      htu_online=false;
      }
    // Initialize communication Bridge
    Bridge.begin();
    // Provide functions to the Bridge for remote calls from python code
    Bridge.provide("drive", drive_motors);
    Bridge.provide("heartbeat", heartbeat);
    Bridge.provide("set_led", setLed);
    }

void loop() 
  {
  static int last_send=millis();
  static int last_display = millis(); // timer display motori
  static int lastheartbeatcounter=0;
  static float htu_te=-1;
  static float htu_rh=-1;

  int elapsed = millis();

  // Refresh motor values on display every 50ms
  if (millis() - last_display > 50)
    {
    char buf[4];
    sprintf(buf,"%03i ", currentLV);
    u8x8.drawString(0,3,"L:");
    u8x8.drawString(2,3,buf);
    sprintf(buf,"%03i ", currentRV);
    u8x8.drawString(6,3,"R:");
    u8x8.drawString(8,3,buf);
    u8x8.drawString(11,3,"    ");
    last_display = millis();
    }
    
  // send sensor values every 1 second
  if (millis()-last_send>1000)
    {
    if (htu_online)
      {
      // read HTU21
      htu_te = htu_read(0xF3);
      htu_rh = htu_read(0xF5);
      // Write values on serial monitor
      Monitor.print("Temperature: ");
      Monitor.println(htu_te);
      Monitor.print("Relative humidity: ");
      Monitor.println(htu_rh);
      // Write values on display
      char buf[6];
      sprintf(buf,"%.1f ",htu_te);
      u8x8.drawString(0,2,"T:");
      u8x8.drawString(2,2,buf);
      sprintf(buf,"%.1f ",htu_rh);
      u8x8.drawString(7,2,"H:");
      u8x8.drawString(9,2,buf);
      }
    // Asynchronously send data to Python without waiting for a reply
    Bridge.notify("data", elapsed, htu_te, htu_rh);
    // update time counter for next call
    last_send=millis();
    } 
    
  // check heartbeat (signal from javascript code)
  if (millis()-lastheartbeat>5000)
    {
    if (lastheartbeatcounter!=heartbeatcounter) { lastheartbeatcounter=heartbeatcounter; }
    // no signals: stop the robot
    else { stopMotors(); }
    }
   
  } // end loop