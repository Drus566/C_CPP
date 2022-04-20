#include <stdio.h>

void some_func(double *a, double *b, double*c);

int main(void)
{
	double a, b, c;
	a = 9.1;
	b = 1.42;
	c = 0.1;
	some_func(&a, &b, &c);
	return 0;
}

void some_func(double *a, double *b, double*c)
{
	double average = (*a + *b + *c) / 3;
	
	double max;
	if ((*a > *b) && (*a > *c))
	{
		max = *a;
	} 
	else if ((*b > *a) && (*b > *c))
	{
		max = *b;
	}
	else if ((*c > *a) && (*c > *b))
	{
		max = *c;
	}

	if ((*a < *b) && (*a < *c))
	{
		*a = *a;
	}		
	else if ((*b < *a) && (*b < *c))
	{
		*a = *b;
	}
	else if ((*c < *a) && (*c < *b))
	{
		*a = *c;
	}

	*b = average;
	*c = max;

	printf("a: %.2f, b: %.2f, c: %.2f\n", *a, *b, *c);
}
