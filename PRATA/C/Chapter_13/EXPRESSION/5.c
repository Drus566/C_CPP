#include <stdio.h>
#include <stdlib.h>
#define ARSIZE 1000

int main(int argc, char *argv[])
{
	if (argc < 2) {
		printf("Неверное количество аругментов\n");
		printf("Введите индекс в диапазоне 0-%d.\n", ARSIZE - 1);
		exit(EXIT_FAILURE);
	}

	double numbers[ARSIZE];
	double value;

	const char * file = "numbers.dat";
	int i;
	long pos;
	FILE * iofile;

	// создание набора значений double
	for (i = 0; i < ARSIZE; i++) 
	{
		numbers[i] = 100.0 * i + 1.0 / (i + 1);

		// попытка открыть файл
		if ((iofile = fopen(file, "wb")) == NULL)
		{
			fprintf(stderr, "Не удается открыть файл %s для вывода.\n", file);
			exit(EXIT_FAILURE);
		}

		// запись в файл массива в двоичном формате
		fwrite(numbers, sizeof(double), ARSIZE, iofile);
		fclose(iofile);
	}

	i = atoi(argv[1]);
	if ((iofile = fopen(file, "rb")) == NULL)
	{
		fprintf(stderr, "Не удается открыть файл %s для произвольного доступа.\n", file);
		exit(EXIT_FAILURE);
	}

	// чтение избранных элементов из файла
	// printf("Введите индекс в диапазоне 0-%d.\n", ARSIZE - 1);
	if (i >= 0 && i < ARSIZE)
	{
		pos = (long) i * sizeof(double); // вычисление смещения
		fseek(iofile, pos, SEEK_SET); // переход в нужную позицию
		fread(&value, sizeof(double), 1, iofile);
		printf("По этому индексу находится значение %f.\n", value);
	}

	// завершение 
	fclose(iofile);
	puts("Программа завершена.");
	return 0;
}
