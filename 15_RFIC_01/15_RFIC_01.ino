#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 9
#define RST_PIN 10

MFRC522 mfrc(SS_PIN,RST_PIN);

void setup() {
  Serial.begin(9600);
  SPI.begin();

  mfrc.PCD_Init();
  Serial.print("연결 확인");
}

void loop() {
  if(mfrc.PICC_ReadCardSerial()){
    Serial.println("새로운 카드 접근 !");
    delay(500);
  }
  if(mfrc.PICC_IsNewCardPresent()){
    Serial.println("새로운 카드 접근 !");
    delay(500);
  }

  Serial.print("Card UID = ");

  for(byte i=0;i<4;i++){
    Serial.print(mfrc.uid.uidByte[i]);
    Serial.print(" ");
  }

  Serial.println();

}
