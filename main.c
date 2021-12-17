#include <stdbool.h>
#include "draying_system/draying_system.h"
#include "temperature_system/temperature_system.h"
#include "hardware/hardware_abstraction_layer.h"

void loop();

int main()
{
    /*
        a função setup deve ser implementada pelo hardware
        onde ele irá colocar as configurações ou estado inicial do hardware
    */
    setup();

    for (;;)
        loop();
}

void loop()
{

    bool switch_status = read_switch_button_status();

    temperature_system_input temp_input;
    temp_input.input_temperature_in_celsius = read_input_temperature_sensor_in_celsius();
    temp_input.output_temperature_in_celsius = read_output_temperature_sensor_in_celsius();

    /*
            toda a regra de negócio utilizada para decidir se a temperatura está ou não
            de acoordo está definida no módulo temperature system
            é nele que se verifica se a tempertura de entrada e saída estão de acordo com  requisito.
    */
    temperature_system_output temp_output = temperature_system(&temp_input);

    power_led(switch_status);
    low_temperature_led(switch_status && !temp_output.input_temperature_is_ok);
    high_temperature_led(switch_status && !temp_output.output_temperature_is_ok);

    if (!switch_status || !temp_output.input_temperature_is_ok || !temp_output.output_temperature_is_ok)
    {
        output_draying_system draying_output = {0, 0};
        write_air_flow_in_cubic_feet_per_minute(&draying_output.air_flow_velocity_in_feet_per_minute);
        write_heat_flow_in_watts(&draying_output.heat_flow_in_watts);
        return;
    }

    input_draying_system draying_input;

    draying_input.humidity_in_percentage = read_humidity_sensor_in_percentage();

    /*
             o modulo drying_system, é onde está localizado toda a regra de negócio
             que determina as velocidade do secador e a potência do seu aquecedor.
    */
    output_draying_system draying_output = drying_system(&draying_input);

    write_air_flow_in_cubic_feet_per_minute(&draying_output.air_flow_velocity_in_feet_per_minute);

    write_heat_flow_in_watts(&draying_output.heat_flow_in_watts);
}