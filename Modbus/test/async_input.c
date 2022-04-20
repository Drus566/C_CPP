#include <sys/types.h>
#include <string.h> 
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <sys/signal.h>
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

void signal_handler_IO (int status); // обработчик сигнала
int wait_flag = TRUE; // TRUE пока не получен сигнал 

int main (void) 
{
	int fd, c, res;
	struct termios oldtio, newtio;
	struct sigaction saio; // объявление сигнала (signal action)
	char buf[255];

	// открываем устройство как не блокируемое
	// вызов read будет возвращать управление немедленно
	fd = open(MODEMDEVICE, O_RDWR | O_NOCTTY | O_NONBLOCK);
	if (fd < 0) { perror(MODEMDEVICE); exit(-1); }

	// устанавливаем обработчик сигнала перед установкой устройства как асинхронного
	saio.sa_handler = signal_handler_IO;
//	saio.sa_mask = 0;
	saio.sa_flags = 0;
	saio.sa_restorer = NULL;
	sigaction(SIGIO, &saio, NULL);

	// Разрешаем процессу получать SIGIO
	fcntl(fd, F_SETOWN, getpid());

	// делаем файловый дескриптор асинхронным (страница руководства
	// говорит, что только O_APPEND и O_NONBLOCK будут работать с
	// F_SETFL...)
	fcntl(fd, F_SETFL, FASYNC);

	tcgetattr(fd, &oldtio); // сохранение текущих настроек 

	// установка новых настроек порта для обработки канонического ввода
	newtio.c_cflag = BAUDRATE | CRTSCTS | CS8 | CLOCAL | CREAD;
	newtio.c_iflag = IGNPAR | ICRNL;
	newtio.c_oflag = 0;
	newtio.c_lflag = ICANON;
	newtio.c_cc[VMIN] = 1;
	newtio.c_cc[VTIME] = 0;
	tcflush(fd, TCIFLUSH);
	tcsetattr(fd, TCSANOW, &newtio);

	while (STOP == FALSE) {
		printf(".\n"); usleep(100000);
		/*
		 * После получения SIGIO, wait_flag = FALSE, ввод доступен и может быть прочитан
		*/
		if (wait_flag == FALSE) {
			res = read(fd,buf,255); 
			buf[res] = 0; 
			printf(":%s:%d\n", buf, res);
			if (res == 1) STOP = TRUE; // останавливаем цикл при вводе символа CR
			wait_flag = TRUE; // ждем нового ввода
		}
	}
	// восстановление старых установок порта
	tcsetattr(fd,TCSANOW, &oldtio);
}

// обработчик сигнала устанавливает wait_flag в FALSE для индикации
// вышеприведенному циклу, что есть принятый символ

void signal_handler_IO (int status)
{
	printf("received SIGIO signal.\n");
	wait_flag = FALSE;	
}
