int potPin = A1;
int gPin=6;
int potVal;
float LEDVal;
int delayTime=500;


void setup() {
  // put your setup code here, to run once:
pinMode(potPin, INPUT);
pinMode(gPin, OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
potVal=analogRead(potPin);
LEDVal=(255./1023.)*potVal;
analogWrite(gPin, LEDVal);
Serial.println(LEDVal);
int d = delayTime*(255-LEDVal)/255+50;
delay(d);
analogWrite(gPin, 0);
delay(d);

}
