#include "MQ135.h"
#include <Arduino.h>

#define MQ135_PIN 35

void initializeMQ135Sensor() {
  Serial.println("Inicializando o sensor MQ-135...");
}

float readMQ135Sensor() {
  int gasValue = analogRead(MQ135_PIN);
  float voltage = gasValue * (5.0 / 1024.0);
  float ppm = voltage * 10.0;
  return ppm;
}