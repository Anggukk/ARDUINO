int switch1=2;
int switch2=3;

int led1=10;
int led2=11;

void setup() {
  Serial.begin(9600);
  pinMode(switch1,INPUT_PULLUP);
  pinMode(led1,OUTPUT);
  pinMode(switch2,INPUT_PULLUP);
  pinMode(led2,OUTPUT);
}

void loop() {
  int BTNState1=digitalRead(switch1);
  int BTNState2=digitalRead(switch2);
  Serial.println(BTNState1);
  Serial.println(BTNState2);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  if(BTNState1==LOW){
    digitalWrite(led1, HIGH);
  }
  if(BTNState2==LOW){
    digitalWrite(led2, HIGH);
  }
}
