int red = 13;
int blue = 11;
int white = 9;
int unit = 150;

void setup() {
  // put your setup code here, to run once:
pinMode(13, OUTPUT);
pinMode(11, OUTPUT);
pinMode(9, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:


int c = red;
blink(1, unit);
blink(3, unit);
blink(1, unit);
delay(6);




  unit = 150;
for (int i = 0; i <100; i++){
  digitalWrite(red, HIGH);
  delay(unit*1);

  digitalWrite(c, LOW);
    delay(unit*1);

    digitalWrite(white, HIGH);
  delay(unit*1);

  digitalWrite(white, LOW);
    delay(unit*1);

    digitalWrite(blue, HIGH);
  delay(unit*1);

  digitalWrite(blue, LOW);
    delay(unit*1);

    digitalWrite(white, HIGH);
  delay(unit*1);

  digitalWrite(white, LOW);
    delay(unit*1);

 unit = unit*.95;

}

unit = 150;
c = red;
blink(1, unit);
blink(3, unit);
blink(1, unit);
delay(6);
}

void blink(int f, int unit){
for (int i = 0; i <3; i++){
  digitalWrite(red, HIGH);
  digitalWrite(blue, HIGH);
  digitalWrite(white, HIGH);
  delay(unit*f);

  digitalWrite(red, LOW);
    digitalWrite(blue, LOW);
    digitalWrite(white, LOW);
    delay(unit*1);

}
  delay(unit*2);
}
