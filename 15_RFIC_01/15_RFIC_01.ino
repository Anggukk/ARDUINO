#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9

MFRC522 mfrc(SS_PIN,RST_PIN);

void setup() {
  Serial.begin(9600);
  SPI.begin();

  mfrc.PCD_Init();
  Serial.print("연결 확인");
}

void loop() {

  if( !mfrc.PICC_IsNewCardPresent()||!mfrc.PICC_ReadCardSerial()){
    Serial.println("카드 태그 없음");
    delay(1000);
    return;
  }

  Serial.print("Card UID = ");
  for(byte i=0;i<4;i++){
    Serial.print(mfrc.uid.uidByte[i]);
    Serial.print(" ");
  }

  Serial.println();

// 하얀카드 - Card UID = 189 50 25 2
// 파란카드 - Card UID = 172 228 205 1

}
