#include <Servo.h>

Servo servo;

const byte servo_signal = 4;

void setup(){
  servo.attach(servo_signal);

}

void loop(){

  servo.write(180);
  delay(1000);
  servo.write(0);
  delay(1000);
}
