int latchPin =11; // set low then send data
int clockPin = 9; // to synchronize with Arduino
int dataPin = 12; // send data here


//declare hex number
byte LEDs =0x8;
byte LEDbytes[] = {0b10000000, 0b01000000, 0b00100000,0b00010000, 0b00001000, 0b00000100, 0b00000010, 0b00000001, 0b00000000};
int size = sizeof(LEDbytes) / sizeof(byte);

int dt = 100;

void setup() {
  // put your setup code here, to run once:
pinMode(latchPin, OUTPUT);
pinMode(dataPin, OUTPUT);
pinMode(clockPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  for(int i=0;i<size;i++){
// open latchPin to send data to dataPin
digitalWrite(latchPin, LOW);
//Send data and synchronise with clockPin
shiftOut(dataPin, clockPin, LSBFIRST, LEDbytes[i]); // LSBFIRST - Least Significant Bit First
// close latchPin
digitalWrite(latchPin, HIGH);
//LEDs-=2;
delay(dt);
  }
}
