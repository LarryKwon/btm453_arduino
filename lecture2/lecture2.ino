#include <Servo.h>

Servo servo;
const byte servo_signal = 4;

const byte red_led = 6;
const byte green_led = 5;
const byte blue_led = 7;
const byte joystick_sw = 3;

int val_x;
int val_y;
int pulse_width = 544;
int red_delta;
int red_brightness = 0;
int green_brightness = 0;
int delta_width;

void setup(){
  servo.attach(servo_signal);
  pinMode(red_led, OUTPUT);
  pinMode(green_led, OUTPUT);
  pinMode(blue_led, OUTPUT);
  pinMode(joystick_sw, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(joystick_sw), tact, CHANGE);
  Serial.begin(9600);
}

void loop(){
  val_x = analogRead(A0);  
  delta_width = map(val_x, 0, 1023, -60, 60);
  pulse_width += delta_width;
  
  servo.writeMicroseconds(pulse_width);

  val_y = analogRead(A1);
  Serial.println(val_y);
  red_brightness = map(val_y, 0, 1023, -255, 255);
  green_brightness = map(val_y, 0, 1023, 255, -255);
  analogWrite(red_led, (red_brightness>0)?red_brightness:0);
  analogWrite(green_led, (green_brightness>0)?green_brightness:0);

  delay(10);
}

void tact(){
  digitalWrite(blue_led, !digitalRead(joystick_sw));
}
