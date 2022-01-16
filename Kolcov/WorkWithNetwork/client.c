#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <memory.h>
#include <stdio.h>
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
	int sock;
	int ans_len;
	int BUF_SIZE = 64;

	char buffer[BUF_SIZE];

	// для получения адреса сервера
	struct hostent *h;
	
	struct sockaddr_in client, server;

	sock = socket(AF_INET, SOCK_STREAM, 0);

	memset((char *)&client, '\0', sizeof(client));

	client.sin_family = AF_INET;
	client.sin_addr.s_addr = INADDR_ANY;
	client.sin_port = CLIENT_PORT;

	bind(sock, (struct sockaddr *)&client, sizeof(client));

	// инициализация структуры сервера
	memset((char *)&server, '\0', sizeof(server));

	// определение айпи адреса сервера
	h = gethostbyname(SERVER_HOST);

	// набор протоколов
	server.sin_family = AF_INET;
	// задаем адрес сервера
	memcpy ((char *)&server.sin_addr,h->h_addr,h->h_length);
	// указываем порт сервера
	server.sin_port = SERVER_PORT;

	// Подключение к серверу
	connect(sock, &server, sizeof(server));

	// принимаем запрос сервера, выводим его на стандартный вывод, отправляем ему свое сообщение и закрываем сокет
	ans_len = recv(sock, buffer, BUF_SIZE, 0);
	write(1, buffer, ans_len);
	send(sock, MSG, sizeof(MSG), 0);
	close(sock);
	exit(0);
}
