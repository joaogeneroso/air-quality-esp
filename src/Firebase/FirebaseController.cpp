#include "FirebaseController.h"
#include <IOXhop_FirebaseESP32.h>
#include <../src/Keys/credentials.h>
#include <WiFi.h>

void initializeFirebase() {
  Firebase.begin(DATABASE_URL, API_KEY);
  Serial.println("Firebase inicializado");
}

void sendFirebaseData(float temperature, float humidity, float dustDensity, float gasLevel) {
  Firebase.setFloat("/dht22/temperature", temperature);
  Firebase.setFloat("/dht22/humidity", humidity);
  Firebase.setFloat("/dustSensor/density", dustDensity);
  Firebase.setFloat("/mq5/gasLevel", gasLevel);
  Serial.println("Dados enviados ao Firebase");
}