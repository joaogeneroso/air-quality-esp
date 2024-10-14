#ifndef FIREBASECONTROLLER_H
#define FIREBASECONTROLLER_H

void initializeFirebase();
void sendFirebaseData(float temperature, float humidity, float dustDensity, float gasLevel);

#endif