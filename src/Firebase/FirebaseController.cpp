#include "FirebaseController.h"
#include <IOXhop_FirebaseESP32.h>
#include <../src/Keys/credentials.h>
#include <WiFi.h>
#include <NTPClient.h>
#include <WiFiUdp.h>

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org", -3 * 3600, 60000);

void initializeFirebase() {
  Firebase.begin(DATABASE_URL, API_KEY);
  Serial.println("Firebase inicializado");
  timeClient.begin();
}

void sendFirebaseData(float temperature, float humidity, float dustDensity, float gasLevel) {
  timeClient.update();
  String formattedTime = timeClient.getFormattedTime();

  Firebase.setFloat("/dht22/temperature", temperature);
  Firebase.setFloat("/dht22/humidity", humidity);
  Firebase.setFloat("/dustSensor/density", dustDensity);
  Firebase.setFloat("/mq135/gasLevel", gasLevel);
  Firebase.setString("/lastUpdate", formattedTime);

  Serial.println("Dados enviados ao Firebase");
}