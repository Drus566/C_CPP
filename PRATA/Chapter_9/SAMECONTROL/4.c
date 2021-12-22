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

