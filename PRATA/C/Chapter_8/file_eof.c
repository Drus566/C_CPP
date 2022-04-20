#include <stdio.h>
#include <stdlib.h> // для функции exit()

int main()
{
	int ch;
	FILE * fp;
	char fname[50]; // для хранения имени файла

	printf("Введите имя файла: ");
	scanf("%s", fname);
	fp = fopen(fname, "r"); // открыть файл для чтения
	if (fp == NULL)
	{
		printf("Не удается открыть файл. Программа завершена.\n");
		exit(1);	// выйти из программы
	}
	// функция getc(fp) получает символ из открытого файла
	while ((ch = getc(fp)) != EOF)
		putchar(ch);

	fclose(fp); // закрыть файл

	return 0;
}


