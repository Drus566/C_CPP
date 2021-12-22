#include <stdio.h>
#define SIZE 4 

int get_max(int * ar, int count);

int main(void)
{

	int sample_massive[SIZE] = { -1, 10, -40, 30  };

	int max = get_max(sample_massive, SIZE); 
	printf("Это наибольшее значение %d\n", max);
	
	return 0;
}

int get_max(int * ar, int count)
{
	int x = *ar;
	int * start = ar + 1;
	int * end = ar + count;
	printf("x %d\n", x);
	printf("start %p\n", start);
	printf("end %p\n", end);

	while (start < end)
	{
		if (*start > x)
		{
			x = *start;
		}
		printf("val %d\n", *start);
		++start;
	
	}	

	return x;
}
