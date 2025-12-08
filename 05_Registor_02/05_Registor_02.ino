int LED_PIN=10;
int TR=A0;

void setup() {
  pinMode(LED_PIN,OUTPUT);
  pinMode(TR, INPUT);
  Serial.begin(9600);
}

void loop() {
  int registor=analogRead(TR);
  Serial.println(registor);
  //registor=registor/4;
  registor=map(registor, 0, 1024, 0, 255);
  analogWrite(LED_PIN, registor);
  delay(100);
}
