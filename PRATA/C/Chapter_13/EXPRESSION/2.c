#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SLEN 81
#define BUFSIZE 1024

void copy(FILE * src, FILE * dst);

int main(int argc, char * argv[]) {
	if (argc != 3) {
		printf("Неверное количество аргументов...\n");
		printf("Введите 1 аргумент - имя файла, который копируем...\n");
		printf("        2 аргумент - имя будущей копии файла\n");
		exit(EXIT_FAILURE);
	}

	char file_src[SLEN];
	char file_dst[SLEN];
	strcpy(file_src, argv[1]);
	strcpy(file_dst, argv[2]);

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
	
	copy(src, dst);

	return 0;
}

void copy(FILE * src, FILE * dst) 
{
	size_t bytes;
	static char temp[BUFSIZE]; 
	while (bytes = fread(temp, sizeof(char), BUFSIZE, src))
	{
		fwrite(temp, sizeof(char), bytes, dst);
	}
}

