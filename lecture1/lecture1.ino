#include <Wire.h>
#include <LiquidCrystal_I2C.h>
//16 -> 가로 글자 수
//2 -> 세로 글자 수
//0x27 -> lcd의 주소
LiquidCrystal_I2C lcd(0x27, 16, 2);

int val;
int brightness;

int pin_led_red = 10;
int pin_led_yellow = 9;
int pin_led_green = 6;

void print_lcd(int value, int brightness){
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Value: %d",value);
  lcd.setCursor(0,1);
  lcd.print("Bright: %d", brightness);
}

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Value: ");
  lcd.setCursor(0,1);
  lcd.print("Bright: ");

  pinMode(pin_led_red, OUTPUT);
  pinMode(pin_led_yellow, OUTPUT);
  pinMode(pin_led_green, OUTPUT);  
}

void loop() {
  val = analogRead(A0);
  brightness = map(val, 0, 1024, 0, 255);
  analogWrite(pin_led_red, brightness);
  analogWrite(pin_led_yellow, brightness);
  analogWrite(pin_led_green, brightness);

  print_lcd(val,brightness);
}
