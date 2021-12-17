#include "temperature_system/temperature_system.h"

#include "stdio.h"
void test_temperature_system()
{

    temperature_system_input inputs[4] = {
        //{input_temperature_in_celsius, output_temperature_in_celsius} ;
        {0, 121},
        {19, 119},
        {21, 140},
        {30, 50}};

    temperature_system_output expected_outputs[4] = {
        // {input_temperature_is_ok, output_temperature_is_ok}
        {false, false}, // 0,121
        {false, true},  // 19, 190
        {true, false},  // 21,140
        {true, true}};  // 30, 50

    for (int i = 0; i < 4; i++)
    {
        temperature_system_output output = temperature_system(&inputs[i]);
        if (output.input_temperature_is_ok != expected_outputs[i].input_temperature_is_ok ||
            output.output_temperature_is_ok != expected_outputs[i].output_temperature_is_ok)
        {
            printf("Teste i: %i Falhou !!\n", i);
            printf("esperado : {%i , %i} recebido  {%i , %i} \n",
                   expected_outputs[i].input_temperature_is_ok, expected_outputs[i].output_temperature_is_ok,
                   output.input_temperature_is_ok, output.output_temperature_is_ok);
            
            return;
        }
    }


    printf("Passou !!\n");


}

int main(int argc, char const *argv[])
{   
    printf("Iniciando teste do sistema de temperatura !!\n");
    test_temperature_system();
    return 0;
}
