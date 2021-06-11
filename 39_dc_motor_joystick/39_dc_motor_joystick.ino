// motor controller
int speedPin=5; // pin1 on chip - EN1
int dir1=4; // pin2 on chip - IN1
int dir2=3; // pin7 on chip - IN2
int startSpeed=255;             // 100 - 255
int runSpeed;
boolean engineStarted = false;

int Xpin=A0;
int Ypin=A1;
int Spin=2;
int Xval;
float Xmiddle=507;

void setup() {
  // put your setup code here, to run once:
pinMode(speedPin, OUTPUT);
pinMode(dir1, OUTPUT);
pinMode(dir2, OUTPUT);

pinMode(Xpin,INPUT);
pinMode(Ypin,INPUT);
pinMode(Spin,INPUT);

Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Xval=analogRead(Xpin);

while(0==0){
  Xval=analogRead(Xpin);
  
  if (Xval>=Xmiddle){
    setRight();

  runSpeed = (Xval-Xmiddle)/(1023.-Xmiddle)*255.;
  Serial.println(runSpeed);
}
else{
  setLeft();
  runSpeed = (Xmiddle-Xval)/(Xmiddle)*255.;
  Serial.println(runSpeed);
}

if (!engineStarted){
kickStart();
engineStarted = true;
}

keepRunning();

}
// Arduino is tilted so switch off
engineStarted = false;
}

void setRight(){
  digitalWrite(dir1, LOW);
  digitalWrite(dir2, HIGH); // have to be opposite
}
void setLeft(){
  digitalWrite(dir1, HIGH);
  digitalWrite(dir2, LOW); // have to be opposite
}
void kickStart(){
  analogWrite(speedPin, startSpeed);
delay(75); // kick start
}

void keepRunning(){
  analogWrite(speedPin,runSpeed  );
delay(5);
}
