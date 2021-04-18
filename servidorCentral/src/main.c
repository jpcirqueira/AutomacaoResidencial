#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <pthread.h>
#include "../inc/cliente_tcp.h"
#include "../inc/servidor_tcp.h"
#include "../inc/arquivo.h"

int bmeErro =0;

void menu(int sinal){
    printf("-----------------------------------Trabalho2---------------------------------\n");
    printf("|digite 1 liga lampada 1.                                                   |\n");
    printf("|digite 2 liga lampada 2.                                                   |\n");
    printf("|digite 3 liga lampada 3.                                                   |\n");
    printf("|digite 4 liga lampada 4.                                                   |\n");
    printf("|digite 5 liga ar-condicionado 1.                                           |\n");
    printf("|digite 6 liga ar-condicionado 2.                                           |\n");
    printf("|digite 7 desliga lampada 1.                                                |\n");
    printf("|digite 8 desliga lampada 2.                                                |\n");
    printf("|digite 9 desliga lampada 3.                                                |\n");
    printf("|digite 10 desliga lampada 4.                                               |\n");
    printf("|digite 11 desliga ar-condicionado 1.                                       |\n");
    printf("|digite 12 desliga ar-condicionado 2.                                       |\n");
    printf("|digite 13 liga alarme.                                                     |\n");
    printf("|digite 14 desliga alarme.                                                  |\n");
    printf("-----------------------------------------------------------------------------\n");
    int entrada;
    scanf("%d",&entrada);

    if(entrada == 1) {
      escreveArquivo("liga lampada 1");
      cliente("1");
    }else if(entrada == 2){
      escreveArquivo("liga lampada 2");
      cliente("2");
    }else if(entrada == 3) {
      escreveArquivo("liga lampada 3");
      cliente("3");
    }else if(entrada == 4) {
      escreveArquivo("liga lampada 4");
      cliente("4");
    }else if(entrada == 5) {
      escreveArquivo("liga ar-condicionado 1");
      cliente("5");
    }else if(entrada == 6) {
      escreveArquivo("liga ar-condicionado 2");
      cliente("6");
    }else if(entrada == 7){
      escreveArquivo("desliga lampada 1");
      cliente("7");
    }else if(entrada == 8){
      escreveArquivo("desliga lampada 2");
      cliente("8");
    }else if(entrada == 9) {
      escreveArquivo("desliga lampada 3");
      cliente("9");
    }else if(entrada == 10) {
      escreveArquivo("desliga lampada 4");
      cliente("10");
    }else if(entrada == 11) {
      escreveArquivo("desliga ar-condicionado 1");
      cliente("11");
    }else if(entrada == 12) {
      escreveArquivo("desliga ar-condicionado 2");
      cliente("12");
    }else if(entrada == 13) {
      escreveArquivo("liga alarme");
      setAlarme(1);
    }else if(entrada == 14) {
      escreveArquivo("desliga alarme");
      setAlarme(0);
    }else{
      printf("entrada invalida");
    }
}
 
void *trata_alarme(void *s){  
  servidor();
}

int main(){
pthread_t t1;
criaArquivo();
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

