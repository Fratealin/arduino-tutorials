int bluePin = 8;
int greenPin = 7;
int tiltPin=13                           ;
int tiltVal;
int buzzPin = 5;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(bluePin, OUTPUT);
pinMode(greenPin, OUTPUT);
pinMode(buzzPin, OUTPUT);
pinMode(tiltPin, INPUT);

digitalWrite(tiltPin, HIGH); // uses internal resistor
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
tiltVal = digitalRead(tiltPin);
if(tiltVal==0){
  Serial.println(tiltVal);
  digitalWrite(greenPin, HIGH);
  digitalWrite(bluePin, LOW);
  delay(500);
  digitalWrite(greenPin, LOW);
  digitalWrite(bluePin, HIGH);
  delay(500);
  digitalWrite(buzzPin, LOW);

}
else{
  digitalWrite(greenPin, LOW);
  digitalWrite(bluePin, LOW);
  digitalWrite(buzzPin, HIGH);
}

}
