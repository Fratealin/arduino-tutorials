// switch on and off
// 1: red 2: green 3: blue
// 1 then up and down to change redness

#include <IRremote.h>
int IRpin=11;
// Create IRremote object
IRrecv IR(IRpin);
// Put signal from IR sensor to cmd
decode_results cmd;

//byte remoteOn=0xFFA25D;
String myCom;
String color;

int redPin=6;
int greenPin=9;
int bluePin=10;
boolean on=false;
int brightness=255;
int green=255;
int blue=255;
int red=255;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
IR.enableIRIn();
pinMode(redPin, OUTPUT);
pinMode(greenPin, OUTPUT);
pinMode(bluePin, OUTPUT);
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
  red=255;
  blue=255;
  green=255;
  on= true;
}
else if (on){
  myCom="lightoff";
  //Serial.println(myCom);
  red=0;
  blue=0;
  green=0;
  //analogWrite(redPin, 0);
  on= false;
}
break;

case 0xFF629D:
  myCom="up";
  if (color=="red"){
    red+=50;
  if (red>255){
    red=255;
    //analogWrite(redPin, brightness);
  }
  }
  
break;

case 0xFF30CF:
  myCom="red";
  color="red";
  red=255;
  green=0;
  blue=0;
break;

case 0xFF18E7:
  myCom="green";
  red=0;
  green=255;
  blue=0;
break;

case 0xFF7A85:
  myCom="blue";
  red=0;
  green=0;
  blue=255;
break;


case 0xFFA857:
  myCom="down";
  //Serial.println(myCom);
  if (color=="red"){
    red-=50;
  if (red<0){
    red=0;
    //analogWrite(redPin, brightness);
  }
  }
  break;
  
  default:
  Serial.println("other button pressed");
break;
}

  Serial.println(myCom);
  analogWrite(redPin, red);
  analogWrite(greenPin, blue);
  analogWrite(bluePin, green);


// pause so it doesn't read it many time
delay(500);
IR.resume(); // start reading again);

}
