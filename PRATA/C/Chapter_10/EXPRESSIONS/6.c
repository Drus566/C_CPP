#include <stdio.h>
#define SIZE 4 

void print_ar(double *ar, int count);
void change_order(double * ar, int count);

int main(void)
{

	double sample_massive[SIZE] = { -1.1, 10.4, -40.9, 30.2  };

	printf("Исходный массив: ");
	print_ar(sample_massive, SIZE);
	change_order(sample_massive, SIZE); 
	printf("Измененный массив: ");
	print_ar(sample_massive, SIZE);
	
	return 0;
}

void print_ar(double *ar, int count)
{
	for (int i = 0; i < count; i++)
	{
		printf("%.1f; ", ar[i]);
	}
	printf("\n");
}

void change_order(double * ar, int count)
{
	double *ptr;
	double temp[count];
	ptr = temp;

	double * start_source = ar;
	double * end_source = ar + count - 1;

	while (end_source >= start_source)
	{
		*ptr = *end_source;
		--end_source;
		++ptr;
	}	

	start_source = ar;
	end_source = ar + count;
	ptr = temp;

	while (start_source < end_source)
	{
		*start_source = *ptr;
		++start_source;
		++ptr;
	}
}

