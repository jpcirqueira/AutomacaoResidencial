#include <stdio.h>
#include <unistd.h>                 
#include <termios.h>        
#include <string.h>
#include <signal.h>
#include <stdlib.h>
#include "./bme/bme.h"

int bmeErro =0;


int main(){
  while (1)
  {
   
    float te = bme();
    printf("%f\n",te);
  }
return 0;
}
