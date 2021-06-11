// download library for DHT humidity sensor
// https://www.arduinolibraries.info/libraries/dht-sensor-library
// save to Arduino libraries folder
#include "DHT.h"
#define Type DHT11
int sensePin = 2;
DHT HT(sensePin, DHT11);
float humidity;
float tempC;
float tempF;
int setupT = 500;
int dT = 1000;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  HT.begin();
  delay(setupT);
}

void loop() {
  // put your main code here, to run repeatedly:
  humidity = HT.readHumidity();
  tempC = HT.readTemperature();
  tempF = HT.readTemperature(true);

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print(" Temperature (C): ");
  Serial.print(tempC);
  Serial.print(" Temperature (F): ");
  Serial.println(tempF);
  delay(dT);
}
