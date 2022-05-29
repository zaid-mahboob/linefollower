/* https://github.com/zaid-mahboob/linefollower 
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
int sensormiddle =A3;
int sensorright = A2;
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

Serial.println(right);
        //forward
if ((leftleft <threshold && left < threshold) &&  (rightright <threshold && right < threshold)){
  digitalWrite(rightmotor1, HIGH);
  digitalWrite(rightmotor2, LOW);
  digitalWrite(leftmotor1, HIGH);
  digitalWrite(leftmotor2, LOW);
  analogWrite(rightpwm, 80);
  analogWrite(leftpwm, 79);  
}           //right 
else if((leftleft <threshold && left < threshold) &&  (rightright > threshold || right > threshold)){
  digitalWrite(rightmotor1, LOW);
  digitalWrite(rightmotor2, HIGH);
  digitalWrite(leftmotor1, HIGH);
  digitalWrite(leftmotor2, LOW);
  analogWrite(rightpwm, 110);
  analogWrite(leftpwm, 150);
  
}             // left
else if((leftleft > threshold || left > threshold) &&  (rightright <threshold && right < threshold)){
  digitalWrite(rightmotor1, HIGH);
  digitalWrite(rightmotor2, LOW);
  digitalWrite(leftmotor1, LOW);
  digitalWrite(leftmotor2, HIGH);
  analogWrite(rightpwm, 150);
  analogWrite(leftpwm, 110);

  
}           // stop right
if((leftleft >threshold || left > threshold) &&  (rightright >threshold || right > threshold)){
  digitalWrite(rightmotor1, LOW);
  digitalWrite(rightmotor2, HIGH);
  digitalWrite(leftmotor1, HIGH);
  digitalWrite(leftmotor2, LOW);
  analogWrite(rightpwm, 110);
  analogWrite(leftpwm, 150);
}
}
