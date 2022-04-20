#include <stdio.h> 
#include <stdlib.h> 

int main(void)
{
	FILE * fp;
	int counter;
	char filename[] = "test.txt";
	char sample[] = "SetTagValue";
	fp = fopen(filename, "w");	
	scanf("%d", &counter);
	for (int i = 0; i < counter; ++i)
	{
		fprintf(fp, "%s\n", sample);
	}
	fclose(fp);

	return 0; 
}

