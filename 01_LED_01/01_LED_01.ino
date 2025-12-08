int Pin1=10;
int Pin2=11;
int Pin3=12;

void setup() {
  pinMode(Pin1,OUTPUT);
  pinMode(Pin2,OUTPUT);
  pinMode(Pin3,OUTPUT);
}

void loop() {
  digitalWrite(Pin1,HIGH);
  digitalWrite(Pin2,HIGH);
  digitalWrite(Pin3,HIGH);
  delay(500);
  digitalWrite(Pin1,LOW);
  digitalWrite(Pin2,LOW);
  digitalWrite(Pin3,LOW);;
  delay(500);
}
