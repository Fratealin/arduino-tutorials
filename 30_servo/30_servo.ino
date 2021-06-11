// Load a library
#include <Servo.h>
int servoPin=9;
int servoPosA=0;
int servoPosB=90;
int servoPosC=180;
int t = 500;
Servo myServo; // Create object

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
myServo.attach(servoPin);
}

void loop() {
  // put your main code here, to run repeatedly:
    myServo.write(90);
    delay(500);
    myServo.write(0);
    delay(500);
  

}
