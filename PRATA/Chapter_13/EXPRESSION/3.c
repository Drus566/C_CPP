#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SLEN 81
#define BUFSIZE 1024

void copy(FILE * src, FILE * dst);

int main(void) {

	char file_src[SLEN];
	char file_dst[SLEN];

	printf("Введите имя исходного файла\n");
	scanf("%s", file_src);

	while(getchar() != '\n')
		continue;

	printf("Введите имя конечного файла\n");
	scanf("%s", file_dst);
	
	while(getchar() != '\n')
		continue;

	FILE *src;
	FILE *dst;

	if ((src = fopen(file_src, "rb")) == NULL) 
	{
		printf("Не удается открыть %s\n", file_src);
		exit(EXIT_FAILURE);
	}

	if ((dst = fopen(file_dst, "wb")) == NULL)
	{
		printf("Не удается открыть или создать %s\n", file_dst);
		exit(EXIT_FAILURE);
	}

	if (strcmp(file_src, file_dst) == 0) 
	{
		fputs("Копировать файл сам в себя невозможно\n", stderr);
		exit(EXIT_FAILURE);
	}

	if (setvbuf(dst, NULL, _IOFBF, BUFSIZE) != 0)
	{
		fputs("Не удается создать выходной буфер\n", stderr);
		exit(EXIT_FAILURE);
	}
	
	char ch;
	while ((ch = getc(src)) != EOF) 
	{
		putc(toupper(ch), dst);
	}

	fclose(src);
	fclose(dst);
	return 0;
}


