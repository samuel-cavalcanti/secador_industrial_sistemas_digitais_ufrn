#ifndef HARDWARE_ABSTRACTION_LAYER_H

#define HARDWARE_ABSTRACTION_LAYER_H

#include <stdint.h>
#include <stdbool.h>

/*
  na especificação do sistema existem 3 Leds
  um led simbolizando que o sistema está ou não ligado
  esse led é ligado ou não pela função:
    - power_led.

  Também existem os leds que simbolizam se a temperatura
  de entrada está muito baixa e ou led que simboliza se
  a temperatura de saída está muito elevada.
  A mudança de estado dos leds (Ligado ou Desligado)

  ocorre chamando as funções:
    - low_temperature_led
    - high_temperature_led
*/

/*
    muda o estado do LED L3 para ligado ou desligado
    onde true é ligado e false é desligado 
*/
void power_led(bool turn_on);

/*
    muda o estado do LED L1 para ligado ou desligado
    onde true é ligado e false é desligado 
*/
void low_temperature_led(bool turn_on);

/*
    muda o estado do LED L2 para ligado ou desligado
    onde true é ligado e false é desligado 
*/
void high_temperature_led(bool turn_on);

/*
    na especificação do sistema existe um botão switch
    onde o operador deve pressionar para habilitar o sistema
*/
bool read_switch_button_status();

/*
    os sensores de temperada devem retornar um valor entre 0 200 graus celsius
    dessa forma um número em ponto flutuante de  32 bits deve ser o suficiente para armazenar seu valor
    uma vez que  2^{16}< 200*1024 < 2^{32}
*/

/*
    retorna o valor da temperatura em graus celsius do sensor de entrada
    a temperatura pode variar de 0 até 200 graus celsius
*/
float read_input_temperature_sensor_in_celsius();

/*
    retorna o valor da temperatura em graus celsius do sensor de saída
    a temperatura pode variar de 0 até 200 graus celsius
*/
float read_output_temperature_sensor_in_celsius();

/*
    retorna um valor de humidade em porcentagem.
    Um dos requisitos do sistema é que ele possui um sensor de humidade
    que será utilizado pelo sistema de secagem

    um número em ponto flutuante de 32 bits é mais que o suficiente para armazenar seu valor
    caso realmente precise economizar mememória seria interessante começar com aqui. 
*/
float read_humidity_sensor_in_percentage();

/*
    O sistema possui um driver que rescebe sinal de velocidade
    onde esse sinal pode variar de 0 100 cubic feet per minute (CFM)
    portanto uma variável de 256 bits são suficientes para representar esse sinal.
*/
void write_air_flow_in_cubic_feet_per_minute(uint8_t *velocity);

/*
    O sistema possui um driver que rescebe sinal de potência 
    onde esse sinal pode variar de 0 100 watts (W)
    portanto uma variável de 256 bits são suficientes para representar esse sinal.
*/
void write_heat_flow_in_watts(uint8_t *power);

/*
       todo código de inicialização do microcontrolador é executado na função setup
*/
void setup();

#endif // HARDWARE_ABSTRACTION_LAYER_H