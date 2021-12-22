#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SLEN 81
#define BUFSIZE 32 

int main(int argc, char * argv[]) {

	char file_dst[SLEN];
	strcpy(file_dst, argv[1]);

	FILE *dst;

	if ((dst = fopen(file_dst, "rb+")) == NULL)
	{
		printf("Не удается открыть или создать %s\n", file_dst);
		exit(EXIT_FAILURE);
	}
	
	double temp[BUFSIZE];
	fread(temp, sizeof(double), BUFSIZE, dst);

	for (int i = 0; i < BUFSIZE; ++i) {
		printf("%f\n", temp[i]);
	}

	fclose(dst);

	if ((dst = fopen(file_dst, "r+")) == NULL)
	{
		printf("Не удается открыть или создать %s\n", file_dst);
		exit(EXIT_FAILURE);
	}
	
	char ch;
	while ((ch = getc(dst)) != EOF) 
	{
		putchar(ch);
	}
	printf("\n");

	fclose(dst);

	return 0;
}


