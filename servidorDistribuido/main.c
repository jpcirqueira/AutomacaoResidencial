#include <stdio.h>
#include <unistd.h>                 
#include <termios.h>        
#include <string.h>
#include <signal.h>
#include <stdlib.h>
#include "./bme/bme.h"
#include "./gpio/gpio.h"
#include "./servidorTcp/servidor_tcp.h"

#define LAMPADA_01 0
#define LAMPADA_02 1
#define LAMPADA_03 2
#define LAMPADA_04 3
#define ARCONDICIONADO_01 23
#define ARCONDICIONADO_02 24
#define SENSOR_PRESENCA_01 6
#define SENSOR_PRESENCA_02 25
#define PORTA_COZINHA 21
#define JANELA_COZINHA 22
#define PORTA_SALA 26
#define JANELA_SALA 27
#define JANELA_QUARTO_01 28
#define JANELA_QUARTO_02 29

int bmeErro =0;

int main(){
  servidor();
  // gpio_liga(LAMPADA_01);
  // sleep(5);
  // gpio_desliga(LAMPADA_01);
  // int teste = ler_gpio(SENSOR_PRESENCA_01);
  // printf("%d\n",teste);

  // while (1)
  // {   
  //   float te = bme();
  //   printf("%f\n",te);
  // }
return 0;
}

