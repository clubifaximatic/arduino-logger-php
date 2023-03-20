#ifndef __ACCUMULATOR_H
#define __ACCUMULATOR_H
#include <Arduino.h>

class Accumulator {
  private:
    long _count;
    double _sum;
    double _lastValue;

  public:
    Accumulator ();

    void increment(double value);
    long count();
    double sum();
    double average();
    double lastValue();
    void clear();
};

#endif

/**
 * 
 */
Accumulator::Accumulator() {
  clear();
}

/**
 * 
 */
void Accumulator::increment(double value) {
  _count++;
  _sum += value;
  _lastValue = value;

  Serial.print("INCREMENT: count: ");
  Serial.print(_count);
  Serial.print(" sum: ");
  Serial.print(_sum);
  Serial.print(" last: ");
  Serial.println( _lastValue);
}

/**
 * 
 */
long Accumulator::count() {
  return _count;
}

/**
 * 
 */
double Accumulator::sum() {
  return _sum;
}

/**
 * 
 */
double Accumulator::average() {
  if (_count == 0) {
    return 0.0;
  }

  Serial.print("AVERAGE: ");
  Serial.print(_sum);
  Serial.print(" / ");
  Serial.print(_count);
  Serial.print(" = ");
  Serial.println( _sum / _count);

  return _sum / _count;
}

/**
 * 
 */
double Accumulator::lastValue() {
  return _lastValue;
}

/**
 * 
 */
void Accumulator::clear() {
  _count = 0;
  _sum = 0.0;
  _lastValue = 0.0;
}
