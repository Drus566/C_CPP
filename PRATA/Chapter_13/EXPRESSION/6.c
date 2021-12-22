#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 50

int main(void) 
{
	FILE * in, * out;
	int ch;
	char name[LEN];
	int count = 0;

	printf("Введите имя файла\n");

	while (scanf("%s", name) != 1) 
	{
		printf("Некорректный ввод");
		printf("Введите имя файла\n");
		continue;
	}	

	if ((in = fopen(name, "r")) == NULL) 
	{
		fprintf(stderr, "Не удается открыть файл \"%s\"\n", name);
		exit(EXIT_FAILURE);
	}

	name[LEN - 5] = '\0';
	strcat(name, ".red");

	if ((out = fopen(name, "w")) == NULL)
	{
		fprintf(stderr, "Не удается создать выходной файл.\n");
		exit(3);
	}

	while ((ch = getc(in) != EOF))
		if (count++ % 3 == 0)
			putc(ch, out);
	
	if (fclose(in) != 0 || fclose(out) != 0)
		fprintf(stderr, "Ошибка при закрытии файлов.\n");

	return 0;
}
