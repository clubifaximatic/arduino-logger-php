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
    Accumulator _accumulatorTemperature;
    Accumulator _accumulatorHumidity;

  public:
    CO2Sensor (uint8_t n, SCD30 *airSensor);
    void read ();
    double averageTemperature();
    double averageHumidity();
    void clear();

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

  double value = _airSensor.getCO2();
  select();
  double valueTemperature = _airSensor.getTemperature();
  select();
  double valueHumidity = _airSensor.getHumidity();

  Serial.print("CO2 ");
  Serial.print(_n);
  Serial.print(" read: ");
  Serial.println(value);

  if (value > 0) {
    _accumulator.increment(value);
  }
  if (valueTemperature > 0) {
    _accumulatorTemperature.increment(valueTemperature);
  }
  if (valueHumidity > 0) {
    _accumulatorHumidity.increment(valueHumidity);
  }
}

/**
 * 
 */
void CO2Sensor::select() {
  if (_n > 7) return;

//  Wire.beginTransmission(TCAADDR);
//  Wire.write(1 << _n);
//  bool r = Wire.endTransmission();
//  Serial.print("select ");
//  Serial.print(_n);
//  Serial.print(" ");
//  Serial.println(r);
}

/**
 * 
 */
double CO2Sensor::averageTemperature() {
  return _accumulatorTemperature.average();
}

/**
 * 
 */
double CO2Sensor::averageHumidity() {
  return _accumulatorHumidity.average();
}

/**
 * 
 */
void CO2Sensor::clear() {
  _accumulator.clear();
  _accumulatorTemperature.clear();
  _accumulatorHumidity.clear();
}

void CO2Sensor::begin() {
  int n = 0;
  select();
  _airSensor.begin(Wire);
  while (_airSensor.begin(Wire) == 0 && n++ < 5) {
    Serial.println("FAIL ");
    delay(500);
    select();
  }
}
