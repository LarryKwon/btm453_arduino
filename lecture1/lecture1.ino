#include <Wire.h>
#include <LiquidCrystal_I2C.h>
//16 -> 가로 글자 수
//2 -> 세로 글자 수
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Hello, world!");
  lcd.setCursor(0,1);
  lcd.print("Name: Gildong");
}

void loop() {

}
