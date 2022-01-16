#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <memory.h>
#include <stdio.h>
#include <string.h> 
#include <unistd.h>
#include <stdlib.h> 

// инфа для подключения к серверу
#define SERVER_HOST "localhost"
#define SERVER_PORT 1234
#define CLIENT_PORT 1235
// сообщение которое будет передано серверу
#define MSG "Client v.0.1\n"

int main(void)
{
	int socket_desc, val;
	struct sockaddr_in client_addr;

	char buffer[256];
	socket_desc = socket(AF_INET, SOCK_STREAM, 0);

	printf("Введите номер порта\n");
	int port;
	scanf("%d", &port);
	client_addr.sin_family = AF_INET;
	client_addr.sin_addr.s_addr = INADDR_ANY;
	client_addr.sin_port = htons(port);

	if (connect(socket_desc, (struct sockaddr *)&client_addr, sizeof(client_addr)) == 0)
		printf("Подключены к серверу, порт %d\n", port);
	else
	{
		printf("Сбой!\n");
		exit(1);
	}

	read(socket_desc,buffer,256);
	printf("Приветствие от сервера: %s\n", buffer);
	read(socket_desc,buffer,256);
	printf("%s\n", buffer);

	while (1)
	{
		printf("Сообщение для передачи серверу: ");
		bzero(buffer, 256);
		scanf("%s", buffer);
		write(socket_desc,buffer,strlen(buffer));
		bzero(buffer, 256);
		
		read(socket_desc,buffer,256);
		printf("Сообщение от сервера: %s\n", buffer);
	}

	close(socket_desc);
	return 0;
}
