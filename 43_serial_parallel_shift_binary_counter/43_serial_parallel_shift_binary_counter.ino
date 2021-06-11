int latchPin =11; // set low then send data
int clockPin = 9; // to synchronize with Arduino
int dataPin = 12; // send data here


//declare hex number
byte LEDs =0x00;


int dt = 250;

void setup() {
  // put your setup code here, to run once:
pinMode(latchPin, OUTPUT);
pinMode(dataPin, OUTPUT);
pinMode(clockPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
// open latchPin to send data to dataPin
digitalWrite(latchPin, LOW);
//Send data and synchronise with clockPin
shiftOut(dataPin, clockPin, LSBFIRST, LEDs); // LSBFIRST - Least Significant Bit First
// close latchPin
digitalWrite(latchPin, HIGH);
LEDs+=1;
delay(dt);
  
}
