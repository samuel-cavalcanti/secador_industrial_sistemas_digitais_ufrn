# secador industrial para secagem de grãos

_Samuel Cavalcanti_

Esse software foi projetado de forma que a sua regra de negócio não esteja acoplada ao hardware, fazendo assim uso do **PODER** da linguagem C. Todo hardware que implemente as funcionalidades do arquivo [hardware_abstraction_layer.h](hardware/hardware_abstraction_layer.h) pode **REUTILIZAR** esse sistema

Durante o desenvolvimento foi utilizado:
- gcc
- avr-gcc
  
ferramentas necessárias para compilar o projeto e executar os testes

## Para executar os testes

```shell
chmod +x run_tests.sh
./run_tests.sh
```


testes no tinkercad : [https://www.tinkercad.com/things/2QMDR9vPmWN](https://www.tinkercad.com/things/2QMDR9vPmWN)

## Para Compilar o projeto

```shell
chmod +x compile.sh
./compile.sh
```

## Como o professor pode corrigir essa atividade

### Ler o PDF como pedido

[prova.pdf](prova.pdf)

### sugestão do aluno

Essa prova pode ser dividia em 2 problemas.

 1. um problema de lógica de programação em C qual é feito
um conjunto de _ifs_  e  _elses_  para resolver a lógica principal do programa está no [main.c](main.c)
     - depois o professor deve checar a lógica do sistema de secagem [draying system](draying_system/draying_system.c)
  
     - depois o professor deve checar a lógica do sistema de temperatura [temperature system](temperature_system/temperature_system.c)


 2. tendo em vista que a lógica da regra de negócio está correta. O professor
Pode verificar os meus conhecimentos do atmega e a parte de hardware no arquivo
[arduino_uno.c](hardware/arduino_uno.c). Onde foi implementado os detalhes como
leitura dos sensores e escrita dos atuadores

3. Observar a simulação no tinkercad [https://www.tinkercad.com/things/2QMDR9vPmWN](https://www.tinkercad.com/things/2QMDR9vPmWN)
      
      - onde os potenciômetros são so sensores de temperatura  


4. Em relação as medidas de temperatura e umidade, Utilizei uma tensão de referência
externa de 5V dessa forma o sensor de umidade, perde um pouco de sua resolução, mas tendo em vista que:
    - 2.5/1024 = 0.0024 
    - 2.5/512  = 0.0049
  
então não existe uma perda significativamente grande.

1. Perceber que é bem legal, poder criar um **esp32.c** e implementar a interface de hardware
```c
void power_led(bool turn_on);
void low_temperature_led(bool turn_on);
void high_temperature_led(bool turn_on);
bool read_switch_button_status();
float read_input_temperature_sensor_in_celsius();
float read_output_temperature_sensor_in_celsius();
float read_humidity_sensor_in_percentage();
void write_air_flow_in_cubic_feet_per_minute(uint8_t *velocity);
void write_heat_flow_in_watts(uint8_t *power);
void setup();  
```
sem precisar mudar a regra de negócio do sistema.
