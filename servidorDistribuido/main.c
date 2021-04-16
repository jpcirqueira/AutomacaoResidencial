#include <stdio.h>
#include <unistd.h>                 
#include <termios.h>        
#include <string.h>
#include <signal.h>
#include <stdlib.h>
#include "./gpio/gpio.h"
#include "./servidorTcp/servidor_tcp.h"
#include "wiringPi.h"

int bmeErro =0;

int main(){
  int w = wiringPiSetup();
  if(w < 0){
      printf("erro ao iniciar wiringPi");
      exit(1);
  }

  servidor();
  // gpio_liga(LAMPADA_01);
  // sleep(5);
  // gpio_desliga(ARCONDICIONADO_01);
  // int teste = ler_gpio(SENSOR_PRESENCA_01);
  // printf("%d\n",teste);

  // while (1)
  // {   
  //   float te = bme();
  //   printf("%f\n",te);
  // }
return 0;
}

