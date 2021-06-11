int buttonPin=12;
int buttonNew;
int buttonOld =1;

int downPin=11;
int downNew;
int downOld =1;
boolean downOn = false;
int msg;
int green = 9; 
boolean on = false; 
int greenLevel = 0;

void setup() {
  // put your setup code here, to run once:

Serial.begin(9600);
pinMode(buttonPin, INPUT);
pinMode(green, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
/*

downNew=digitalRead(downPin);

  delay(100);
  if (downOld==1 && downNew==0){
    if (greenLevel>0){
      greenLevel-=50;
    }
    // just gone down
    if (downOn==false){
      msg = 0;
    analogWrite(green, greenLevel);
    downOn = true;
    }
    else if (downOn==true){
      analogWrite(green, greenLevel);
    downOn = false;
  msg=1;
    }
  }
      downOld = downNew; 
      */
downOld = myButtonFunction(downNew, downPin, downOld, downOn, "down");


/*
buttonNew=digitalRead(buttonPin);

  delay(100);
  if (buttonOld==1 && buttonNew==0){
    if (greenLevel<250){
      greenLevel+=50;
    }
    // just gone down
    if (on==false){
      msg = 0;
    analogWrite(green, greenLevel);
    on = true;
    }
    else if (on==true){
      analogWrite(green, greenLevel);
    on = false;
  msg=1;
    }
  }
      buttonOld = buttonNew; 
 Serial.println(greenLevel);  //Sending the data over serial to Raspberry pi
*/
buttonOld = myButtonFunction(buttonNew, buttonPin, buttonOld, on, "up");
 Serial.println(greenLevel);  //Sending the data over serial to Raspberry pi

}


int myButtonFunction(int thisNew, int thisPin, int thisOld, boolean thisOn, String type){
  thisNew=digitalRead(thisPin);

  delay(100);
  if (thisOld==1 && thisNew==0){
    if (type == "up"){
    if (greenLevel<250){
      greenLevel+=25;
    }
    }
    else{
      if (greenLevel>0){
      greenLevel-=25;
    }
    }
    // just gone down
    if (thisOn==false){
      msg = 0;
    analogWrite(green, greenLevel);
    thisOn = true;
    }
    else if (thisOn==true){
      analogWrite(green, greenLevel);
    thisOn = false;
    }
  }
      thisOld = thisNew;
      return thisOld;
}
