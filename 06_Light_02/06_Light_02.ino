void setup() {
  Serial.begin(9600);
  pinMode(10, OUTPUT);
}

void loop() {
  int photoresistor=analogRead(A0);
  Serial.println(photoresistor);
  if(photoresistor<=700){
    digitalWrite(10, LOW);
  }
  else if (photoresistor>700) {
  digitalWrite(10, HIGH);
  }
}
