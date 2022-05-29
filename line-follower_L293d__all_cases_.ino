/* https://github.com/zaid-mahboob/linefollower 
 In this code I have implemented all the possible sensor combination possibilites for black line. I have made
 multiple if else cases. After every case I have written its sensor combination such as 0110, 1001, etc. Here 1st digit
 represents left most sensor and 4th digit represent the right most sensor. Here 1 means that the sensor is 
 on black line and 0 means that the sensor is on white line.
 For more line following codes visit https://github.com/zaid-mahboob/linefollower 
 */

 
#include <AFMotor.h> 



AF_DCMotor motor1(1, MOTOR12_1KHZ);
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);

int left = A0;
int right =  A1;
int left_left = A2;
int right_right = A3;

int leftsensor = 0;
int leftleftsensor = 0;
int rightsensor = 0;
int rightrightsensor = 0;

int threshold = 500;

void setup() 
{
  motor1.setSpeed(70);
  motor2.setSpeed(70);
  motor3.setSpeed(70);
  motor4.setSpeed(70);
  Serial.begin(9600);
}


void loop() 
{

  leftsensor = analogRead(left);
  leftleftsensor = analogRead(left_left);
  rightsensor = analogRead(right);
  rightrightsensor = analogRead(right_right);
  Serial.println(leftsensor);
  
  // ALL MOVING FORWARD CONDITIONS
  
  if (leftleftsensor<threshold && leftsensor<threshold && rightsensor<threshold && rightrightsensor<threshold)
    {
    motor1.run(FORWARD);
    motor1.setSpeed(70);
    motor2.run(FORWARD);
        motor2.setSpeed(70);
    motor3.run(FORWARD);
    motor3.setSpeed(70);
    motor4.run(FORWARD);
    motor4.setSpeed(70);
    }

  else if (leftleftsensor>threshold && leftsensor<threshold && rightsensor<threshold && rightrightsensor>threshold)
    {
    motor1.run(FORWARD);
    motor1.setSpeed(70);
    motor2.run(FORWARD);
        motor2.setSpeed(70);
    motor3.run(BACKWARD);
    motor3.setSpeed(70);
    motor4.run(BACKWARD);
    motor4.setSpeed(70);
    } // 1001
    
  else if (leftleftsensor<threshold && leftsensor>threshold && rightsensor>threshold && rightrightsensor<threshold)
    {
    motor1.run(FORWARD);
    motor1.setSpeed(70);
    motor2.run(FORWARD);
    motor2.setSpeed(70);
    motor3.run(BACKWARD);
    motor3.setSpeed(70);
    motor4.run(BACKWARD);
    motor4.setSpeed(70);
    } //0110

  else if (leftleftsensor<threshold && leftsensor>threshold && rightsensor<threshold && rightrightsensor>threshold)
    {
    motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor3.run(FORWARD);
    motor4.run(FORWARD);
    } // 0101
    
  else if (leftleftsensor>threshold && leftsensor<threshold && rightsensor>threshold && rightrightsensor<threshold)
    {
    motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor3.run(FORWARD);
    motor4.run(FORWARD);
    } //1010
    



  else if (leftleftsensor<threshold && leftsensor>threshold && rightsensor<threshold && rightrightsensor<threshold)
    {
    motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor3.run(FORWARD);
    motor4.run(FORWARD);
    } // 0101
    




     // ALL LEFT TURN CONDITIONS 
  else if (leftleftsensor<threshold && leftsensor>threshold && rightsensor<threshold && rightrightsensor<threshold)
   {
    
    motor1.run(BACKWARD);
    motor1.setSpeed(120);
    motor2.run(BACKWARD);
    motor2.setSpeed(120);
    motor3.run(FORWARD);
    motor3.setSpeed(120);
    motor4.run(FORWARD);
        motor4.setSpeed(120);
        
    } // 0120
    

  else if (leftleftsensor>threshold && leftsensor<threshold && rightsensor<threshold && rightrightsensor<threshold)
    {
    motor1.run(BACKWARD);
    motor1.setSpeed(120);
    motor2.run(BACKWARD);
    motor2.setSpeed(120);
    motor3.run(FORWARD);
    motor3.setSpeed(120);
    motor4.run(FORWARD);
        motor4.setSpeed(120);
    } // 1200


  else if (leftleftsensor>threshold && leftsensor>threshold && rightsensor<threshold && rightrightsensor<threshold)
    {
    motor1.run(BACKWARD);
    motor1.setSpeed(120);
    motor2.run(BACKWARD);
    motor2.setSpeed(120);
    motor3.run(FORWARD);
    motor3.setSpeed(120);
    motor4.run(FORWARD);
        motor4.setSpeed(120);
    } // 1120


  else if (leftleftsensor>threshold && leftsensor>threshold && rightsensor>threshold && rightrightsensor<threshold)
    {
    
    motor1.run(BACKWARD);
    motor1.setSpeed(120);
    motor2.run(BACKWARD);
    motor2.setSpeed(120);
    motor3.run(FORWARD);
    motor3.setSpeed(120);
    motor4.run(FORWARD);
        motor4.setSpeed(120);
    } // 1110

    // ALL RIGHT TURN CONDITIONS
    
      else if (leftleftsensor<threshold && leftsensor<threshold && rightsensor>threshold && rightrightsensor<threshold)
    {
    motor1.run(FORWARD);
    motor1.setSpeed(120);
    motor2.run(FORWARD);
    motor2.setSpeed(120);
    motor3.run(BACKWARD);
    motor3.setSpeed(120);
    motor4.run(BACKWARD);
       motor4.setSpeed(120);
       
    }// 0010
    

  else if (leftleftsensor<threshold && leftsensor<threshold && rightsensor<threshold && rightrightsensor>threshold)
    {
    
    motor1.run(FORWARD);
    motor1.setSpeed(120);
    motor2.run(FORWARD);
    motor2.setSpeed(120);
    motor3.run(BACKWARD);
    motor3.setSpeed(120);
    motor4.run(BACKWARD);
        motor4.setSpeed(120);
    } // 0001
    
  else if (leftleftsensor<threshold && leftsensor<threshold && rightsensor>threshold && rightrightsensor>threshold)
    {
    
    motor1.run(FORWARD);
    motor1.setSpeed(120);
    motor2.run(FORWARD);
    motor2.setSpeed(120);
    motor3.run(BACKWARD);
    motor3.setSpeed(120);
    motor4.run(BACKWARD);
    motor4.setSpeed(120);
    } //0011


   else if (leftleftsensor<threshold && leftsensor>threshold && rightsensor>threshold && rightrightsensor>threshold)
   {
    
    motor1.run(FORWARD);
    motor1.setSpeed(120);
    motor2.run(FORWARD);
    motor2.setSpeed(120);
    motor3.run(BACKWARD);
    motor3.setSpeed(120);
    motor4.run(BACKWARD);
    motor4.setSpeed(120);
    } // 0111




  else //(leftleftsensor>threshold && leftsensor>threshold && rightsensor>threshold && rightrightsensor>threshold)
    {
    motor1.run(FORWARD);
    motor1.setSpeed(120);
    motor2.run(FORWARD);
    motor2.setSpeed(120);
    motor3.run(BACKWARD);
    motor3.setSpeed(120);
    motor4.run(BACKWARD);
       motor4.setSpeed(120);

       delay(500);
    } 

}
