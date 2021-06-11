int buttonPin=12;
int buttonNew;
int buttonOld =1;
int msg;
int d=250;
int buzzPin = 5;
int blue = 6;
int green = 9;
boolean switchedOn = false;
int count = 0;
boolean on = false; 
boolean stop = false; // for stopping alarm

int waitTime;

float LEDVal;
int incoming_state = 0;  //Initializes a variable for storing the incoming data from Arduino
int previous_state = 0;
boolean newData = false;

void setup() {
  // put your setup code here, to run once:

  
  
Serial.begin(9600);
pinMode(buttonPin, INPUT);
pinMode(blue, OUTPUT);
pinMode(green, OUTPUT);
pinMode(buzzPin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
// Check it's working
    if (!switchedOn){
    digitalWrite(blue, HIGH);  
    delay(50);
    digitalWrite(blue, LOW);
    switchedOn = true;
    }

  // if message from raspberry
if (Serial.available() > 0){  //Looking for incoming data
    incoming_state = Serial.read() - '0';  //Reading the data
    if(incoming_state != previous_state){
      newData = true;

    if (incoming_state == 9){
      // repeat 20 times unless interrupted by button
      count = 0;
      
          while (not stop){
          tone(buzzPin, 450, 100);
          digitalWrite(blue, incoming_state);  //Making the LED light up or down
          delay(100);
          noTone(buzzPin);
          //digitalWrite(buzzPin, incoming_state);
          digitalWrite(blue, 0);  //Making the LED light up or down
          delay(500);
          stop = toggleButton();
          count ++;
          if (count>=20){
            stop = true;
          }

          }
          stop = false;
    }
    

    else if (incoming_state >= 2){
          for (int i =0;i<incoming_state; i++){
          tone(buzzPin, 450, 100);
          digitalWrite(blue, incoming_state);  //Making the LED light up or down
          delay(100);
          noTone(buzzPin);
          //digitalWrite(buzzPin, incoming_state);
          digitalWrite(blue, 0);  //Making the LED light up or down
          delay(100);

          }
    }
     else {
      digitalWrite(blue, incoming_state);  //Making the LED light up or down
    digitalWrite(green, incoming_state);
    digitalWrite(buzzPin, incoming_state);
    delay(100);
     }
     previous_state = incoming_state;
incoming_state = 0;
}    
}


      
    
  

toggleButton(); 
 Serial.println(msg);  //Sending the data over serial to Raspberry pi

}

int toggleButton(){
  buttonNew=digitalRead(buttonPin);
  if (buttonOld==1 && buttonNew==0){
    stop = true;
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
      return stop;
      
  
}
