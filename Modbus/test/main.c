#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <termios.h>

//struct termios {
//	tcflag_t c_iflag; // флаги режима ввода
//	tcflag_t c_oflag; // флаги режима вывода
//	tcflag_t c_cflag; // флаги управляющего режима
//	tcflag_t c_lflag; // флаги локального режима
//	cc_t c_line; // дисциплина линии связи
//	cc_t c_cc[NCCS]; // управляющие символы
//};

// текущие настройки устройства
//int tcgetattr(int fd, struct termios * tp);
// установка настроек
//int tcsetattr(int fd, int oact, struct termios * tp);

int main(int argc, char ** argv)
{
	struct termios oldsettings, newsettings;
	tcgetattr(fileno(stdin), &oldsettings);
	newsettings = oldsettings;
	// снимаем флаг локального эха, канонического режима, отключаем получение сигналов
	newsettings.c_lflag &= ~(ECHO|ICANON|ISIG);
	newsettings.c_cc[VMIN] = 1;
	newsettings.c_cc[VTIME] = 1;
	tcsetattr(fileno(stdin), TCSANOW, &newsettings);
	printf("press [q] to quit\n");
	char rd_ch = '\0';

	char buffer[256];

	int fd_open = open("/dev/tty", O_RDONLY)
	if ( fd_open <= 0) 
	{
		pritnf("Error open\n");
	}

	while (rd_ch != 'q') {
		int read_count = read(fd_open, &rd_ch, 1);
	}

	tcsetattr(fileno(stdin), TCSANOW, &oldsettings);
	return EXIT_SUCCESS;

	int length = 10;
	int result = read(fd_open, buffer, length);
	// if length > SSIZE_MAX // Неопределен
	// return result == length reads bytes, file position increase on length reads bytes
	// if result == 0 // end of file
	// if result <= length // this is not error
	// result == -1 // if error
	// var errno == error number // in this case file position not defined
	
	buffer[0] ='\0';
	buffer = "ggwp";
	int size_buffer = sizeof(buffer);
	int count_write_bytes = write(fd_open, buffer, size_buffer);
	// if count_write_bytes == 0 // not write nothing
	// if count_write_bytes == -1 // error and errno = error number
	

	if(close(fd_open) != 0)
	{
		printf("Erro close\n");
	}

	return 0;
}

