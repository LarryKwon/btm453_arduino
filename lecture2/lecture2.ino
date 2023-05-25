int pin_buzzer = 2;

int Tones[7] = {262, 294, 330, 349, 392, 440, 494};
int Tones_Num;

void setup() {
  // put your setup code here, to run once:
  pinMode(pin_buzzer, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  for(Tones_Num = 0; Tones_Num < 7; Tones_Num++){
    // output sound
    tone(pin_buzzer,Tones[Tones_Num]);
    delay(500);

    // stop sound
    noTone(pin_buzzer);
    delay(500);    
  }
}
