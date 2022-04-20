#include <stdio.h>
#include <stdlib.h> // прототип exit()
#define LENGTH 100

int main(void) {
	int ch; // место для хранения каждого символа по мере чтения
	FILE *fp; // указатель файла
	unsigned long count = 0;
	char filename[LENGTH];

	printf("Введите имя файла\n");
	scanf("%s", filename);

	if ((fp = fopen(filename, "r")) == NULL)
	{
		printf("Не удается открыть %s\n", filename);
		exit(EXIT_FAILURE);
	}

	while ((ch = getc(fp)) != EOF)
	{
		putc(ch, stdout); // то же, что и putchar(ch);
		count++;
	}

	fclose(fp);
	printf("Файл %s содержит %lu символов\n", filename, count);
	return 0;
}
