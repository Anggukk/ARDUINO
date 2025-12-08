int LED[]={12,11,10};
int count=3;

void setup() {
  for(int i=0;i<count;i++){
    pinMode(LED[i], OUTPUT);
  }

}

void loop() {
  for(int i=0;i<count;i++){
    digitalWrite(LED[i], HIGH);
    delay(500);
  }
  for(int i=0;i<count;i++){
    digitalWrite(LED[i],LOW);
    delay(500);
  }
}
