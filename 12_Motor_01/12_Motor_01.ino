#include <Servo.h>

Servo myServo;

void setup() {
  Serial.begin(9600);
  myServo.attach(10);
}

void loop() {
 for(int angle=0;angle<=180;angle++){
  myServo.write(angle);
  Serial.print("angle : ");
  Serial.println(angle);
  delay(100);
 } 
}
