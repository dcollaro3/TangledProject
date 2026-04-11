#include <Servo.h>
#include <math.h>

Servo servo180;
Servo servo180_2;

Servo servo360_1;
Servo servo360_2;

int t = 0;


unsigned long lastFlip = 0;
bool direction = true;

void setup() {
  servo180.attach(2);
  servo180_2.attach(4);

  servo360_1.attach(5);
  servo360_2.attach(6);
}

void loop() {
  t++;
  int hairAngle = 90 + 20 * sin(t * 0.06);
  int boatAngle = 90 + 20 * sin(t * 0.08 + 1.5);

  servo180.write(hairAngle);
  servo180_2.write(boatAngle);
  unsigned long currentTime = millis();

  if (currentTime - lastFlip > 2000) { 
    lastFlip = currentTime;
    direction = !direction;
  }

  if (direction) {
    servo360_1.write(120); 
    servo360_2.write(120);
  } else {
    servo360_1.write(60);  
    servo360_2.write(60);
  }

  delay(20);
}