#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

#include "draying_system/draying_system.h"

void drying_system_test()
{

    input_draying_system drying_system_inputs[11] = {
        // humidity_in_percentage
        {0},
        {10},
        {20},
        {30},
        {40},
        {50},
        {60},
        {70},
        {80},
        {90},
        {100}};

    output_draying_system expected_outputs[] = {
        // { P(t), Q(t) }
        {0, 0},    //0
        {0, 0},    //10
        {0, 0},    //20
        {25, 100}, //30
        {25, 100}, //40
        {50, 50},  //50
        {50, 50},  //60
        {50, 50},  //70
        {50, 50},  //80
        {50, 50},  //90
        {100, 25}, //100
    };

    for (int i = 0; i < 11; i++)
    {
        input_draying_system *input = &drying_system_inputs[i];
        output_draying_system output = drying_system(input);
        if (output.air_flow_velocity_in_feet_per_minute != expected_outputs[i].air_flow_velocity_in_feet_per_minute ||
            output.heat_flow_in_watts != expected_outputs[i].heat_flow_in_watts)
        {
            printf("Teste Falhou no caso %i\n", i);
            printf("input: %i\n air flow: %i heat flow %i\n",
                   input->humidity_in_percentage, output.air_flow_velocity_in_feet_per_minute, output.heat_flow_in_watts);
            return;
        }
    }

    printf("Passou!!\n");
}

int main(int argc, char const *argv[])
{
    printf("Iniciando teste do sistema de secagem !!\n");
    drying_system_test();

    return 0;
}