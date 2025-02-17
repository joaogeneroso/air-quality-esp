#include <Arduino.h>
#include <WiFi.h>

#include <Firebase/FirebaseController.h>

#include <Sensors/GP2Y1010AU0F.h>
#include <Sensors/DHT22.h>
#include <Sensors/MQ135.h>

#include <Keys/credentials.h>

void connectToWiFi() {
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectando ao WiFi...");
  }
  Serial.println("Conectado ao WiFi");
}

void setup() {
  Serial.begin(115200);

  connectToWiFi();
  initializeFirebase();

  initializeDHT22();
  initializeDustSensor();
  initializeMQ135Sensor();
}

void loop() {
  float temperature = readTemperature();
  float humidity = readHumidity();
  float dustDensity = readDustSensor();
  float gasLevel = readMQ135Sensor();
  
  sendFirebaseData(temperature, humidity, dustDensity, gasLevel);

  delay(60000);
}