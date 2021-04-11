#include <stdio.h>
#include <unistd.h>                 
#include <termios.h>        
#include <string.h>
#include <signal.h>
#include <stdlib.h>
#include "./bme/bme.h"
#include "./gpio/gpio.h"

#define LAMPADA_01 0
#define LAMPADA_02 1
#define LAMPADA_03 13
#define LAMPADA_04 15
#define ARCONDICIONADO_01 33
#define ARCONDICIONADO_02 35
#define SENSOR_PRESENCA_01 6
#define SENSOR_PRESENCA_02 37
#define SENSOR_ABERTURA_01 21
#define SENSOR_ABERTURA_02 31
#define SENSOR_ABERTURA_03 26
#define SENSOR_ABERTURA_04 27
#define SENSOR_ABERTURA_05 28
#define SENSOR_ABERTURA_06 29

int bmeErro =0;

int main(){
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


