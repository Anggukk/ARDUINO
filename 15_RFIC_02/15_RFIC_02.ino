#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9

#define BUZZ 4
#define LED_R 2
#define LED_B 3

MFRC522 mfrc(SS_PIN,RST_PIN);

void setup() {
  Serial.begin(9600);
  SPI.begin();
  mfrc.PCD_Init();

  pinMode(BUZZ,OUTPUT);
  pinMode(LED_R,OUTPUT);
  pinMode(LED_B,OUTPUT);
}

void loop() {
  if(!mfrc.PICC_IsNewCardPresent()||!mfrc.PICC_ReadCardSerial()){
    delay(500);
    return;
  }

  if(mfrc.uid.uidByte[0]==189 && mfrc.uid.uidByte[1]==50 && mfrc.uid.uidByte[2]==25 && mfrc.uid.uidByte[3]==2){
    digitalWrite(LED_B, HIGH);
    digitalWrite(BUZZ,HIGH);
    delay(1000);
    digitalWrite(LED_B, LOW);
    digitalWrite(BUZZ, LOW);

    return;
  }
  else if(mfrc.uid.uidByte[0]==172 && mfrc.uid.uidByte[1]==228 && mfrc.uid.uidByte[2]==205 && mfrc.uid.uidByte[3]==1){
    digitalWrite(LED_R, HIGH);
    digitalWrite(BUZZ, HIGH);
    delay(500);
    digitalWrite(LED_R, LOW);
    digitalWrite(BUZZ, LOW);
    delay(500);
    digitalWrite(LED_R, HIGH);
    digitalWrite(BUZZ, HIGH);
    delay(500);
    digitalWrite(LED_R, LOW);
    digitalWrite(BUZZ, LOW);

    return;
  }

}
