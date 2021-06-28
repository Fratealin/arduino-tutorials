#include <TimerOne.h>
int blue = 9;
int red = 10;


String ledStatus = "OFF";
void setup() {
  // put your setup code here, to run once:
pinMode(blue, OUTPUT);
pinMode(red, OUTPUT);
// define software interupt
Timer1.initialize(250000); // runs interrupt function once a second
Timer1.attachInterrupt(BlinkRed);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(blue, HIGH);
  delay(750);
  digitalWrite(blue,LOW);
  delay(750);
}

void BlinkRed(){
  if (ledStatus=="OFF"){
    digitalWrite(red, HIGH);
    ledStatus = "ON";
    return;
  }
  else{
    digitalWrite(red, LOW);
    ledStatus = "OFF";
  }
}
