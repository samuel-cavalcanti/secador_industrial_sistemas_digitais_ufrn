#include <stdint.h>


#ifndef DRAYING_SYSTEM_H

#define DRAYING_SYSTEM_H

typedef struct output_draying_system
{
    uint8_t heat_flow_in_watts;                   // P(t)
    uint8_t air_flow_velocity_in_feet_per_minute; // Q(t)
} output_draying_system;

typedef struct input_draying_system
{
    float humidity_in_percentage;
} input_draying_system;

output_draying_system drying_system(input_draying_system *input);

#endif// DRAYING_SYSTEM_H