#include <stdio.h>
#define SIZE 4 

double get_max(double * ar, int count);

int main(void)
{

	double sample_massive[SIZE] = { -1.1, 10.4, -40.9, 30.2  };

	double max = get_max(sample_massive, SIZE); 
	printf("Это наибольшее значение %.1f\n", max);
	
	return 0;
}

double get_max(double * ar, int count)
{
	double x = *ar;
	double * start = ar + 1;
	double * end = ar + count;
	printf("x %.1f\n", x);
	printf("start %p\n", start);
	printf("end %p\n", end);

	while (start < end)
	{
		if (*start > x)
		{
			x = *start;
		}
		printf("val %.1f\n", *start);
		++start;
	
	}	

	return x;
}

