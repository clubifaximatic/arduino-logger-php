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
