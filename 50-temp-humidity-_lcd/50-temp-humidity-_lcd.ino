// download library for DHT humidity sensor
// https://www.arduinolibraries.info/libraries/dht-sensor-library
// and https://www.arduinolibraries.info/libraries/adafruit-unified-sensor
// save to Arduino libraries folder
#include "DHT.h"
#define Type DHT11
int sensePin = 2;
DHT HT(sensePin, DHT11);
float humidity;
float tempC;
float tempF;
int setupT = 500;
int dT = 500;

// Load library for lcd
#include <LiquidCrystal.h>
int rs=7;
int en=8;
int d4=9;
int d5=10;
int d6=11;
int d7=12;
// instantiate lcd object
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  HT.begin();
  lcd.begin(16,2); // size
  delay(setupT);
}

void loop() {
  // put your main code here, to run repeatedly:
  getReadings();
  showReadings();
  delay(dT);
}

void getReadings(){
  humidity = HT.readHumidity();
  tempC = HT.readTemperature();
  tempF = HT.readTemperature(true);
}

void showReadings(){
  lcd.setCursor(0,0);
  lcd.print("Humidity: ");
  lcd.print(humidity);
  
  lcd.setCursor(0,1);
  lcd.print("Temp (C): ");
  lcd.print(tempC);
  }
