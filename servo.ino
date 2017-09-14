#include <Servo.h>
Servo kickBallServo;
int pos = 0;
void setup() {
  // put your setup code here, to run once:
  kickBallServo.attach(6);


}

void loop() {
  // put your main code here, to run repeatedly:
  for (pos = 0; pos < 180; pos += 10) 
  { // 每次步进一度
    kickBallServo.write(pos);       
    delay(15);      
  }
  
}
