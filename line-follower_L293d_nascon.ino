/* https://github.com/zaid-mahboob/linefollower  
 
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
  motor1.setSpeed(69);
  motor2.setSpeed(69);
  motor3.setSpeed(69);
  motor4.setSpeed(69);
  Serial.begin(9600);
}
void loop() 
{
  leftsensor = analogRead(left);
  leftleftsensor = analogRead(left_left);
  rightsensor = analogRead(right);
  rightrightsensor = analogRead(right_right);
  Serial.println(rightrightsensor);
  // move forward
  if (leftleftsensor < threshold && leftsensor<threshold && rightsensor<threshold && rightrightsensor < threshold){
    
    motor1.run(FORWARD);
    motor1.setSpeed(70);
    motor2.run(FORWARD);
    motor2.setSpeed(70);
    motor3.run(FORWARD);
    motor3.setSpeed(70);
    motor4.run(FORWARD);
    motor4.setSpeed(70);
    }


    
      if ((leftleftsensor > threshold || leftsensor>threshold) && rightsensor<threshold && rightrightsensor < threshold){
    motor1.run(BACKWARD);
    motor1.setSpeed(180);
    motor2.run(BACKWARD);
    motor2.setSpeed(180);
    motor3.run(FORWARD);
    motor3.setSpeed(180);
    motor4.run(FORWARD);
    motor4.setSpeed(180);
    }


 
  if (leftleftsensor < threshold && leftsensor<threshold && (rightsensor>threshold || rightrightsensor > threshold)){
    motor1.run(FORWARD);
    motor1.setSpeed(180);
    motor2.run(FORWARD);
    motor2.setSpeed(180);
    motor3.run(BACKWARD);
    motor3.setSpeed(180);
    motor4.run(BACKWARD);
    motor4.setSpeed(180);
    
    }

  
  if ((leftleftsensor > threshold || leftsensor>threshold) && (rightsensor>threshold || rightrightsensor > threshold)){
    motor1.run(FORWARD);
    motor1.setSpeed(180);
    motor2.run(FORWARD);
    motor2.setSpeed(180);
    motor3.run(BACKWARD);
    motor3.setSpeed(180);
    motor4.run(BACKWARD);
    motor4.setSpeed(180);
    }

}
