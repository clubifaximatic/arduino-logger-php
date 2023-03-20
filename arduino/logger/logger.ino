
#include  <SparkFun_SCD30_Arduino_Library.h>
#include <Wire.h>

#include "Constants.h"
#include "CO2Sensor.h"
#include "O2Sensor.h"

SCD30 airSensor;
Sensor *sensors[INPUTS_SIZE];

unsigned long nextRead = 0;
unsigned long nextWrite = WRITE_PERIOD;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  airSensor.begin();

  // create all sensors
  initializeAllSensors();

  // start Ethernet connection
  startEthernet();
}

int i = 0;

void loop() {  
  unsigned long now = millis();

  // read when needed
  if (nextRead < now) {
    readAllSensors();
    nextRead += READ_PERIOD;
  }

  // read when needed
  if (nextWrite < now) {
    String allValues = allAverages();
    Serial.println(allValues);
    //sendHttpRequest(allValues);

    clearAllSensors();
    nextWrite += WRITE_PERIOD;
  }

  // read the Internet
  readNetwork();
}
