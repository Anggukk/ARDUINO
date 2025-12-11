const int PANEL_PIN=A0;
const int SW_PIN=2;

long energy=0;

const long SELL_UNIT=100;

const int MAX_CHARE_RATE=50;

void setup() {
  Serial.begin(9600);
  pinMode(SW_PIN,INPUT_PULLUP);
}

void loop() {
  int raw=analogRead(PANEL_PIN);
  float voltage=(raw*5.0)/1023.0;

  int gain=(voltage/5.0)*MAX_CHARE_RATE;
  
  if(gain>0){
    energy+=gain;
  }

  if(digitalRead(SW_PIN)==LOW){
    Serial.println("=== 스위치 눌림 ===");
    if(energy>=SELL_UNIT){
      Serial.println("판매 성공 !!");
      energy-=SELL_UNIT;
      Serial.print("남은 에너지 : ");
      Serial.println(energy);
    }
    else{
      Serial.println("에너지 부족 !! 판매 실패 ㅠㅠ");
      Serial.print("남은 에너지 : ");
      Serial.println(energy);
    }
  }

  Serial.println("=== 현재 상태 출력 ===");
  Serial.print("전압 : ");
  Serial.print(voltage);
  Serial.print(" | 적립량 : ");
  Serial.print(gain);
  Serial.print(" | 현재 에너지 : ");
  Serial.println(energy);

  delay(1000);
}
