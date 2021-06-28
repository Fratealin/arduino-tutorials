// switch motor on and off with remote
// Vol+ an - changes speed
// fwd and rew changes direction

// wrap wires of motor, and connect remote to Arduino
// to reduce static

#include <IRremote.h>
int IRpin=11;
// Create IRremote object
IRrecv IR(IRpin);
// Put signal from IR sensor to cmd
decode_results cmd;

//byte remoteOn=0xFFA25D;
String myCom;

boolean on=false;
int velocity=255;

// motor controller
int speedPin=5; // pin1 on chip - EN1
int dir1=4; // pin2 on chip - IN1
int dir2=3; // pin7 on chip - IN2
int mSpeed=255;             // 100 - 255
boolean engineStarted = false;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
IR.enableIRIn();

pinMode(speedPin, OUTPUT);
pinMode(dir1, OUTPUT);
pinMode(dir2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  // The & symbol passes the address of the variable into the function
  // so it can be editted
  // brings the value returned by IR.decode() into cmd
while (IR.decode(&cmd)==0){
// wait till someone presses button
}
Serial.println(cmd.value,HEX);

switch(cmd.value){
  case 0xFFA25D: 
  if (!on){
  myCom="lighton";
  velocity=255;
  setRight();
  kickStart();
  on= true;
}
else if (on){
  myCom="lightoff";
  //Serial.println(myCom);
  velocity=0;
  //analogWrite(redPin, 0);
  on= false;
}
break;

case 0xFF629D:
  myCom="up";
  velocity+=50;
  if (velocity>255){
    velocity=255;
    //analogWrite(redPin, velocity);
  }
break;

case 0xFFA857:
  myCom="down";
  //Serial.println(myCom);
  velocity-=100;
  if (velocity<25){
    velocity=25;
    //analogWrite(redPin, velocity);
  }
  break;

case 0xFF22DD:
  myCom="left";
  //Serial.println(myCom);
  setLeft();
  while (!engineStarted){
  kickStart();
  engineStarted = true;
  }
  break;

case 0xFFC23D:
  myCom="right";
  //Serial.println(myCom);
  setRight();
  while (!engineStarted){
  kickStart();
  engineStarted = true;
  }

  break; 
  
  default:
  Serial.println("other button pressed");
break;
}

  Serial.println(velocity);
  Serial.println(myCom);
  keepRunning();

IR.resume(); // start reading again);

}

void setRight(){
  digitalWrite(dir1, HIGH);
  digitalWrite(dir2, LOW); // have to be opposite
}

void setLeft(){
  digitalWrite(dir1, LOW);
  digitalWrite(dir2, HIGH); // have to be opposite
}

void kickStart(){
  analogWrite(speedPin, mSpeed);
delay(75); // kick start
}

void keepRunning(){
  analogWrite(speedPin,velocity);
delay(500);
}
