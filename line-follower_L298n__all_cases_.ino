/* https://github.com/zaid-mahboob/linefollower 
 This robot has 5 sensors. In this code I have implemented all the possible sensor combination possibilites for black line. I have made
 multiple if else cases. After every case I have written its sensor combination such as 0110, 1001, etc. Here 1st digit
 represents left most sensor and 5th digit represent the right most sensor. Here 1 means that the sensor is 
 on black line and 0 means that the sensor is on white line.
 For more line following codes visit https://github.com/zaid-mahboob/linefollower 
 */

int rightmotor1 = 5;
int rightmotor2 = 6;
int leftmotor1 = 3;
int leftmotor2 = 4;
int rightpwm  = 11;
int leftpwm = 10;




int sensorleftleft = A0; // sensor pins
int sensorleft = A1;
int sensormiddle =A2;
int sensorright = A3;
int sensorrightright = A4;
int leftleft = 0; // sensor values
int left =0;
int middle = 0;
int right = 0;
int rightright = 0;
int threshold = 500;
  
void setup(){
  Serial.begin(9600);
  pinMode(sensorleftleft, INPUT);
  pinMode(sensorleft, INPUT);
  pinMode(sensormiddle, INPUT);
  pinMode(sensorright, INPUT);
  pinMode(sensorrightright, INPUT);
  pinMode(rightmotor1, OUTPUT);
  pinMode(rightmotor2, OUTPUT);
  pinMode(leftmotor1, OUTPUT);
  pinMode(leftmotor2, OUTPUT);
  pinMode(rightpwm, OUTPUT);
  pinMode(leftpwm, OUTPUT);




}
void loop(){
  leftleft= analogRead(sensorleftleft);
  left = analogRead(sensorleft);
  middle = analogRead(sensormiddle);
  right = analogRead(sensorright);
  rightright = analogRead(sensorrightright);

Serial.println(middle);
if (leftleft <threshold && left < threshold && right < threshold && rightright <threshold){
    digitalWrite(rightmotor1, HIGH);
  digitalWrite(rightmotor2, LOW);
  digitalWrite(leftmotor1, HIGH);
  digitalWrite(leftmotor2, LOW);
  analogWrite(rightpwm, 105);
  analogWrite(leftpwm, 99);
  
}           // 1st condition 00100
if(leftleft <threshold && left > threshold && right < threshold && rightright <threshold){
    digitalWrite(rightmotor1, HIGH);
  digitalWrite(rightmotor2, LOW);
  digitalWrite(leftmotor1, LOW);
  digitalWrite(leftmotor2, HIGH);
  analogWrite(rightpwm, 104);
  analogWrite(leftpwm, 98);
  
}             // 2nd condition 01000
if(leftleft <threshold && left < threshold && right > threshold && rightright <threshold){
    digitalWrite(rightmotor1, LOW);
  digitalWrite(rightmotor2, HIGH);
  digitalWrite(leftmotor1, HIGH);
  digitalWrite(leftmotor2, LOW);
  analogWrite(rightpwm, 104);
  analogWrite(leftpwm, 98);
  
}           // 3rd condition 00010
if(leftleft <threshold && left < threshold && right > threshold && rightright > threshold){
    digitalWrite(rightmotor1, LOW);
  digitalWrite(rightmotor2, HIGH);
  digitalWrite(leftmotor1, HIGH);
  digitalWrite(leftmotor2, LOW);
  analogWrite(rightpwm, 104);
  analogWrite(leftpwm, 98);
  
}           // 4th condition 00111
if(leftleft >threshold && left > threshold && right < threshold && rightright <threshold){
    digitalWrite(rightmotor1, HIGH);
  digitalWrite(rightmotor2, LOW);
  digitalWrite(leftmotor1, LOW);
  digitalWrite(leftmotor2, HIGH);
  analogWrite(rightpwm, 104);
  analogWrite(leftpwm, 98);
  
}           // 5th condition  11100
if(leftleft <threshold && left < threshold && right < threshold && rightright >threshold){
    digitalWrite(rightmotor1, LOW);
  digitalWrite(rightmotor2, HIGH);
  digitalWrite(leftmotor1, HIGH);
  digitalWrite(leftmotor2, LOW);
  analogWrite(rightpwm, 105);
  analogWrite(leftpwm, 99);
  
}             // 6th condition 00001
if(leftleft > threshold && left < threshold && right < threshold && rightright <threshold){
    digitalWrite(rightmotor1, HIGH);
  digitalWrite(rightmotor2, LOW);
  digitalWrite(leftmotor1, LOW);
  digitalWrite(leftmotor2, HIGH);
  analogWrite(rightpwm, 105);
  analogWrite(leftpwm, 99);
  
}             // 7th condition 10000
if(leftleft >threshold && left > threshold && right > threshold && rightright > threshold){
  digitalWrite(rightmotor1, LOW);
  digitalWrite(rightmotor2, HIGH);
  digitalWrite(leftmotor1, HIGH);
  digitalWrite(leftmotor2, LOW);
  analogWrite(rightpwm, 105);
  analogWrite(leftpwm, 99);
  
}             // 8th condition 11111
if(leftleft <threshold && left < threshold && right < threshold && rightright <threshold){
    digitalWrite(rightmotor1, HIGH);
  digitalWrite(rightmotor2, LOW);
  digitalWrite(leftmotor1, HIGH);
  digitalWrite(leftmotor2, LOW);
  analogWrite(rightpwm, 105);
  analogWrite(leftpwm, 99);
  
}             // 9th condition 00000
if(leftleft <threshold && left > threshold && right > threshold && rightright <threshold){
    digitalWrite(rightmotor1, LOW);
  digitalWrite(rightmotor2, HIGH);
  digitalWrite(leftmotor1, HIGH);
  digitalWrite(leftmotor2, LOW);
  analogWrite(rightpwm, 100);
  analogWrite(leftpwm, 100);
}               // 10th condition 01010
if(leftleft >threshold && left < threshold && right < threshold && rightright >threshold){
    digitalWrite(rightmotor1, LOW);
  digitalWrite(rightmotor2, HIGH);
  digitalWrite(leftmotor1, HIGH);
  digitalWrite(leftmotor2, LOW);
  analogWrite(rightpwm, 105);
  analogWrite(leftpwm, 99);
}           // 11th condition 10001
if(leftleft <threshold && left < threshold && right > threshold && rightright >threshold){
    digitalWrite(rightmotor1, LOW);
  digitalWrite(rightmotor2, HIGH);
  digitalWrite(leftmotor1, HIGH);
  digitalWrite(leftmotor2, LOW);
  analogWrite(rightpwm, 105);
  analogWrite(leftpwm, 99);
}               //12th condition 00011
if(leftleft >threshold && left > threshold && right < threshold && rightright <threshold){
    digitalWrite(rightmotor1, HIGH);
  digitalWrite(rightmotor2, LOW);
  digitalWrite(leftmotor1, LOW);
  digitalWrite(leftmotor2, HIGH);
  analogWrite(rightpwm, 105);
  analogWrite(leftpwm, 99);
}               // 13th condition 11000
if(leftleft <threshold && left > threshold && right > threshold && rightright <threshold){
    digitalWrite(rightmotor1, LOW);
  digitalWrite(rightmotor2, HIGH);
  digitalWrite(leftmotor1, HIGH);
  digitalWrite(leftmotor2, LOW);
  analogWrite(rightpwm, 100);
  analogWrite(leftpwm, 100);
}               // 14th condition 01110
if(leftleft >threshold && left < threshold && right < threshold && rightright <threshold){
    digitalWrite(rightmotor1, HIGH);
  digitalWrite(rightmotor2, LOW);
  digitalWrite(leftmotor1, LOW);
  digitalWrite(leftmotor2, HIGH);
  analogWrite(rightpwm, 105);
  analogWrite(leftpwm, 99);
}               // 15th condition 10100 
if(leftleft >threshold && left > threshold && right > threshold && rightright >threshold){
    digitalWrite(rightmotor1, LOW);
  digitalWrite(rightmotor2, HIGH);
  digitalWrite(leftmotor1, HIGH);
  digitalWrite(leftmotor2, LOW);
  analogWrite(rightpwm, 105);
  analogWrite(leftpwm, 99);
}                         // 16th condition 11011
if(leftleft >threshold && left < threshold && right < threshold && rightright >threshold){
    digitalWrite(rightmotor1, LOW);
  digitalWrite(rightmotor2, HIGH);
  digitalWrite(leftmotor1, HIGH);
  digitalWrite(leftmotor2, LOW);
  analogWrite(rightpwm, 105);
  analogWrite(leftpwm, 99);
}                         // 17th condition 10101
if(leftleft <threshold && left < threshold && right < threshold && rightright >threshold){
    digitalWrite(rightmotor1, LOW);
  digitalWrite(rightmotor2, HIGH);
  digitalWrite(leftmotor1, HIGH);
  digitalWrite(leftmotor2, LOW);
  analogWrite(rightpwm, 105);
  );
}                   // 18th condition
}
