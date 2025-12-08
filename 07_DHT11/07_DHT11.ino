#include "DHT.h"

#define DHTPIN 2
#define DHTTYPE DHT11

// DHT 센서를 제어하는 객체 (오브젝트) 생성
// DHT : DHT 라이브러리에 정의된 클래스 (class)
// mydht : 내가 만드는 객체 이름
// (DHTPIN,DHTTYPE) : mydht 객체를 만들 때 전달하는 초기 설정 값
DHT mydht(DHTPIN,DHTTYPE);

void setup() {
  Serial.begin(9600);
  mydht.begin();
}

void loop() {
  delay(2000); // 측정 대기 시간
  float h=mydht.readHumidity(); // 습도 측정
  float c=mydht.readTemperature(); // 온도 측정(섭씨)
  float f=mydht.readTemperature(true); // 온도 측정(화씨)

  if(isnan(h) || isnan(c) || isnan(f)){
    Serial.println("측정실패 !");
    return; // loop 처음부터 다시 시작
  }

  Serial.print("습도 : ");
  Serial.print(h);
  Serial.print("% | 섭씨 온도 : ");
  Serial.print(c);
  Serial.print("C | 화씨 온도 : ");
  Serial.print(f);
  Serial.println("F");

  Serial.println("습도 : "+String(h)+"% | 섭씨 온도 : "+String(c)+"C | 화씨 온도 : "+String(f)+"F");
}
