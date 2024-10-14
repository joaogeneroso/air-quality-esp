#include "DHT22.h"
#include <DHT.h>

#define DHTPIN 26
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

void initializeDHT22() {
  dht.begin();
}

float readTemperature() {
  float temperature = dht.readTemperature();
  if (isnan(temperature)) { return 0; }
  return temperature;
}

float readHumidity() {
  float humidity = dht.readHumidity();
  if (isnan(humidity)) { return 0; }
  return humidity;
}