// int pin_led_red = 10;
// int pin_led_green = 9;
// int pin_led_blue = 6;

// int x;

// void setup() {
//   // put your setup code here, to run once:
//   pinMode(pin_led_red, OUTPUT);
//   pinMode(pin_led_green, OUTPUT);
//   pinMode(pin_led_blue, OUTPUT);

// }

// void turn_on_and_off(int pin_led){
//   digitalWrite(pin_led, HIGH);
//   delay(500);
//   digitalWrite(pin_led,LOW);
//   delay(500);
// }

// void loop() {
//   // put your main code here, to run repeatedly:
//   // digitalWrite(10, HIGH);
//   // delay(500);
//   // digitalWrite(10,LOW);
//   // delay(500);

//   // for(x=0; x<255; x++){
//   //   analogWrite(pin_led,x);
//   //   delay(10);
//   // }

//   // for(x=255;x>0;x--){
//   //   analogWrite(pin_led,x);
//   //   delay(10);
//   // }

//   turn_on_and_off(pin_led_red);
//   turn_on_and_off(pin_led_green);
//   turn_on_and_off(pin_led_blue);
// }




int val;
int brightness;

int pin_led_red = 10;
int pin_led_yellow = 9;
int pin_led_green = 6;

void setup() {
  // put your setup code here, to run once:
  pinMode(pin_led_red, OUTPUT);
  pinMode(pin_led_green, OUTPUT);
  pinMode(pin_led_yellow, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(A0);
  brightness = map(val, 0, 1024, 0, 255);
  analogWrite(pin_led_red, brightness);
  analogWrite(pin_led_yellow, brightness);
  analogWrite(pin_led_green, brightness);

  Serial.print(val);
  Serial.print("    ");
  Serial.println(brightness);
}
