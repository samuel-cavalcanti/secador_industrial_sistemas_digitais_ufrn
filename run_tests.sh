#! /bin/bash

TEST_TEMP=test_temperature
TEST_DRAYING=test_draying
# Compilando modulo que com seu respectivo teste
gcc test_temperature_system.c temperature_system/* -o $TEST_TEMP
gcc test_draying_system.c draying_system/*   -o $TEST_DRAYING

#executando testes
./$TEST_TEMP
./$TEST_DRAYING

# Removendo os arquivos de teste

rm test_temperature test_draying