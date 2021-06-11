// Load library for lcd
#include <LiquidCrystal.h>
int rs=7;
int en=8;
int d4=9;
int d5=10;
int d6=11;
int d7=12;


int number1;
int number2;
int answer;
String op;
// instantiate lcd object
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // put your setup code here, to run once:
lcd.begin(16,2); // size
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
getInput();
calculate();
showAnswer();
delay(2000);
lcd.clear();
}

void getInput(){
  lcd.setCursor(0,0);
lcd.print("Enter number");
while (Serial.available() == 0) {  
  }
  number1 = Serial.parseInt();
  lcd.clear();
lcd.print("Enter operator");
while (Serial.available() == 0) {  
  }
  op = Serial.readString();
  lcd.clear();
  lcd.print("Enter 2nd number");

while (Serial.available() == 0) {  
  }
  number2 = Serial.parseInt();
  lcd.clear();
}

void calculate(){
  if(op=="+"){
    Serial.println("plus");
    answer = number1+number2;
  }
  else if (op=="-"){
    answer = number1-number2;
  }
  else if (op=="/"){
    answer = number1/number2;
  }
  else if (op=="*"){
    answer = number1*number2;
  }
}
void showAnswer(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(number1);
  lcd.print(" ");
  lcd.print(op);
  lcd.print(" ");
  lcd.print(number2);
  lcd.print(" =");
  lcd.setCursor(0,1);
  lcd.print(answer);
  Serial.println(answer);

}
