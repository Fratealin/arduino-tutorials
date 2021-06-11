// get average of five readings to improve accuracy

int triggerPin = 12;
int echoPin=11;
int pingTravelTime;
int delayT1=10;
int delayT2=100;
int delayT3=1000;
float distance; // in cm
int arrayLength = 5;
float distances[5];
float sum=0;
float velocity = 340; // in m/s
int closeDistance=200;

int bluePin=13;
// Load library for lcd
#include <LiquidCrystal.h>
int rs=4;
int en=5;
int d4=6;
int d5=7;
int d6=8;
int d7=9;
// instantiate lcd object
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int buttonPin=2;
int buttonValue;
int oldValue;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(triggerPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(bluePin, OUTPUT);

lcd.begin(16,2); // size

pinMode(buttonPin, INPUT);
digitalWrite(buttonPin, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:

if (checkButton()==0){
  for (int i=0; i <arrayLength; i++){  
sendPulse();
calculateDistance();
sum+=distance;
displayDistance();
delay(delayT3);
}
  // calculate average
  distance=sum/arrayLength;
  sum=0;
  // display distance
  displayDistance();

delay(delayT2);
}
}

int checkButton(){
  buttonValue=digitalRead(buttonPin);
  Serial.print("Your Button is: ");
  Serial.println(buttonValue);
  if(buttonValue==0 && buttonValue!=oldValue){
      Serial.println("new");
  oldValue=buttonValue;
  return 0;

  }
  else{

    oldValue=buttonValue;
    return 1;
  }
}


void sendPulse(){
  digitalWrite(triggerPin, LOW);
delayMicroseconds(delayT1);
digitalWrite(triggerPin, HIGH);
delayMicroseconds(delayT1);
digitalWrite(triggerPin, LOW); // launches sound wave.
digitalWrite(bluePin, HIGH);
// echoPin goes high until sound wave returns
pingTravelTime = pulseIn(echoPin, HIGH); // measures how long echoPin is high
digitalWrite(bluePin, LOW);
}

void calculateDistance(){
  distance= velocity*100.*(pingTravelTime/2./1000000.);
}

void displayDistance(){
Serial.print("distance ");
Serial.println(distance);
lcd.clear();
lcd.setCursor(0,0);
lcd.print(distance);
lcd.print( " cm");
}
