#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH 20

int main(int argc, char * argv[])
{
	FILE * fp;
	double result = 0;
	double digit;
	int count = 0;

	printf("COUNT OF ARGS: %d\n", argc);
	if (argc == 2) 
	{
		printf("ARG 1: %s\n", argv[0]);
		printf("ARG 2: %s\n", argv[1]);

		char filename[LENGTH];
		strcpy(filename, argv[1]);

		if ((fp = fopen(filename, "r")) == NULL) {
			printf("не удается открыть: %s\n", argv[1]);
			exit(EXIT_FAILURE);
		}

		while (fscanf(fp, "%lf", &digit) == 1)
		{
			result += digit;
			++count;
			float average = result / count;
			printf("Total: %lf, count: %d, average: %lf\n", result, count, average);
		}

	} 
	else if (argc == 1)
	{
		while (scanf("%lf", &digit) != 0)
		{
			result += digit;
			++count;
			double average = result / count;
			printf("Total: %f, count: %d, average: %f\n", result, count, average);
		}
	}
	return 0;
}
