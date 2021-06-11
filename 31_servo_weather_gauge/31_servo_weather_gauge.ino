// Load a library
#include <Servo.h>
int servoPin=9;
int servoPosA=0;
int servoPosB=90;
int servoPosC=180;
int t = 500;
Servo myServo; // Create object

int lightPin=A0;
float lightVal;
int angle;
int greenPin = 6;
float maxAngle = 0;
float minAngle = 180;
float maxLight = 750;
float minLight = 500;


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
myServo.attach(servoPin);

pinMode(lightPin, INPUT);
pinMode(greenPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  lightVal = analogRead(lightPin);
  Serial.println(lightVal);
  angle = minAngle +minLight*minAngle/(maxLight-minLight) - lightVal/(maxLight-minLight)*(minAngle);
    myServo.write(angle);
    analogWrite(greenPin, 255 +minLight*255./(maxLight-minLight) - lightVal/(maxLight-minLight)*(255.));
    delay(1000);
    //slowServo();

}

void slowServo(){
  for (int i = 0; i<=180; i++){
        myServo.write(i);
        delay(20);

  }
  
}
