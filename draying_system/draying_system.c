#include "draying_system.h"

output_draying_system drying_system(input_draying_system *input)
{
    output_draying_system output;

    if (input->humidity_in_percentage >= 100)
    {
        output.air_flow_velocity_in_feet_per_minute = 25;
        output.heat_flow_in_watts = 100;
    }

    else if (input->humidity_in_percentage >= 50)
    {
        output.air_flow_velocity_in_feet_per_minute = 50;
        output.heat_flow_in_watts = 50;
    }

    else if (input->humidity_in_percentage >= 25)
    {
        output.air_flow_velocity_in_feet_per_minute = 100;
        output.heat_flow_in_watts = 25;
    }

    else if (input->humidity_in_percentage >= 0)
    {
        output.air_flow_velocity_in_feet_per_minute = 0;
        output.heat_flow_in_watts = 0;
    }

    return output;
}