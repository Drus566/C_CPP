#include <sys/types.h>
#include <stdlib.h> 
#include <unistd.h> // write
#include <netdb.h>
#include <memory.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <arpa/inet.h> // inet_addr
#include <pthread.h> // для потоков, сборка с -lpthread

// этот порт будет слушать программа
#define SERVER_PORT 1234
// размер буфера передаваемых данных
#define BUF_SIZE 64
// наш запрос клиенту
#define MSG_TO_SEND "Version\n"

void * connection_handler(void * socket_desc);

int main(void)
{
	// ans_len - хранение размера передаваемой клиентом информации - фактически размер структуры struct sockaddr_in
	// total - общий счетчик числа клиентов (для вывода порядкового номера клиента)
	int ans_len, total = 0;

	// буфер для обмена информацией
	char buffer[BUF_SIZE];

	int socket_desc, client_sock, c;
	struct sockaddr_in server, client;

	socket_desc = socket(AF_INET, SOCK_STREAM, 0);
	if (socket_desc == -1)
	{
		printf("Ошибка при создании сокета");
	}
	puts("Создан пакет");

	// инициализация структуры sin
	memset((char *)&server, '\0', sizeof(server));
	server.sin_family = AF_INET; // TCP/IP
	server.sin_addr.s_addr = INADDR_ANY; // можем работать на любом адресе
	server.sin_port = htons(1234); // указываем порт (1234)

	// связывание сокета и структуры sin с адресом и портом сервера
	if (bind(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0)
	{
		perror("bind failed. Error");
		return 1;
	}
	puts("bind выполнен");
	printf("Server running...\n");

	// прослушка сокета и максимальное число клиентов не должно превышать 3
	listen(socket_desc, 3);

	puts("Ждем новые соединения...");
	c = sizeof(struct sockaddr_in);
	pthread_t thread_id;

	while ((client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c)))
	{
		puts("Соединение создано");

		if (pthread_create(&thread_id, NULL, connection_handler, (void*) &client_sock) < 0)
		{
			perror("Ошибка при создании потока\n");
			exit(1);
		}
		puts("Обработчик назначен");
	}
	
	if (client_sock < 0)
	{
		perror("accept failed");
		return 1;
	}

	return 0;
}

void * connection_handler(void * socket_desc)
{
	// Получаем дескриптор сокета
	int sock = *(int *)socket_desc;
	int read_size;
	char * message, client_message[2000];

	// приветствует клиента
	message = "Hi! I am your connection handler\n";
	write(sock, message, strlen(message));

	message = "Please, send me a text: \n";
	write(sock, message, strlen(message));

	// читаем сообщение от клиента
	while ((read_size = recv(sock, client_message, 2000, 0)) > 0)
	{
		// добавляем символ конца строки
		client_message[read_size] = '\0';

		// отправляем клиенту его же сообщение
		write(sock, client_message, strlen(client_message));

		// очищаем буфер
		memset(client_message, 0, 2000);
	}

	if (read_size == 0)
	{
		puts("Клиент отключен");
		fflush(stdout);
	}	
	else if (read_size == -1)
	{
		perror("Сбой при recv ");
	}

	return 0;
}
