int lightPen=A0;
int lightVal;
int d=250;
int buzzPin = 5;
int blue = 6;
int green = 9;

void setup() {
  // put your setup code here, to run once:
pinMode(lightPen, INPUT);
Serial.begin(9600);
pinMode(buzzPin, OUTPUT);
pinMode(blue, OUTPUT);
pinMode(green, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
lightVal=analogRead(lightPen);
d=(15./550.)*lightVal-(200.*15./550.)+1.;
analogWrite(buzzPin, 50);
delayMicroseconds(d);
analogWrite(buzzPin, 0);
delayMicroseconds(d);

if (lightVal>500){
  analogWrite(blue, 255);
  digitalWrite(green, LOW);
}
else {
  digitalWrite(blue, LOW);
  analogWrite(green, 255);
}
Serial.println(lightVal);  
}
