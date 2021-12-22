#include <stdio.h>

double min(double x, double y);

int main(void)
{
	printf("%.2f\n", min(0.2, 0.3));
	return 0;
}

double min(double x, double y)
{
	if (x < y)
	{
		return x;
	}
	else if (y < x)
	{
		return y;
	}
}
