#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C myLCD(0x27,16,2);

void setup() {
  myLCD.init();
  myLCD.backlight();
}

void loop() {
  myLCD.setCursor(0, 0); // == myLCD.home();
  myLCD.print("Hello, World!");

  myLCD.setCursor(0, 1);
  myLCD.print("I'm eungyeong^o^");
  delay(1000);

  myLCD.clear();
  delay(1000);

}
