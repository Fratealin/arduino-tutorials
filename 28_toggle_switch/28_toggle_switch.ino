int buttonPin=12;
int buttonNew;
int buttonOld =1;
int msg;
int green = 9;
boolean on = false; 
)

void setup() {
  // put your setup code here, to run once:

Serial.begin(9600);
pinMode(buttonPin, INPUT);
pinMode(green, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

buttonNew=digitalRead(buttonPin);

  delay(100);
  if (buttonOld==1 && buttonNew==0){
    // just gone down
    if (on==false){
      msg = 0;
    digitalWrite(green, HIGH);
    on = true;
    }
    else if (on==true){
      digitalWrite(green, LOW);
    on = false;
  msg=1;
    }
  }
      buttonOld = buttonNew; 
 Serial.println(msg);  //Sending the data over serial to Raspberry pi

}
