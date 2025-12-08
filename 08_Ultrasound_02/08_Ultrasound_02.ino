#define TRIG 2
#define ECHO 3

void setup() {
  Serial.begin(9600);
  pinMode(TRIG,OUTPUT);
  pinMode(ECHO,INPUT);
  pimMode(8,OUTPUT);
}

void loop() {
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  float duration = pulseIn(ECHO,HIGH);
  float distance = ((34000*duration)/1000000)/2;

  Serial.print(distance);
  Serial.println("cm");

  if (distance<10){
    digitalWrite(8, HIGH);
    delay(100);
  }
  else {
  digitalWrite(8, LOW);
  delay(100);
  }
  
  delay(100);
}