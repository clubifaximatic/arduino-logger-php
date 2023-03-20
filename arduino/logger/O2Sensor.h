#ifndef __O2_SENSOR_H
#define __O2_SENSOR_H
#include <Arduino.h>

class O2Sensor {
  private:
    int _pin;
    Accumulator _accumulator;

  public:
    O2Sensor (int pin);
    void read ();
    double average ();
    void clear();
    
 private:
   void initialize ();
};

#endif

/**
 *
 */
O2Sensor::O2Sensor(int pin)
{
  _accumulator = Accumulator();
  _pin = pin;

  pinMode(_pin, OUTPUT);
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

  return value < 0 ? 0 : value;
}

/**
 * 
 */
void O2Sensor::clear() {
  _accumulator.clear();
}
