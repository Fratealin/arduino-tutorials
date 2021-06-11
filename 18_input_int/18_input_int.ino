int numBlinks = 20;
String msg="How many blinks:";
String msg2 = "Your number is: ";
int j;
int bt=500;
int redPin =12;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(redPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

Serial.println("Length of pause (ms)");
while (Serial.available() ==0) {
}
bt = Serial.parseInt();

Serial.print(numBlinks);
for(j=1; j<=numBlinks; j=j+1){
  digitalWrite(redPin, HIGH);
  delay(bt/2);
  digitalWrite(redPin, LOW);
  delay(bt);
  Serial.print(j);
  Serial.print(", ");  
}

Serial.println();
}
