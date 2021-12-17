
#ifndef TEMPERATURE_SYSTEM_H

#define  TEMPERATURE_SYSTEM_H

#include <stdint.h>
#include <stdbool.h>

typedef struct temperature_system_input
{
    float input_temperature_in_celsius;
    float output_temperature_in_celsius;

} temperature_system_input;

typedef struct temperature_system_output
{
    bool input_temperature_is_ok;
    bool output_temperature_is_ok;
} temperature_system_output;

temperature_system_output temperature_system(temperature_system_input *input);

#endif //TEMPERATURE_SYSTEM_H