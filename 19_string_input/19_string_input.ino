int rPin = 12;
int gPin = 11;
int bPin = 10;
String msg = "What color light up? ";
String myColor;

void setup() {
  // put your setup code here, to run once:
pinMode(gPin, OUTPUT);
pinMode(rPin, OUTPUT);
pinMode(bPin, OUTPUT);
Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println(msg);
while (Serial.available()==0){
  
}
myColor = Serial.readString();
Serial.print(myColor);

if (myColor == "r"){
  Serial.print(myColor);

  Serial.print("hi");
  digitalWrite(rPin, HIGH);
  digitalWrite(gPin,LOW);
    digitalWrite(bPin, LOW);


}


if (myColor == "g"){
  digitalWrite(rPin, LOW);
  digitalWrite(gPin, HIGH);
    digitalWrite(bPin, LOW);
}

if (myColor == "b"){
  digitalWrite(rPin, LOW);
  digitalWrite(gPin, LOW);
    digitalWrite(bPin, HIGH);
}


}
