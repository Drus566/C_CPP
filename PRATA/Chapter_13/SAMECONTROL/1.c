#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE * fp;
	int k;

	if ((fp = fopen("getlatin", "a+")) == NULL)
	{		
		printf("не удается открыть\n");
		exit(EXIT_FAILURE);
	}
	for (k = 0; k < 30; k++) 
		fputs("Кто-то ест студень", fp);
	fclose(fp);
	return 0;
}
