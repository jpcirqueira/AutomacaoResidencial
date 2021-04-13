#include <stdio.h>
#include <unistd.h>
#include "./cliente/cliente_tcp.h"
int bmeErro =0;

int main(){
  while(1){
    printf("-----------------------------------Trabalho2---------------------------------\n");
    printf("|digite 1 liga lampada 1.                                                   |\n");
    printf("|digite 2 liga lampada 2.                                                   |\n");
    printf("|digite 3 liga lampada 3.                                                   |\n");
    printf("|digite 4 liga lampada 4.                                                   |\n");
    printf("|digite 5 liga ar-condicionado 1.                                           |\n");
    printf("|digite 6 liga ar-condicionado 2.                                           |\n");
    printf("-----------------------------------------------------------------------------\n");
    int entrada;
    scanf("%d",&entrada);

    if(entrada == 1) {
      cliente("liga lampada 1");
    }else if(entrada == 2){
      cliente("liga lampada 2");
    }else if(entrada == 3) {
      cliente("ligal ampada 3");
    }else if(entrada == 4) {
      cliente("liga lampada 4");
    }else if(entrada == 5) {
      cliente("liga ar-condicionado 1");
    }else if(entrada == 6) {
      cliente("liga ar-condicionado 2");
    }
  }
  
return 0;
}

