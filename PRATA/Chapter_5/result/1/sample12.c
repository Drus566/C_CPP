#include <stdio.h>
int main(void)
{
	int x = 0;
	int m;
	int n = 20;
	int k = 6;
	int q = 2;
	int b = 12;
	int a = 10;
	int d = 3;
	int c = 4;
	int p;
	--x;
	printf("%d\n", x);
	m = n % k;
	printf("%d\n", m);
	p = q / (b - a);
	printf("%d\n", p);
	x = (a + b) / (c * d);
	printf("%d\n", x);
	return 0;
}
