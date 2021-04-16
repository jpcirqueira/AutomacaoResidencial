#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <string.h>
#include "../gpio/gpio.h"
#include "../bme/bme280.h"

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

float temperatura = 0;
float umidade = 0;

void bme()
{
  int i;
  
  int T=0,P, H;
  i = bme280Init(1, 0x76);
  if (i != 0)
  {
    printf("ocorreu um erro ao abrir o bme280 ira tentar novamente.\n");
      exit(1);
  }
  
  bme280ReadValues(&T, &P, &H);
  T -= 150;
  temperatura = (float)T/100.0;
	umidade = (float)H/1024;
} 

void TrataClienteTCP(int socketCliente) {
	char buffer[2];
	int tamanhoRecebido;

	if((tamanhoRecebido = recv(socketCliente, buffer, 2, 0)) < 0)
		printf("Erro no recv()\n");

	switch(atoi(buffer)) {
    case 1: {
        gpio_liga(LAMPADA_01);
				send(socketCliente, "lampada 1 ligada", 20, 0);
        break;
    }
		case 2: {
				gpio_liga(LAMPADA_02);
				send(socketCliente, "lampada 2 ligada\n", 20, 0);
        break;
    }
		case 3: {
				gpio_liga(LAMPADA_03);
				send(socketCliente, "lampada 3 ligada\n", 20, 0);
        break;
    }
		case 4: {
				gpio_liga(LAMPADA_04);
				send(socketCliente, "lampada 4 ligada\n", 20, 0);
        break;
    }
		case 5: {
				gpio_liga(ARCONDICIONADO_01);
				send(socketCliente, "ar-condicionado 1 ligado\n", 30, 0);
        break;
    }
		case 6: {
				gpio_liga(ARCONDICIONADO_02);
				send(socketCliente, "ar-condicionado 2 ligado\n", 30, 0);
        break;
    }
		case 7: {
				gpio_desliga(LAMPADA_01);
				send(socketCliente, "lampada 1 desligada\n", 20, 0);
        break;
    }
		case 8: {
				gpio_desliga(LAMPADA_02);
				send(socketCliente, "lampada 2 desligada\n", 20, 0);
        break;
    }
		case 9: {
				gpio_desliga(LAMPADA_03);
				send(socketCliente, "lampada 3 desligada\n", 20, 0);
        break;
    }
		case 10: {
				gpio_desliga(LAMPADA_04);
				send(socketCliente, "lampada 4 desligada\n", 20, 0);
        break;
    }
		case 11: {
				gpio_desliga(ARCONDICIONADO_01);
				send(socketCliente, "ar-condicionado 1 desligado\n", 30, 0);
        break;
    }
		case 12: {
				gpio_desliga(ARCONDICIONADO_02);
				send(socketCliente, "ar-condicionado 2 desligado\n", 30, 0);
        break;
    }
		case 13: {
			bme();
			char response[30];
			char temperatura_aux[9];
			char umidade_aux[9];
			gcvt(temperatura, 4, temperatura_aux);
			gcvt(umidade, 2, umidade_aux);
			strcat(response, "Temperatura: ");
			strcat(response, temperatura_aux);
			strcat(response, " Umidade: ");
			strcat(response, umidade_aux);
			strcat(response, "\n");
			send(socketCliente, response, 50, 0);
			break;
    }
    default: {
      send(socketCliente, "ocorreu um erro ao receber mensaegm\n", 50, 0);
    }
	}
}

int servidor() {
	int servidorSocket;
	int socketCliente;
	struct sockaddr_in servidorAddr;
	struct sockaddr_in clienteAddr;
	unsigned short servidorPorta = 10105;
	unsigned int clienteLength;

	// Abrir Socket
	if((servidorSocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
		printf("falha no socker do Servidor\n");

	// Montar a estrutura sockaddr_in
	memset(&servidorAddr, 0, sizeof(servidorAddr)); // Zerando a estrutura de dados
	servidorAddr.sin_family = AF_INET;
	servidorAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servidorAddr.sin_port = htons(servidorPorta);

	// Bind
	if(bind(servidorSocket, (struct sockaddr *) &servidorAddr, sizeof(servidorAddr)) < 0)
		printf("Falha no Bind\n");

	// Listen
	if(listen(servidorSocket, 10) < 0)
		printf("Falha no Listen\n");		

	while(1) {
		clienteLength = sizeof(clienteAddr);
		if((socketCliente = accept(servidorSocket, 
			                      (struct sockaddr *) &clienteAddr, 
			                      &clienteLength)) < 0)
			printf("Falha no Accept\n");
		
		printf("Conexão do Cliente %s\n", inet_ntoa(clienteAddr.sin_addr));
		
		TrataClienteTCP(socketCliente);
		close(socketCliente);

	}
	close(servidorSocket);

}
