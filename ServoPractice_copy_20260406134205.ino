#include <Servo.h> //servo code 

Servo servo360;
Servo servo180;

void setup() {
  servo360.attach(9);  // 360° servo
  servo180.attach(8);  // 180° servo
}

void loop() {
  // 360° servo
  servo360.write(180);
  delay(2000); // run 2 seconds
  servo360.write(0);
  delay(2000);

 // 180 servo
  for (int pos = 0; pos <= 180; pos += 1) {
    servo180.write(pos);
    delay(15);
  }
  for (int pos = 180; pos >= 0; pos -= 1) {
    servo180.write(pos);
    delay(15);
  }
}