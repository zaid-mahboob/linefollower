/* https://github.com/zaid-mahboob/linefollower  
 
 For more line following codes visit https://github.com/zaid-mahboob/linefollower 
 */


//Make sure to install the library
#include <QTRSensors.h>
QTRSensors qtr;
const uint8_t SensorCount = 8;
uint16_t sensorValues[SensorCount];

float Kp = 01; //set up the constants value
float Ki = 0.01;
float Kd = 0.5;
int P;
int I;
int D;

int lastError = 0;
boolean onoff = false;

//Increasing the maxspeed can damage the motors - at a value of 255 the 6V motors will receive 7,4 V 
const uint8_t rightmaxspeed = 150;
const uint8_t leftmaxspeed = 150;
const uint8_t rightbasespeed = 100;
const uint8_t leftbasespeed = 100;

//Set up the drive motor carrier pins
int rightmotor1 = A1;
int rightmotor2 = A2;
int leftmotor1 = A4;
int leftmotor2 = A5;
int rightpwm  = 10;
int leftpwm = 11;

//Set up the buttons pins
int buttoncalibrate = 17; //pin A3

int buttonstart = 2;

void setup() {
  Serial.begin(9600);
  qtr.setTypeRC();
  //Set up the sensor array pins
  qtr.setSensorPins((const uint8_t[]){2, 3, 4, 5, 6, 7, 8, 9}, SensorCount);
  qtr.setEmitterPin(12);//LEDON PIN

  pinMode(rightmotor1, OUTPUT);
  pinMode(rightmotor2, OUTPUT);
  pinMode(leftmotor1, OUTPUT);
  pinMode(leftmotor2, OUTPUT);
  pinMode(rightpwm, OUTPUT);
  pinMode(leftpwm, OUTPUT);

  delay(500);
  

  boolean Ok = false;
  calibration();
  
  forward_brake(0, 0);
}

void calibration() {
  digitalWrite(LED_BUILTIN, HIGH);
  for (uint16_t i = 0; i < 400; i++)
  {
    qtr.calibrate();
  }
  
}

void loop() {

    PID_control();
 
}
void forward_brake(int posa, int posb) {
  //set the appropriate values for aphase and bphase so that the robot goes straight
  digitalWrite(rightmotor1, HIGH);
  digitalWrite(rightmotor2, LOW);
  digitalWrite(leftmotor1, HIGH);
  digitalWrite(leftmotor2, LOW);
  analogWrite(rightpwm, posa);
  analogWrite(leftpwm, posb);
}
void PID_control() {
  uint16_t position = qtr.readLineBlack(sensorValues);
  int error = 3500 - position;
Serial.print(position);Serial.print("     "); 
  P = error;
  I = I + error;
  D = error - lastError;
  lastError = error;
  int motorspeed = P*Kp + I*Ki + D*Kd;
  
  int motorspeedright = rightbasespeed + motorspeed;
  int motorspeedleft = leftbasespeed - motorspeed;
  
  if (motorspeedright > rightmaxspeed) {
    motorspeedright = rightmaxspeed;
  }
  if (motorspeedleft > leftmaxspeed) {
    motorspeedleft = leftmaxspeed;
  }
  if (motorspeedright < 0) {
    motorspeedright = 0;
  }
  if (motorspeedleft < 0) {
    motorspeedleft = 0;
  } 
  //Serial.print(motorspeedright);Serial.print(" ");Serial.println(motorspeedleft);
  forward_brake(motorspeedright, motorspeedleft);
}
