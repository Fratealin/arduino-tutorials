#include <Stepper.h>
int stepsPerRevolution=2048; // depends on the motor. Don't change
Stepper myStepper(stepsPerRevolution, 8,10,9,11); // depends on the motor
int motorSpeed=10; //rpm
int dt = 500;

int buttonPin=12;
int buttonNew;
int buttonOld =1;
int msg;
boolean clockwise = true; 

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
myStepper.setSpeed(motorSpeed);
pinMode(buttonPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (clockwise==true){
    myStepper.step(1);
    Serial.println("clockwise");

  }
  else{
    myStepper.step(-1);
    Serial.println("anticlockwise");

  }
button();
Serial.println(buttonOld);

}

void button(){
  buttonNew=digitalRead(buttonPin);

  if (buttonOld==1 && buttonNew==0){
    // just gone down
    if (clockwise==false){
      msg = 0;
    clockwise = true;
    }
    else if (clockwise==true){
    clockwise = false;
  msg=1;
    }
  }
      buttonOld = buttonNew; 
}
