// motor controller
int speedPin=5; // pin1 on chip - EN1
int dir1=4; // pin2 on chip - IN1
int dir2=3; // pin7 on chip - IN2
int mSpeed=255;             // 100 - 255
boolean engineStarted = false;

void setup() {
  // put your setup code here, to run once:
pinMode(speedPin, OUTPUT);
pinMode(dir1, OUTPUT);
pinMode(dir2, OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
setDirection();
while (!engineStarted){
kickStart();
engineStarted = true;
}
keepRunning();
}

void setDirection(){
  digitalWrite(dir1, LOW);
  digitalWrite(dir2, HIGH); // have to be opposite
}
void kickStart(){
  analogWrite(speedPin, mSpeed);
delay(75); // kick start
}

void keepRunning(){
  analogWrite(speedPin,100);
delay(5000);
}
