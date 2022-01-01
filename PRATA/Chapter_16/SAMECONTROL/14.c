#include <math.h>
#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 

#define NUM1 100
#define NUM2 300

void fill_array(double *, int);
void show_array(double *, int);
int sort_array(const void * p1, const void * p2);

int main(int argc, char * argv[])
{
	double data1[NUM1];
	double data2[NUM2];

	fill_array(data1, NUM1);
	fill_array(data2, NUM2);

	printf("\nDATA1\n");
	show_array(data1, NUM1);
	printf("\nDATA2\n");
	show_array(data2, NUM2);

	memcpy(data1, data2, sizeof(double) * 100);
	printf("\nDATA1\n");
	show_array(data1, 100);

	memcpy(data1, data2 + 200, sizeof(double) * 100);
	printf("\nDATA1\n");
	show_array(data1, 100);

	return 0; 
}

void fill_array(double * ptr, int count)
{
	int i = 0;
	for (i; i < count; ++i)
	{
		ptr[i] = ((double) rand() / (double) rand()) + 5; 
	}
}

void show_array(double * ptr, int count) 
{
	int i = 0;
	printf("START\n");
	for (i; i < count; ++i)
	{
		printf("%.2f ", ptr[i]);	
		if (i % 5 == 0 && i != 0)
		{
			printf("\n");
		}	
	}
	printf("\nEND\n");
}

int sort_array(const void * p1, const void * p2)
{
	const double * a1 = (const double *) p1;
	const double * a2 = (const double *) p2;

	// по убыванию, т.е. второй больше первого
	if (*a1 < *a2)
		// истина
		return -1;
	else if (*a1 == *a2)
		return 0;
	else
		// ложь
		return 1;
}

