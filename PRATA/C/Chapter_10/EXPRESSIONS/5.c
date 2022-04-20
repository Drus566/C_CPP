#include <stdio.h>
#define SIZE 4 

double get_diff(double * ar, int count);

int main(void)
{

	double sample_massive[SIZE] = { -1.1, 10.4, -40.9, 30.2  };

	double diff = get_diff(sample_massive, SIZE); 
	printf("Это разница между наибольшем и наименьшим %.1f\n", diff);
	
	return 0;
}

double get_diff(double * ar, int count)
{
	double x = *ar;
	double y = *ar;
	double * start = ar + 1;
	double * end = ar + count;
	printf("x %.1f\n", x);
	printf("y %.1f\n", y);
	printf("start %p\n", start);
	printf("end %p\n", end);

	while (start < end)
	{
		if (*start > x)
		{
			x = *start;
		}
		if (*start < y)
		{
			y = *start;
		}

		printf("val %.1f\n", *start);
		++start;
	}	

	printf("MAX: %.1f\n", x);
	printf("MIN: %.1f\n", y);
	return x - y;
}

