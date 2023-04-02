
#include  <SparkFun_SCD30_Arduino_Library.h>
#include <Wire.h>

#include "Constants.h"

unsigned long nextBlink = 0;
unsigned long nextRead = 0;
unsigned long nextWrite = WRITE_PERIOD;

void setup() {
  Serial.begin(57600);
  Wire.begin();

//  airSensor.begin(Wire);

  // start Ethernet connection
  startEthernet();

  // create all sensors
  initializeAllSensors();
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
    sendHttpRequest(allValues);

    clearAllSensors();
    nextWrite += WRITE_PERIOD;
  }

  // blink when needed
  if (nextBlink < now) {
    blink();
    nextBlink += BLINK_PERIOD;
  }

  // read the Internet
  readNetwork();
}
