#ifndef __O2_SENSOR_H
#define __O2_SENSOR_H
#include <Arduino.h>

#include "Constants.h"
#include "Sensor.h"

class O2Sensor : public Sensor {
  private:
    int _pin;

  public:
    O2Sensor (int pin);
    void read ();
    double average ();
};

#endif

/**
 *
 */
O2Sensor::O2Sensor(int pin)
{
  _pin = pin;

  pinMode(_pin, INPUT);
}

/**
 * 
 */
void O2Sensor::read() {
  int value = analogRead(_pin);

  Serial.print("O2 ");
  Serial.print(_pin);
  Serial.print(" read: ");
  Serial.println(value);
  
  _accumulator.increment(value);
}

/**
 * 
 */
double O2Sensor::average() {
  double rawAverage = _accumulator.average();
  double value =  map(rawAverage, ONE_VOLT, 1024, 0, MAX_OXYGEN);

  Serial.print("O2 Average ");
  Serial.print(_pin);
  Serial.print(" rawAverage: ");
  Serial.print(rawAverage);
  Serial.print(" value: ");
  Serial.println(value);

  return value < 0 ? 0 : value / 100.0;
}
