#ifndef __CO2_SENSOR_H
#define __CO2_SENSOR_H

#include <Arduino.h>
#include <SparkFun_SCD30_Arduino_Library.h>
#include <Wire.h>

#include "Accumulator.h"
#include "constants.h"

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
class CO2Sensor {
  private:
    uint8_t _n;
    SCD30 *_airSensor;
    Accumulator _accumulator;

  public:
    CO2Sensor (uint8_t n, SCD30 *airSensor);
    void read ();
    double average ();
    void clear();

  private:
    void select();
};

#endif

/**
 * 
 */
CO2Sensor::CO2Sensor(uint8_t n, SCD30 *airSensor) {
  _accumulator = Accumulator();
  _airSensor = airSensor;
  _n = n;
}

/**
 * 
 */
void CO2Sensor::read() {
  // select the CO2 sensor
  select();

  double value = _airSensor->getCO2();

  Serial.print("CO2 ");
  Serial.print(_n);
  Serial.print(" read: ");
  Serial.println(value);
  
  _accumulator.increment(value);
}

/**
 * 
 */
double CO2Sensor::average() {
  return _accumulator.average();
}

/**
 * 
 */
void CO2Sensor::clear() {
  _accumulator.clear();
}


void CO2Sensor::select() {
  if (_n > 7) return;

  Wire.beginTransmission(TCAADDR);
  Wire.write(1 << _n);
  int r = Wire.endTransmission();
}
