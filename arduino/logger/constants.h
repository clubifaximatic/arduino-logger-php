#ifndef __CONSTANTS_H
#define __CONSTANTS_H

// anaog input pins
const uint8_t CO2_INPUTS[] = {0, 1, 2, 3, 4, 5}; // possition when using multiplexer
const int O2_INPUTS[] = {PIN_I0_7, PIN_I0_8, PIN_I0_9, PIN_I0_10, PIN_I0_11, PIN_I0_12}; // Use this for MDuino 21+
//const int O2_INPUTS[] = {A0, A1, A2, A3, A4, A5}; // Use this for Arduio Mega

const int CO2_INPUTS_SIZE = sizeof(CO2_INPUTS) / sizeof(CO2_INPUTS[0]);
const int O2_INPUTS_SIZE = sizeof(O2_INPUTS) / sizeof(O2_INPUTS[0]);


// read and write period
#define READ_PERIOD  10000
#define WRITE_PERIOD 60000

// oxygen value
#define ONE_VOLT (1024/5)
#define MAX_OXYGEN 25.0

// multiplexer address
#define TCAADDR 0x70

// server
#define API_HOST "bideko.elllimoner.com"
#define API_PORT 80

#endif
