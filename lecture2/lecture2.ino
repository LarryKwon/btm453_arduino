int pin_buzzer = 2;

void setup() {
  // put your setup code here, to run once:
  pinMode(pin_buzzer, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  // output sound
  tone(pin_buzzer,262);
  delay(1000);

  // stop sound
  noTone(pin_buzzer);
  delay(1000);
}
