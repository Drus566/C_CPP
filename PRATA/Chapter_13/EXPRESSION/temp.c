#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SLEN 81
#define BUFSIZE 32 

int main(int argc, char * argv[]) {

	char file_dst[SLEN];
	strcpy(file_dst, argv[1]);

	FILE *dst;

	if ((dst = fopen(file_dst, "wb")) == NULL)
	{
		printf("Не удается открыть или создать %s\n", file_dst);
		exit(EXIT_FAILURE);
	}

	double temp[BUFSIZE];
	double semp[BUFSIZE];

	for (int i = 0; i < BUFSIZE; ++i) 
	{
		temp[i] = i + 0.2 * i + 1;
		printf("%d: %f\n", i, temp[i]);
	}

	fwrite(temp, sizeof(double), BUFSIZE, dst);

	fclose(dst);


	if ((dst = fopen(file_dst, "rb")) == NULL)
	{
		printf("Не удается открыть или создать %s\n", file_dst);
		exit(EXIT_FAILURE);
	}

	fread(semp, sizeof(double) * BUFSIZE, 1, dst);

	printf("SEMP\n");
	for (int i = 0; i < BUFSIZE; ++i) 
	{
		printf("%d: %f\n", i, semp[i]);
	}

	fclose(dst);

	return 0;
}


