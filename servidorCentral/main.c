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
    printf("|digite 7 desligar lampada 1.                                               |\n");
    printf("|digite 8 desligar lampada 2.                                               |\n");
    printf("|digite 9 desligar lampada 3.                                               |\n");
    printf("|digite 10 desligar lampada 4.                                              |\n");
    printf("|digite 11 desligar ar-condicionado 1.                                      |\n");
    printf("|digite 12 desligar ar-condicionado 2.                                      |\n");
    printf("-----------------------------------------------------------------------------\n");
    int entrada;
    scanf("%d",&entrada);

    if(entrada == 1) {
      cliente("1");
    }else if(entrada == 2){
      cliente("2");
    }else if(entrada == 3) {
      cliente("3");
    }else if(entrada == 4) {
      cliente("4");
    }else if(entrada == 5) {
      cliente("5");
    }else if(entrada == 6) {
      cliente("6");
    }else if(entrada == 7){
      cliente("7");
    }else if(entrada == 8){
      cliente("8");
    }else if(entrada == 9) {
      cliente("9");
    }else if(entrada == 10) {
      cliente("10");
    }else if(entrada == 11) {
      cliente("11");
    }else if(entrada == 12) {
      cliente("12");
    }else{
      printf("entrada invalida");
    }
  }
  
return 0;
}

