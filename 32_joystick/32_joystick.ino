// Load a library
#include <Servo.h>
int Xpin = A0;
int Ypin = A1;
int SwitchPin = 2;
int Xval;
int Yval;
int SwitchVal;
int dt = 400;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(Xpin, INPUT);
pinMode(Ypin, INPUT);
pinMode(SwitchPin, INPUT);
digitalWrite(SwitchPin,HIGH); // sets up the pullup resistor
}

void loop() {
  // put your main code here, to run repeatedly:
  Xval = analogRead(Xpin);
  Yval = analogRead(Ypin);
  SwitchVal = digitalRead(SwitchPin);
  delay(dt);
  Serial.print("X Value = ");
  Serial.print(Xval);
  Serial.print(" - Y Value = ");
  Serial.print(Yval);
  Serial.print(" - Switch State is ");
  Serial.println(SwitchVal);

}
