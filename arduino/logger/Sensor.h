#ifndef __SENSOR_H
#define __SENSOR_H
#include <Arduino.h>

#include "Accumulator.h"

class Sensor {
  protected:
    Accumulator _accumulator;

  public:
    Sensor();
    virtual void read() = 0;
    virtual double average();
    void clear();
};

#endif
