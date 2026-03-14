#include <Arduino.h>
#include "read_fsr.h"

const int sensorPin = 6; 
const int sensorPin_2 = 5;
double old_force = -1;

void setup() {
  Serial.begin(115200); 
  analogReadResolution(12);
}

//This function takes the pin of the FSR sensor
//and returns the 
double Read_FSR(const int sensor_pin) {
  int rawADC = analogRead(sensor_pin);
  
  // double currentX = (rawADC * 3.3) / 4095.0;

  double currentX = (rawADC * 3.3);

  //double pressure = interpolate(currentX);

  return interpolate(currentX);
}

void loop() {
  double force = Read_FSR(sensorPin);

  double force_2 = Read_FSR(sensorPin_2);

  double force_total = force + force_2;

  Serial.print("V | force: "); 
  Serial.println(force_total);

  delay(100);
}