
#include "Sensor.h"


/**
 *
 */
Sensor::Sensor()
{
  // nop
}

/**
 * 
 */
double Sensor::average() {
  return _accumulator.average();
}

/**
 * 
 */
void Sensor::clear() {
  _accumulator.clear();
}
