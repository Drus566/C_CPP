#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100

void transform(double *, double *, int, double (*)(double)); 
void init_src(double *);
void display(double *);

double multiply_twice(double);
double divide_twice(double);

int main(void)
{
	double src[100];
	double dst[100];

	init_src(&src[0]);

	printf("\n\nMULTIPLE:\n\n");

	transform(&src[0], &dst[0], MAX, multiply_twice);
	display(&dst[0]);

	printf("\n\nDIVIDE:\n\n");

	transform(&src[0], &dst[0], MAX, divide_twice);
	display(&dst[0]);

	printf("\n\nSIN:\n\n");

	transform(&src[0], &dst[0], MAX, sin);
	display(&dst[0]);
	
	printf("\n\nCOS:\n\n");

	transform(&src[0], &dst[0], MAX, cos);
	display(&dst[0]);
	
	return 0; 
}

void transform(double * src, double * dst, int size, double (*func)(double))
{
	for (int i = 0; i < size; i++)
		dst[i] = (*func)(src[i]);
}

double multiply_twice(double x)
{
	return x * 2;	
}

double divide_twice(double x)
{
	return  x / 2;
}

void init_src(double * src)
{
	for (int i = 0; i < MAX; i++)
		*(src + i) = i + 1;
}

void display(double * ptr)
{
	for (int i = 0; i < MAX; i++)
	{
		printf("%.2f", *(ptr + i));
		if (i != MAX - 1)
			printf(", ");
	}

}
