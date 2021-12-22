#include <stdio.h>
#define SIZE 3

void first_f(double * target, double * source, int count);
void second_f(double * target, double * source, int count);
void third_f(double * target, double * source, double * target_end);
void out(double * target, int count);

int main(void)
{
	double first[SIZE];
	double second[SIZE];
	double third[SIZE];

	double sample[SIZE] = {0, 1, 2};
	
	printf("----------------\n");
	printf("BEST\n");
	out(sample, SIZE);
	printf("----------------\n");

	first_f(first, sample, SIZE);
	printf("----------------\n");
	printf("First\n");
	out(first, SIZE);
	printf("----------------\n");

	second_f(second, sample, SIZE);
	printf("----------------\n");
	printf("Second\n");
	out(second, SIZE);
	printf("----------------\n");

	third_f(third, sample, sample + SIZE);
	printf("----------------\n");
	printf("Third\n");
	out(third, SIZE);
	printf("----------------\n");

	return 0;
}

void out(double * target, int count)
{
	for (int i = 0; i < count; i++)
	{
		printf("%lf\n", target[i]);
	}
}

void first_f(double * target, double * source, int count)
{
	for (int i = 0; i < count; i++)
	{
		target[i] = source[i];
	}
}

void second_f(double * target, double * source, int count)
{
	double * ptr = source + count;
	for (int i = 0; source < ptr; target++, source++) 
	{
		*target = *source;
	}
}

void third_f(double * target, double * source,  double * target_end)
{
	double * start = source;
	double * end = target_end;	
	double * temp = target;

	while (start < end)
	{
		*temp = *start;
		++start;
		++temp;
	}
}
