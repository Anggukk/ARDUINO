int leds[]={12,11,10};
int count=3;

void turnOnALL(){
  for(int i=0;i<count;i++){
    digitalWrite(leds[i], HIGH);
    delay(500);
  }
}

void turnOffALL(){
  for(int i=0;i<count;i++){
    digitalWrite(leds[i], LOW);
    delay(500);
  }
}

void setup() {
  for(int i=0;i<count;i++){
    pinMode(leds[i], OUTPUT);
  }

}

void loop() {
  turnOnALL();
  turnOffALL();

}
