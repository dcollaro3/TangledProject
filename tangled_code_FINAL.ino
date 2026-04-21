/*code used for once upon an arduino project: Tangled. There are 6 scenes, and 6 interactions, only 4 of those interactions required code. 
The first scene has Flynn step into the tower area and when circuit is completed Rapunzel's hair swings using a servo.
Second scene didn't require code.
Third scene was when you place an alligator clip on Flynn's hand it would light up.
Fourth scene didn't require code.
5th & 6th scene when activated had a 360 degree servo that would spin when you place an object to complete the circuit. 
All circuit were completed by seperating the 5V wire and then having copper tape on the back of an object to connect the 5V wire to servos. 
*/

#include <Servo.h>
#include <math.h>

Servo servo180; //servo used for Rapunzel's hair s1

Servo servo360_1; //servo used for mother gothels death s5
Servo servo360_2; //servo used for dancing end scene s6

int t = 0;
int ledPin = 13; //led for s3

unsigned long lastFlip = 0;
bool direction = true;

void setup() {
  servo180.attach(2);

  servo360_1.attach(5);
  servo360_2.attach(6);

  pinMode(ledPin, OUTPUT); 
}

void loop() {
  t++;
  int hairAngle = 90 + 20 * sin(t * 0.06); //code for hair servo

  servo180.write(hairAngle); 
  unsigned long currentTime = millis();

  if (currentTime - lastFlip > 2000) { 
    lastFlip = currentTime;
    direction = !direction;
  }

  if (direction) {
    servo360_1.write(120); 
    servo360_2.write(120);
    digitalWrite(ledPin, HIGH); // Turn LED on
  } else {
    servo360_1.write(60);  
    servo360_2.write(60);
    digitalWrite(ledPin, LOW); // Turn LED off
  }

  delay(20);
}