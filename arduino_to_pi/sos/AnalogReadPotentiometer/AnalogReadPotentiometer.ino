
int myVoltPin=A2;
int readVal;
float V2;
int delayTime=250;
int bluePin=9;
int yellowPin=7;
int greenPin=5;
int danger=4;


void setup() {
  // put your setup code here, to run once:

Serial.begin(9600);
pinMode(myVoltPin, INPUT);
pinMode(bluePin, OUTPUT);
pinMode(yellowPin, OUTPUT);
pinMode(greenPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
readVal=analogRead(myVoltPin);
V2 = (5./1023.)*readVal;         
Serial.println(V2); 
if (V2>4) {
  digitalWrite(bluePin, HIGH);
}
if (V2<4) {
  digitalWrite(bluePin, LOW);
}
if (V2>2 && V2<4) {
  digitalWrite(greenPin, HIGH);
}
if (V2<2 || V2>4) {
  digitalWrite(greenPin, LOW);
}
if (V2<2) {
  digitalWrite(yellowPin, HIGH);
}
if (V2>2              ) {
  digitalWrite(yellowPin, LOW);
}

delay(delayTime);

}
