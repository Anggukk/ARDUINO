#include <SoftwareSerial.h>

SoftwareSerial myESP(2,3);

void setup() {
 Serial.begin(9600);
 myESP.begin(9600);
}

void loop() {
  if(myESP.available()){
    Serial.write(myESP.read());
  }
  if(Serial.available()){
    myESP.write(Serial.read());
  }
}
