#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int clienteSocket;

int cliente(char *msg) {	
	struct sockaddr_in servidorAddr;
	unsigned short servidorPorta;
	char *IP_Servidor;
	char *mensagem;
	char buffer[16];
	unsigned int tamanhoMensagem;

	int bytesRecebidos;
	int totalBytesRecebidos;

	IP_Servidor = "192.168.0.4";
	servidorPorta = 10105;
	mensagem = msg;

	// Criar Socket
	if((clienteSocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
		printf("Erro no socket()\n");

	// Construir struct sockaddr_in
	memset(&servidorAddr, 0, sizeof(servidorAddr)); // Zerando a estrutura de dados
	servidorAddr.sin_family = AF_INET;
	servidorAddr.sin_addr.s_addr = inet_addr(IP_Servidor);
	servidorAddr.sin_port = htons(servidorPorta);

	// Connect
	if(connect(clienteSocket, (struct sockaddr *) &servidorAddr, 
							sizeof(servidorAddr)) < 0)
		printf("Erro no connect()\n");

	tamanhoMensagem = strlen(mensagem);

	if(send(clienteSocket, mensagem, tamanhoMensagem, 0) != tamanhoMensagem)
		printf("Erro no envio: numero de bytes enviados diferente do esperado\n");

	totalBytesRecebidos = 0;
	while(totalBytesRecebidos < tamanhoMensagem) {
		if((bytesRecebidos = recv(clienteSocket, buffer, 30, 0)) <= 0)
			printf("Não recebeu o total de bytes enviados\n");
		totalBytesRecebidos += bytesRecebidos;
		buffer[bytesRecebidos] = '\0';
		printf("%s\n", buffer);
	}
	close(clienteSocket);
}

void closeCliente(){
	close(clienteSocket);
}