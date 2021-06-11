// motor controller
int speedPin=5; // pin1 on chip - EN1
int dir1=4; // pin2 on chip - IN1
int dir2=3; // pin7 on chip - IN2
int startSpeed=255;             // 100 - 255
int runSpeed = 0;
boolean engineStarted = false;


int buttonUp = 7;
int buttonUpValNew;
int buttonUpValOld = 1;

int buttonDown = 8;
int buttonDownValNew;
int buttonDownValOld = 1;

int motDir = 1;

void setup() {
  // put your setup code here, to run once:
pinMode(speedPin, OUTPUT);
pinMode(dir1, OUTPUT);
pinMode(dir2, OUTPUT);

pinMode(buttonUp, INPUT);
pinMode(buttonDown, INPUT);
digitalWrite(buttonUp, HIGH);
digitalWrite(buttonDown, HIGH);

Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonUpValNew = digitalRead(buttonUp);
  if(buttonUpValOld == 1 && buttonUpValNew == 0){
    // increase speed if up button is pressed
    runSpeed +=10;

    // Cap speed at 255
    if (runSpeed>255){
      runSpeed = 255;
    }
    // increase speed if less than 100
    else if (runSpeed<100 && runSpeed>0){
      runSpeed=100;
    }
    // stop motor if less than -100
    else if (runSpeed<0 && runSpeed>-100){
      runSpeed =0;
    }
  }
  buttonUpValOld = buttonUpValNew;

  
  buttonDownValNew = digitalRead(buttonDown);
  if(buttonDownValOld == 1 && buttonDownValNew == 0){
    // decrease speed if button pressed
    runSpeed -=10;
    // cap speed at -255
    if (runSpeed<-255){
      runSpeed = -255;
    }
    // increase speed if less than -100
    else if (runSpeed>-100 && runSpeed<0){
      runSpeed=-100;
    }
    // stop motor if less than 100
    else if (runSpeed>0 && runSpeed<100){
      runSpeed =0;
    }
  }
    buttonDownValOld = buttonDownValNew;

    // set direction
    if (runSpeed>0){
      setRight();
      analogWrite(speedPin,runSpeed  );
    }
    else if (runSpeed<0){
      setLeft();
      analogWrite(speedPin,-runSpeed  );
    }
    
Serial.println(runSpeed);
keepRunning();
}

void setRight(){
  digitalWrite(dir1, LOW);
  digitalWrite(dir2, HIGH); // have to be opposite
}
void setLeft(){
  digitalWrite(dir1, HIGH);
  digitalWrite(dir2, LOW); // have to be opposite
}

void keepRunning(){
  analogWrite(speedPin,runSpeed  );
delay(5);
}
