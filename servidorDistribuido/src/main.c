#include <stdio.h>
#include <unistd.h>                 
#include <termios.h>        
#include <string.h>
#include <signal.h>
#include <stdlib.h>
#include "../inc/gpio.h"
#include "../inc/servidor_tcp.h"
#include "../inc/cliente_tcp.h"
#include "wiringPi.h"

#define SENSOR_PRESENCA_01 6
#define SENSOR_PRESENCA_02 25
#define PORTA_COZINHA 21
#define JANELA_COZINHA 22
#define PORTA_SALA 26
#define JANELA_SALA 27
#define JANELA_QUARTO_01 28
#define JANELA_QUARTO_02 29

void alarme(){
  cliente();
}

int main(){
  int w = wiringPiSetup();
  if(w < 0){
      printf("erro ao iniciar wiringPi");
      exit(1);
  }

  wiringPiISR(SENSOR_PRESENCA_01,INT_EDGE_RISING,alarme);
  wiringPiISR(SENSOR_PRESENCA_02,INT_EDGE_RISING,alarme);
  wiringPiISR(PORTA_COZINHA,INT_EDGE_RISING,alarme);
  wiringPiISR(JANELA_COZINHA,INT_EDGE_RISING,alarme);
  wiringPiISR(PORTA_SALA,INT_EDGE_RISING,alarme);
  wiringPiISR(JANELA_SALA,INT_EDGE_RISING,alarme);
  wiringPiISR(JANELA_QUARTO_01,INT_EDGE_RISING,alarme);
  wiringPiISR(JANELA_QUARTO_02,INT_EDGE_RISING,alarme);
  servidor();

return 0;
}

