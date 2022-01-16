#include <sys/types.h>
#include <unistd.h>
#include <netdb.h>
#include <memory.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <signal.h>
//#include "sock.h"

// Любой нормальный сервер при поступлении определенных сигналов, например, SIG_HUP должен корректно перезапуститься или вообще завершить работу.
// обработчик сигнала SIGPIPE
//sigpipe_handler()
//{
//	err_quit("Получен SIGPIPE\n");
//}

// этот порт будет слушать программа
#define SERVER_PORT 1234
// размер буфера передаваемых данных
#define BUF_SIZE 64
// наш запрос клиенту
#define MSG_TO_SEND "Version\n"

int main(void)
{
	// установка обработчика SIGPIPE
  // signal(SIGPIPE, sigpipe_handler);
	
	// первый сокет - сокет сервера
	// второй сокет - обмен данными с клиентом
	int sock1, sock2;
	// ans_len - хранение размера передаваемой клиентом информации - фактически размер структуры struct sockaddr_in
	// total - общий счетчик числа клиентов (для вывода порядкового номера клиента)
	int ans_len, total = 0;

	// буфер для обмена информацией
	char buffer[BUF_SIZE];
	// sin - структура для сервера
	// client - для клиента
	struct sockaddr_in sin, client;

	// создание серверного сокета. Набор протоколов TCP/IP, режим с установлением соединения
	sock1 = socket(AF_INET, SOCK_STREAM, 0);

  // Функция memset() копирует младший байт параметра ch в первые count символов массива, адресуемого параметром buf. Функция возвращает значение указателя buf. Чаще всего функция memset() используется для инициализации области памяти некоторым известным значением.
	
	// инициализация структуры sin
	memset((char *)&sin, '\0', sizeof(sin));
	sin.sin_family = AF_INET; // TCP/IP
	sin.sin_addr.s_addr = INADDR_ANY; // можем работать на любом адресе
	sin.sin_port = SERVER_PORT; // указываем порт (1234)

	// связывание сокета и структуры sin с адресом и портом сервера
	bind(sock1, (struct sockaddr *)&sin, sizeof(sin));

	printf("Server running...\n");

	// прослушка сокета sock1(порт 1234) и максимальное число клиентов не должно превышать 3
	listen(sock1, 3);
	
	// бесконечный цикл для постоянной обработки запросов клиентов
	while(1) 
	{
		// получаем размер структуры client
		ans_len = sizeof(client);
		// создаем второй сокет для обмена данными. Если в очереди listen нет клиентов, переходим в режим ожидаения
		sock2 = accept(sock1, &client, &ans_len);
		// отправка сообщения клиенту в sock2
		write(sock2, MSG_TO_SEND, sizeof(MSG_TO_SEND));
		// инкрементируем общее количество клиентов
		total += 1;
		// получаем размер прочитанных данных, данные записываются в buffer
		ans_len = read(sock2, buffer, BUF_SIZE);
		// вывод прочитанных данных на стандартный вывод
		write(1, buffer, ans_len);

		printf("Client no %d\n", total);

		// завершение сеанса связи
		shutdown(sock2, 0);
		// закрытие сокета
		close(sock2);
	};

	return 0;
}
