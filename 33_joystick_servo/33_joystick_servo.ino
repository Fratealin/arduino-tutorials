// Load a library
#include <Servo.h>
int servoPin=9;
int angle = 0;
Servo myServo; // Create object


int Xpin = A0;
int Ypin = A1;
int SwitchPin = 2;
int Xval;
int Yval;
float switchVal;
int dt = 50;

int greenPin = 6;
int bluePin = 12;
int buzzPin = 3;




void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(Xpin, INPUT);
pinMode(Ypin, INPUT);
pinMode(SwitchPin, INPUT);
digitalWrite(SwitchPin,HIGH); // sets up the pullup resistor
pinMode(greenPin, OUTPUT);
pinMode(bluePin, OUTPUT);
pinMode(buzzPin, OUTPUT);
myServo.attach(servoPin);


}

void loop() {
  // put your main code here, to run repeatedly:
  Xval = analogRead(Xpin);
  Yval = analogRead(Ypin);
  switchVal = digitalRead(SwitchPin);
  delay(dt);
  Serial.print("X Value = ");
  Serial.print(Xval);
  Serial.print(" - Y Value = ");
  Serial.print(Yval);
  Serial.print(" - Switch State is ");
  Serial.println(switchVal);
  analogWrite(greenPin, 1 + Xval/1023.*255.);
  if (switchVal == 1){
      digitalWrite(bluePin, LOW);
      digitalWrite(buzzPin, LOW);
  }
  else{
    digitalWrite(bluePin, HIGH);
    digitalWrite(buzzPin, HIGH);

  }
  angle = Yval/1023.*180.;
  myServo.write(angle);              
}
