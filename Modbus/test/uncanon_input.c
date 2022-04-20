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

#define MODEMDEVICE "/dev/ttyS1"
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
	newtio.c_cflag = BAUDRATE | CRTSCTS | CS8 | CLOCAL | CREAD;
	newtio.c_iflag = IGNPAR | ICRNL;
	newtio.c_oflag = 0;

	// установка режима ввода (неканонический), нет эха...
	newtio.c_lflag = 0;
	newtio.c_cc[VTIME] = 0; // посимвольный таймер не используется
	newtio.c_cc[VMIN] = 5; // блокировка чтения до тех пор пока не будут приняты 5 символов

	tcflush(fd, TCIFLUSH);
	tcsetattr(fd, TCSANOW, &newtio);

	while (STOP==FALSE) {
		res = read(fd,buf,255); // выход после приема 5-ти символов
		buf[res] = 0; 
		printf(":%s:%d\n", buf, res);
		if (buf[0] == 'z') STOP = TRUE;
	}
	// восстановление старых установок порта
	tcsetattr(fd,TCSANOW, &oldtio);
}

