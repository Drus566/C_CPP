#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LENGTH 41

int main(void)
{
	FILE *fp;
	char name[LENGTH];
	long pos;

	printf("Введите имя файла...: ");
	scanf("%s", name);

	if ((fp = fopen(name, "r+")) == NULL) {
		printf("Не удается открыть файл %s\n", name);
		exit(EXIT_FAILURE);
	}

	long limit;

	fseek(fp, 0, SEEK_END);
	limit = ftell(fp) - 1;
	printf("Граница файла: %ld\n", limit);

	printf("Введите позицию в файле (и отрицательное или не числовое значение для выхода): ");
	while (scanf("%ld", &pos) == 1) 
	{
		if (pos < 0 || pos > limit) 
		{
			printf("Не укладывается в диапазон байтов файла\n");
			printf("Введите позицию в файле (и отрицательное или не числовое значение для выхода): ");
			continue;
		}		

		fseek(fp, pos, SEEK_SET);

		char ch;
		while ((ch = getc(fp)) != '\n')
			putchar(ch);	

		printf("\nВведите позицию в файле: ");
	}
	
	return 0;
}


