#include "CO2Sensor.h"
#include "O2Sensor.h"

Sensor *sensors[INPUTS_SIZE];

void initializeAllSensors() {
  int pos = 0;
  
  // initialize CO2 sensors
  for (int i = 0; i < CO2_INPUTS_SIZE; i++) {
    Serial.println(CO2_INPUTS[i]);
    sensors[pos++] = new CO2Sensor(CO2_INPUTS[i]);
  }

  // initialize O2 sensors
  for (int i = 0; i < O2_INPUTS_SIZE; i++) {
    Serial.println(O2_INPUTS[i]);
    sensors[pos++] = new O2Sensor(O2_INPUTS[i]);
  }
}


void readAllSensors() {
  for (int i = 0; i < INPUTS_SIZE; i++) {
    sensors[i]->read();
  }
}

String allAverages() {
  String payload = "";

  for (int i = 0; i < INPUTS_SIZE; i++) {
    payload += sensors[i]->average();
    payload += ",";
  }

  return payload;
}


void clearAllSensors() {
  for (int i = 0; i < INPUTS_SIZE; i++) {
    sensors[i]->clear();
  }
}
