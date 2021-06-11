int redPin =  8;
int greenPin = 9;
int bluePin = 10;
int buzzPin = 6;
int waitTime;
String msg = "How long till alarm? ";

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
waitTime = Serial.parseInt();
for (int i = 0; i <= waitTime; i++) {
delay(950);
analogWrite(redPin,0);
    analogWrite(greenPin,0);
      analogWrite(bluePin,255);

    delay(50);
    analogWrite(redPin,0);
    analogWrite(greenPin,0);
      analogWrite(bluePin,0);
}

  for (int i = 0; i <= 4; i++) {

  analogWrite(redPin,255);
    analogWrite(greenPin,0);
      analogWrite(bluePin,255);

    digitalWrite(buzzPin, HIGH);
    delay(250);
    digitalWrite(buzzPin,LOW);
    analogWrite(redPin,0);
    analogWrite(greenPin,0);
      analogWrite(bluePin,255);
      delay(250);
  }
    analogWrite(redPin,0);
    analogWrite(greenPin,0);
      analogWrite(bluePin,0);
  }
