#include "DHT.h"

#define GAS_A A0
#define SWITCH 7
#define BUZZ 4
#define green 11
#define blue 12
#define red 13
#define TRIG 2
#define ECHO 3

DHT mydht (8,DHT22);

void setup() {
  Serial.begin(9600);
  mydht.begin();
  Serial.println("센서 준비");

  delay(2000);

  pinMode(green,OUTPUT);
  pinMode(blue,OUTPUT);
  pinMode(red,OUTPUT);
  pinMode(TRIG,OUTPUT);
  pinMode(ECHO,INPUT);
  pinMode(BUZZ, OUTPUT);
  pinMode(SWITCH,INPUT_PULLUP);
}

void loop() {

  float sensorAValue = analogRead(GAS_A);
  float h = mydht.readHumidity();
  float c = mydht.readTemperature();
  float f = mydht.readTemperature(true);

  int BTNState=digitalRead(SWITCH);

  digitalWrite(BUZZ,LOW);

  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  float duration = pulseIn(ECHO,HIGH);
  float distance = ((34000*duration)/1000000)/2;

  if(distance<=5){
    digitalWrite(red,HIGH);
    delay(100);
    digitalWrite(red,LOW);
    delay(100);
    digitalWrite(red,HIGH);
    delay(100);
    if(BTNState==LOW){
      digitalWrite(BUZZ,HIGH);
    }
  }


  digitalWrite(green,LOW);
  digitalWrite(blue,LOW);
  digitalWrite(red,LOW);

  Serial.print("가스 농도 : ");
  Serial.println(sensorAValue);
  Serial.println("습도 : "+String(h)+" | 온도(섭씨) : "+String(c)+" | 온도(화씨) : "+String(f));
  

  if(sensorAValue > 300){
    digitalWrite(red,HIGH);
    delay(1000);
  }
  else if(sensorAValue > 100){
    digitalWrite(blue,HIGH);
    delay(1000);
  }
  else{
    digitalWrite(green,HIGH);
    delay(1000);
  }
}