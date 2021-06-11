int buzzPin=6;
int buzzTime=1;
int delayTime=3000;
int potVal;
float normalVal;
int potPin = A1;

 
void setup() {
  // put your setup code here, to run once:
pinMode(buzzPin, OUTPUT);
pinMode(potPin, INPUT);
Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  
  potVal=analogRead(potPin);
  normalVal = (9940./1023.)*potVal+2;
  Serial.println(normalVal);
   
  analogWrite(buzzPin, 255);
  delayMicroseconds(normalVal);
  analogWrite(buzzPin, LOW);
  delayMicroseconds(normalVal);

}
