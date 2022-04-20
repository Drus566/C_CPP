#include <sys/types.h>
#include <string.h> 
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <termios.h>
#include <stdio.h>

// установка скорости передачи в <asm/termios.h>
#define BAUDRATE B38400

#define MODEMDEVICE "/dev/ttyS10"
#define _POSIX_SOURCE 1 // POSIX совместимый источник

#define FALSE 0
#define TRUE 1

volatile int STOP = FALSE;

int main (void) 
{
	int fd, c, res;
	struct termios oldtio, newtio;
	char buf[255];

	// открываем для чтения и записи как неуправляющий терминал (tty)
	// т.к. не хотим завершать процесс когда помехи в линии посылают Ctrl+C
	fd = open(MODEMDEVICE, O_RDWR | O_NOCTTY );
	if (fd < 0) { perror(MODEMDEVICE); exit(-1); }

	tcgetattr(fd, &oldtio); // сохранение текущих настроек 
	bzero(&newtio, sizeof(newtio)); // очистка структуры для новых настроек

	/*
		BAUDRATE - скорость передачи данных в bps 
		(можно использовать cfsetispeed и cfsetospeed)
		CRTSCTS - аппаратное управление выводным потоком данных 
		(используется только если кабель обладает всеми необходимыми сигнальными линиями)
		CS8 - 8n1 (8 бит, без четности, 1 стопбит)
		CLOCAL - локальное подключение, нет управления модемом
		CREAD - разрешает прием символов
	*/

	newtio.c_cflag = BAUDRATE | CRTSCTS | CS8 | CLOCAL | CREAD;

	/*
		IGNPAR - игнорировать байты с ошибками четности
		ICRNL - отобразить символ CR на NL (иначе ввод CR на другом
		компьютере не будет завершать ввод) иначе
		установить устройство как raw (нет обработки ввода)
	*/
	newtio.c_iflag = IGNPAR | ICRNL;
	/*
		Raw вывод (нет обработки вывода)
	*/
	newtio.c_oflag = 0;
	/*
		ICANON - разрешить канонический ввод
		заблокировать любое функционирование эхо и не посылать сигналы
		к вызывающей программе
	*/
	newtio.c_lflag = ICANON;
	/*
		инициализация всех управляющих символов
		значения по умолчанию могут быть найденных в in /usr/include/termios.h,
		и даются в комментариях, но мы не нуждаемся в них здесь
	*/
	newtio.c_cc[VINTR] = 0; // Ctrl-c
	newtio.c_cc[VQUIT] = 0; /* Ctrl-\ */
	newtio.c_cc[VERASE] = 0; // del
	newtio.c_cc[VKILL] = 0; // @
	newtio.c_cc[VEOF] = 4; // Ctrl-d
	newtio.c_cc[VTIME] = 0; // inter-character timer unused
	newtio.c_cc[VMIN] = 1; // blocking read until 1 character arrives
	newtio.c_cc[VSWTC] = 0; // '\0'
	newtio.c_cc[VSTART] = 0; // Ctrl-q
	newtio.c_cc[VSTOP] = 0; // Ctrl-s
	newtio.c_cc[VSUSP] = 0; // Ctrl-z
	newtio.c_cc[VEOL] = 0; // '\0'
	newtio.c_cc[VREPRINT] = 0; // Ctrl-r
	newtio.c_cc[VDISCARD] = 0; // Ctrl-u
	newtio.c_cc[VWERASE] = 0; // Ctrl-w
	newtio.c_cc[VLNEXT] = 0; // Ctrl-v
	newtio.c_cc[VEOL2] = 0; // '\0'

	/*
		Теперь очищаем модемную линию
	*/
	tcflush(fd, TCIFLUSH);
	tcsetattr(fd, TCSANOW, &newtio);

	/*
		терминальные установки выполнены, теперь приступаем к обработке ввода
		ctrl-z будет завершать программу
	*/
	while (STOP==FALSE) {
		/* программа выполняет чтение блока до тех пор пока не будет получен
			символ завершения строки, даже если на ввод получено больше чем 255
			символов. Если число прочитанных символов меньше чем число доступных символов
			то последующее чтение возвратит оставшиеся символы.
			В переменной res будет установлено число реально прочитанных символов
		*/
		res = read(fd,buf,255);
		buf[res] = 0; 
		/* установить завершитель строки, т.о.
		 * мы можем выполнять printf 
		 */
		printf(":%s:%d\n", buf, res);
		if (buf[0] == 'z') STOP = TRUE;
	}
	// восстановление старых установок порта
	tcsetattr(fd,TCSANOW, &oldtio);
}

