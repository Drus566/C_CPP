#include <stdio.h>

int summ(int, int);

int main(void)
{
	int x = summ(12.3, 10.1);
	printf("x - %d\n", x);
	return 0;
}

int summ(int a, int b)
{
	return a + b;
}

void alter(int x, int y)
{
	int temp = x
	x = x + y
	y = temp - y
}

int max(int x, int y, int z)
{
	if (x > y && x > z)
		return x;
	if (y > x && y > z)
		return y;
	if (z > x && z > y)
		return z;
}	

