int latchPin =11; // set low then send data
int clockPin = 9; // to synchronize with Arduino
int dataPin = 12; // send data here


//declare hex number
byte LEDtop = 0b11000000;
byte LEDbottom = 0b00000011;
byte LEDs =LEDtop;

boolean down = true;

int dt = 500;

void setup() {
  // put your setup code here, to run once:
pinMode(latchPin, OUTPUT);
pinMode(dataPin, OUTPUT);
pinMode(clockPin, OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

// open latchPin to send data to dataPin
digitalWrite(latchPin, LOW);
//Send data and synchronise with clockPin
shiftOut(dataPin, clockPin, LSBFIRST, LEDs); // LSBFIRST - Least Significant Bit First
// close latchPin
digitalWrite(latchPin, HIGH);

if (down==true){
  // logical shift right
 shiftRight();
  }
  
  else{
   shiftLeft();
}
delay(dt);
}

void shiftRight(){
  Serial.println(LEDs);
  LEDs/=2;
  if (LEDs<=0b00000000){
    // change direction
    down= false;
    LEDs=LEDbottom;
}
}

void shiftLeft(){
   LEDs*=2;
      Serial.println(LEDs);

  if (LEDs<=0){
    down = true;
    LEDs=LEDtop;
  }
}
