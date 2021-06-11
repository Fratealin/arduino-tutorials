int redPin =  8;
int greenPin = 9;
int bluePin = 10;
int buzzPin = 6;
String myColor;
String msg = "What Color Do You Want? ";

int potPin = A1;
int potVal;
float buzzVal;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(redPin, OUTPUT);
pinMode(greenPin, OUTPUT);
pinMode(bluePin, OUTPUT);
pinMode(buzzPin, OUTPUT);

pinMode(potPin, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println(msg);
while (Serial.available() == 0){
  
}
myColor = Serial.readString();
if (myColor == "red") {
  digitalWrite(redPin,HIGH);
    digitalWrite(greenPin,LOW);
      digitalWrite(bluePin,LOW);
}



if (myColor == "green") {
  digitalWrite(redPin,LOW);
    digitalWrite(greenPin,HIGH);
      digitalWrite(bluePin,LOW);
}
if (myColor == "blue") {
  digitalWrite(redPin,LOW);
    digitalWrite(greenPin,LOW);
      digitalWrite(bluePin,HIGH);
}
if (myColor == "off") {
  digitalWrite(redPin,LOW);
    digitalWrite(greenPin,LOW);
      digitalWrite(bluePin,LOW);
}
if (myColor == "all") {
  analogWrite(redPin,10);
    analogWrite(greenPin,10);
      analogWrite(bluePin,10);
}
if (myColor == "rg") {
  digitalWrite(redPin,HIGH);
    digitalWrite(greenPin,HIGH);
      digitalWrite(bluePin,LOW);
}
if (myColor == "rb") {
  digitalWrite(redPin,HIGH);
    digitalWrite(greenPin,LOW);
      digitalWrite(bluePin,HIGH);
}
if (myColor == "gb") {
  digitalWrite(redPin,LOW);
    digitalWrite(greenPin,HIGH);
      digitalWrite(bluePin,HIGH);
}
if (myColor == "aqua") {
  digitalWrite(redPin,LOW);
    analogWrite(greenPin,255);
      analogWrite(bluePin,50);
}
if (myColor == "brown") {
  analogWrite(redPin,150);
    analogWrite(greenPin,75);
      analogWrite(bluePin,0);
}
if (myColor == "coffee") {
  analogWrite(redPin,111);
    analogWrite(greenPin,78);
      analogWrite(bluePin,55);
}
if (myColor == "orange") {
  analogWrite(redPin,255);
    analogWrite(greenPin,69);
      analogWrite(bluePin,0);
}
if (myColor == "orange") {
  analogWrite(redPin,255);
    analogWrite(greenPin,69);
      analogWrite(bluePin,0);
}
if (myColor == "slide"){
for (int i = 0; i <= 255; i++) {
  analogWrite(redPin,i);
    analogWrite(greenPin,255-i);
      analogWrite(bluePin,255-i/2);
      delay(25);
}
}
if (myColor == "rand"){
for (int i = 0; i <= 20; i++) {
  analogWrite(redPin,random(0,255));
    analogWrite(greenPin,random(0,255));
      analogWrite(bluePin,random(0,255));
      delay(500);
}
}
if (myColor == "flash"){
for (int i = 0; i <= 20; i++) {
  analogWrite(redPin,0);
    analogWrite(greenPin,0);
      analogWrite(bluePin,255);
      delay(250);
      analogWrite(redPin,0);
    analogWrite(greenPin,0);
      analogWrite(bluePin,0);
      delay(250);
}
}
if (myColor == "buzz"){
  for (int i = 0; i <= 200; i++) {
    digitalWrite(buzzPin, HIGH);
    delay(50);
    digitalWrite(buzzPin,LOW);
    delay(1);
  }
}
}
