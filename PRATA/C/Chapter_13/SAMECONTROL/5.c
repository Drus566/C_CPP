#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LENGTH 100

int main(int argc, char * argv[]) 
{
	FILE * fp;
	char string[LENGTH];
	char search;
	if (argc != 3)
	{
		printf("Введите 2 аргумента:\n1 аргумент - символ\n2 аргумент - имя файла\n");
		exit(EXIT_FAILURE);
	}

	search = *argv[1];

	if ((fp = fopen(argv[2], "r")) == NULL)
	{
		printf("Нет такого файла\n");
		exit(EXIT_FAILURE);
	}

	while (fscanf(fp, "%s", string) == 1)
	{
		char * tmp = string;
		while (*tmp) {
			if (*tmp == search) {
				printf("%s\n", string);
			}
			++tmp;
		}
	}
	return 0;
}
