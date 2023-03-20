
#include  <SparkFun_SCD30_Arduino_Library.h>
#include <Wire.h>


#include "constants.h"
#include "CO2Sensor.h"
#include "O2Sensor.h"

SCD30 airSensor;

CO2Sensor *co2Sensors[CO2_INPUTS_SIZE];
O2Sensor *o2Sensors[O2_INPUTS_SIZE];

unsigned long nextRead = 0;
unsigned long nextWrite = WRITE_PERIOD;

void setup() {
  Serial.begin(9600);

  Wire.begin();
  airSensor.begin();

  initializeAll();

  startEthernet();
}

int i = 0;

void loop() {

  // read the Internet
  readNetwork();
  
  unsigned long now = millis();

  if (nextRead < now + READ_PERIOD) {
    readAll();
    nextRead += READ_PERIOD;
  }

  if (nextWrite < now + WRITE_PERIOD) {
    String allValues = allAverages();
    Serial.println(allValues);
    sendHttpRequest(allValues);

    clearAll();
    nextWrite += WRITE_PERIOD;
  }
}

void initializeAll() {
  // initialize CO2 sensors
  for (int i = 0; i < CO2_INPUTS_SIZE; i++) {
    co2Sensors[i] = new CO2Sensor(CO2_INPUTS[i], &airSensor);
  }

  // initialize O2 sensors
  for (int i = 0; i < O2_INPUTS_SIZE; i++) {
    Serial.println(CO2_INPUTS[i]);
    o2Sensors[i] = new O2Sensor(CO2_INPUTS[i]);
  }
}

void readAll() {
  for (int i = 0; i < CO2_INPUTS_SIZE; i++) {
    co2Sensors[i]->read();
  }
  for (int i = 0; i < O2_INPUTS_SIZE; i++) {
    o2Sensors[i]->read();
  }
}

String allAverages() {
  String payload = "";
  
  for (int i = 0; i < CO2_INPUTS_SIZE; i++) {
    payload += co2Sensors[i]->average();
    payload += ",";
  }
  for (int i = 0; i < O2_INPUTS_SIZE; i++) {
    payload += o2Sensors[i]->average();
    payload += ",";
  }

  return payload;
}


void clearAll() {
  for (int i = 0; i < CO2_INPUTS_SIZE; i++) {
    co2Sensors[i]->clear();
  }
  for (int i = 0; i < O2_INPUTS_SIZE; i++) {
    o2Sensors[i]->clear();
  }
}
