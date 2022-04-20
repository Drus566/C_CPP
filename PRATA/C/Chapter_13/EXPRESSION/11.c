#include <stdio.h> 
#include <stdlib.h>
#include <string.h> 

#define LENGTH 40
#define BUFSIZE 1024 

int main(int argc, char * argv[])
{
	if (argc < 2) {
		printf("Введите аргументы программы\n");
		exit(EXIT_FAILURE);
	}

	char search[LENGTH];
	char namefile[LENGTH];

	strcpy(search, argv[1]);
	strcpy(namefile, argv[2]);

	FILE *fp;

	if ((fp = fopen(namefile, "r+")) == NULL) {
		printf("Невозможно открыть файл %s\n", namefile);
		exit(EXIT_FAILURE);
	}

	char words[BUFSIZE];

	while(fgets(words, BUFSIZE, fp) != NULL) {
		if (strstr(words, search) != 0)
			fputs(words, stdout);
	}
}
