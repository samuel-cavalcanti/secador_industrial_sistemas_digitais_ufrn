#include "temperature_system.h"

temperature_system_output temperature_system(temperature_system_input *input)
{
    temperature_system_output output;

    if (input->input_temperature_in_celsius < 20)
        output.input_temperature_is_ok = false;
    else
        output.input_temperature_is_ok = true;

    if (input->output_temperature_in_celsius > 120)
        output.output_temperature_is_ok = false;
    else
        output.output_temperature_is_ok = true;

    return output;
}