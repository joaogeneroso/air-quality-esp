#include "GP2Y1010AU0F.h"
#include <Arduino.h>

#define LED_PIN 27
#define DUST_PIN 34

void initializeDustSensor() {
  pinMode(LED_PIN, OUTPUT);
}

float readDustSensor() {
  digitalWrite(LED_PIN, LOW);
  delayMicroseconds(280);
  
  int dustValue = analogRead(DUST_PIN);  
  digitalWrite(LED_PIN, HIGH);
  
  float voltage = dustValue * (5.0 / 1024.0);
  float dustDensity = (voltage - 0.1) * 1000.0 / 5.0;
  
  return dustDensity;
}