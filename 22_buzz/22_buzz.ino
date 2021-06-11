int potVal;
int buzzPin=6;
int dt=2000;
int potPin = A1;


void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600); 
pinMode(potPin, INPUT);
pinMode(buzzPin,OUTPUT); 
}

void loop() {
  // put your main code here, to run repeatedly:
potVal=analogRead(potPin); 
  while (potVal>1000) {
    digitalWrite(buzzPin, HIGH);
    potVal=analogRead(potPin); 

}
    digitalWrite(buzzPin, LOW);

}
