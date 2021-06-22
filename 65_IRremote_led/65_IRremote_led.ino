#include <IRremote.h>
int IRpin=11;
// Create IRremote object
IRrecv IR(IRpin);
// Put signal from IR sensor to cmd
decode_results cmd;

//byte remoteOn=0xFFA25D;
String myCom;

int redPin=9;
boolean on=false;
int brightness=255;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
IR.enableIRIn();
pinMode(redPin, OUTPUT);
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
  brightness=255;
  on= true;
}
else if (on){
  myCom="lightoff";
  //Serial.println(myCom);
  brightness=0;
  //analogWrite(redPin, 0);
  on= false;
}
break;

case 0xFF629D:
  myCom="up";
  brightness+=50;
  if (brightness>255){
    brightness=255;
    //analogWrite(redPin, brightness);
  }
break;

case 0xFFA857:
  myCom="down";
  //Serial.println(myCom);
  brightness-=100;
  if (brightness<25){
    brightness=25;
    //analogWrite(redPin, brightness);
  }
  break;
  
  default:
  Serial.println("other button pressed");
break;
}

  Serial.println(brightness);
  Serial.println(myCom);
  analogWrite(redPin, brightness);


// pause so it doesn't read it many time
delay(1000);
IR.resume(); // start reading again);

}
