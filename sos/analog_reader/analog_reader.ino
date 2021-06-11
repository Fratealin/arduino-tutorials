// reads the voltage

int readPin = A3;
int readVal;
float V2=0.                                                                                                                             ;
int delayTime=500;

void setup() {
  // put your setup code here, to run once:
pinMode(readPin, INPUT);
// Start serial monitor
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
readVal = analogRead(readPin);
// reads a scaled value between 0 and 1023
V2 = (5./1023.)*readVal;         
Serial.println(V2);
delay(delayTime);
}
