#include <Wire.h> // 아두이노 I2C 통신 표준 라이브러리

const int MPU = 0x68; // 자이로센서 I2C 통신 주소 저장

int16_t AcX, AcY, AcZ, Tmp, GyX, GyY, GyZ;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  Wire.beginTransmission(MPU); 
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);
}

void loop() {
  Wire.beginTransmission(MPU);
  Wire.write(0x6B);
  Wire.endTransmission(false);

  Wire.requesFrom(MPU,14)

}
