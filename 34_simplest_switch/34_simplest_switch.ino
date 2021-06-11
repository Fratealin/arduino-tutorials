int buttonPin = 4;
int buttonValue;
int dt = 25;
int green = 6;
int buzzPin = 3;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(green, OUTPUT);
  pinMode(buttonPin, INPUT);
  digitalWrite(buttonPin, HIGH); // write to input pin. Use the internal pull up resistor switch
  pinMode(buzzPin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  buttonValue = digitalRead(buttonPin);
  //Serial.print("Your Button is: ");
  //Serial.println(buttonValue);
  
  if(buttonValue==0){
    digitalWrite(green, HIGH);
    digitalWrite(buzzPin, HIGH);
  }
  else{
      digitalWrite(green, LOW);
      digitalWrite(buzzPin, LOW);
  }
  delay(dt);


}
