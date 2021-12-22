#include <stdio.h>

void larger_of(double * i, double * j);

int main(void)
{
	double i, j;
	i = 2.3;
	j = 11.8999;
	larger_of(&i, &j);
	printf("i: %.2f, j: %.2f\n", i, j);
	return 0;
}

void larger_of(double * i, double * j)
{
	if (*i > *j)
	{
		*i = *i;
		*j = *i;
	} 
	else if (*j > *i)
	{
		*i = *j;
		*j = *j;
	}
}

