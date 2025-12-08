int LED_PIN=3;

void setup() {
  pinMode(LED_PIN,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  for(int i=0;i<=255;i++){
    analogWrite(LED_PIN,i);
    delay(10);
    Serial.println(i);
  }
}