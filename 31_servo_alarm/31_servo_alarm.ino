// Load a library
#include <Servo.h>
int servoPin=9;
int servoPosA=0;
int servoPosB=90;
int servoPosC=180;
int angle = 0;
float timeLimit = 60000.;

Servo myServo; // Create object

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
myServo.attach(servoPin);
}

void loop() {
  // put your main code here, to run repeatedly:
  angle = 0;
  while (angle<=180){
    Serial.println(timeLimit/180.);
    
    myServo.write(angle);
    delay(timeLimit/180);
    angle+=1;
  }
}
