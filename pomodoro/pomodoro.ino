int redPin =  8;
int greenPin = 9;
int bluePin = 10;
int buzzPin = 6;
float LEDVal;
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
  
int seconds = 15;
for (int i = 0; i <= seconds; i++) {
delay(50);
analogWrite(redPin,0);
    analogWrite(greenPin,0);
      analogWrite(bluePin,255);

    delay(50);
    analogWrite(redPin,0);
    analogWrite(greenPin,0);
      analogWrite(bluePin,0);
}

  
  analogWrite(redPin,255);
    analogWrite(greenPin,0);
      analogWrite(bluePin,255);

    digitalWrite(buzzPin, HIGH);
    
    potVal=analogRead(potPin);
    LEDVal=(255./1023.)*potVal;
    // wait for switch off
    while (LEDVal >2){
      potVal=analogRead(potPin);
    LEDVal=(255./1023.)*potVal;

}
//switch off
analogWrite(redPin,0);
    analogWrite(greenPin,0);
      analogWrite(bluePin,0);

    digitalWrite(buzzPin, LOW);

// wait for restart
    while (LEDVal <2){
      potVal=analogRead(potPin);
    LEDVal=(255./1023.)*potVal;

}
  }
