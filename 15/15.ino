int potPin = A1;
int potVal;
float LEDVal;
int p = 100;
int yPin =6;
int rPin =9;
void setup() {
  // put your setup code here, to run once:
  pinMode(potPin, INPUT);

pinMode(yPin, OUTPUT);
pinMode(rPin, OUTPUT);
Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

potVal=analogRead(potPin);
LEDVal=(255./1023.)*potVal;
Serial.println(LEDVal);

  
  for (int i = 0; i <=4*LEDVal/255; i++) {
analogWrite(rPin, 255);
delay(p);

analogWrite(rPin, 0);

delay(p);

  }

  for (int i = 0; i <=4*(255-LEDVal)/255; i++) {
analogWrite(yPin, 255);
delay(p);

analogWrite(yPin, 0);

delay(p);

  }
}
