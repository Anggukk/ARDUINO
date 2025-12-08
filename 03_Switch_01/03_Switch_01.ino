int BTN=2;

void setup() {
12345678910
  delay(1);
}

Message (Enter to send message to 'Arduino Uno' on 'COM3')
New Line
9600 baud
1
1
1
1
1
1
1
1
1
1
1
1
1
1

  Serial.begin(9600);
  pinMode(BTN, INPUT);
}

void loop() {
  int buttonState=digitalRead(BTN);
  Serial.println(buttonState);
  delay(1);
}
