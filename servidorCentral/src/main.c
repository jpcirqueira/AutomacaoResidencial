#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <pthread.h>
#include "../inc/cliente_tcp.h"
#include "../inc/servidor_tcp.h"

int bmeErro =0;
int alarme = 0;
void menu(int sinal){
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
    }else if(entrada == 14) {
      alarme = 1;
    }else{
      printf("entrada invalida");
    }
}
void *trata_alarme(void *s){  
  servidor();
  if(alarme == 1){
    printf("alarme tocando.");
  }
}

int main(){
pthread_t t1;
pthread_create(&t1,NULL, trata_alarme,NULL);
printf("para mostrar menu pressione ctrl + z\n");
signal(SIGTSTP, menu);

while(1){
  cliente("13");
  usleep(1000000);
}  
pthread_join(t1,NULL);
return 0;
}
