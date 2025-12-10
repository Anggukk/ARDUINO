#include <Servo.h>
#include <LiquidCrystal_I2C.h>

Servo myServo;
LiquidCrystal_I2C myLCD(0x27,16,2);

#define Servo 5

void setup() {
  myServo.attach(Servo);
  myLCD.init();
  myLCD.backlight();

  pinMode(A0,INPUT);
}

void loop() {

  myLCD.home();

  int registor=analogRead(A0);
  registor=map(registor,0,1023,0,180);

  myServo.write(registor);

  myLCD.print("Servo now : ");
  myLCD.setCursor(0,1);
  myLCD.print(registor);

  delay(1000);
  myLCD.clear();
}
