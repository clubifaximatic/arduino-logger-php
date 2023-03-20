#ifndef __CO2_SENSOR_H
#define __CO2_SENSOR_H

#include <Arduino.h>
#include <SparkFun_SCD30_Arduino_Library.h>
#include <Wire.h>

#include "Constants.h"
#include "Sensor.h"

/**
 * pins CO2
 * 
 * 0 VIN
 * 1 GND
 * 2 SCL
 * 3 SDA
 * 
 * pins Multiplexer
 * 0 VIN
 * 1 GND
 * 2 SDA
 * 3 SCL
 * ...
 * 8 SDA
 * 9 SLC
 */
class CO2Sensor : public Sensor {
  private:
    uint8_t _n;
    SCD30 _airSensor;

  public:
    CO2Sensor (uint8_t n, SCD30 *airSensor);
    void read ();

  private:
    void begin();
    void select();
};

#endif

/**
 * 
 */
CO2Sensor::CO2Sensor(uint8_t n, SCD30 *airSensor) {
  //_airSensor = airSensor;
  _n = n;

  begin();
}

/**
 * 
 */
void CO2Sensor::read() {
  // select the CO2 sensor
  select();

  double value = _airSensor.getTemperature();

  Serial.print("CO2 ");
  Serial.print(_n);
  Serial.print(" read: ");
  Serial.println(value);
  
  _accumulator.increment(value);
}

/**
 * 
 */
void CO2Sensor::select() {
  if (_n > 7) return;

  Wire.beginTransmission(TCAADDR);
  Wire.write(1 << _n);
  bool r = Wire.endTransmission();
  Serial.print("select ");
  Serial.print(_n);
  Serial.print(" ");
  Serial.println(r);
}

void CO2Sensor::begin() {
  int n = 0;
  select();
  _airSensor.begin(Wire);
  while (_airSensor.begin(Wire) == 0 && n++ < 5) {
    Serial.print("BEGIN ");
    Serial.println(_airSensor.isConnected());

    delay(500);
    select();
  }
}
