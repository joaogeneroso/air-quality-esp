#include "MQ5.h"
#include <Arduino.h>

#define MQ5_PIN 35

void initializeMQ5Sensor() {
  Serial.println("Conectado ao WiFi");
}

float readMQ5Sensor() {
  int gasValue = analogRead(MQ5_PIN);
  float voltage = gasValue * (5.0 / 1024.0);  
  return voltage;
}