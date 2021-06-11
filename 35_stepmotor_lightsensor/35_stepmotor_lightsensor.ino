#include <Stepper.h>
int stepsPerRevolution=2048; // depends on the motor. Don't change
Stepper myStepper(stepsPerRevolution, 8,10,9,11); // depends on the motor
int motorSpeed=10; //rpm
int dt = 500;

int buttonPin=2;
int buttonNew;
int buttonOld =1;
int msg;
int green = 9;
int direction = -1; 

int lightPin = A0;
int lightVal; 
boolean bright=true;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
myStepper.setSpeed(motorSpeed);
pinMode(buttonPin, INPUT);
digitalWrite(buttonPin, HIGH);

pinMode(lightPin, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  
    myStepper.step(direction );
  
button();

lightVal = analogRead(lightPin);
Serial.println(lightVal);
if (lightVal>150 && bright == false){
  direction = direction*(-1);
  bright = true;
  }
  else if (lightVal <=150){
    bright = false;
  }

}
 
void button(){
  buttonNew=digitalRead(buttonPin);

  if (buttonOld==1 && buttonNew==0){
    // just gone down
    direction = direction*(-1);
  }
  buttonOld = buttonNew; 

}
