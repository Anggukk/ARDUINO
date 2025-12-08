#include "DHT.h"

#define DHTPIN 2
#define DHTTYPE DHT22

DHT mydht(DHTPIN,DHTTYPE);

void setup() {
  Serial.begin(9600);
  mydht.begin();
}

void loop() {
  delay(2000);
  float h = mydht.readHumidity();
  float c = mydht.readTemperature();
  float f = mydht.readTemperature(true);

  if (isnan(h) || isnan(c) || isnan(f)){
    Serial.println("측정 실패 !!");
    return ;
  }

  Serial.println("습도 : "+String(h)+" | 온도(섭씨) : "+String(c)+" | 온도(화씨) : "+String(f));
}
