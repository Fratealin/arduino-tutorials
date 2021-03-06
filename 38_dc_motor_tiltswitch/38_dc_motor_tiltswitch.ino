// motor controller
int speedPin=5; // pin1 on chip - EN1
int dir1=4; // pin2 on chip - IN1
int dir2=3; // pin7 on chip - IN2
int mSpeed=255;             // 100 - 255
boolean engineStarted = false;

int tiltPin=13                           ;
int tiltVal=0;

void setup() {
  // put your setup code here, to run once:
pinMode(speedPin, OUTPUT);
pinMode(dir1, OUTPUT);
pinMode(dir2, OUTPUT);

pinMode(tiltPin, INPUT);
digitalWrite(tiltPin, HIGH); // uses internal resistor

Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  tiltVal = digitalRead(tiltPin);

setDirection();
while(tiltVal==0){
    tiltVal = digitalRead(tiltPin);

if (!engineStarted){
kickStart();
engineStarted = true;
}
keepRunning();
}
engineStarted = false;
 analogWrite(speedPin,0  );
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
  analogWrite(speedPin,150  );
delay(5);
}

void checkTilt(){
  
  
}
