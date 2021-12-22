#include <stdio.h>
int main(void)
{
	int x = 0;
	int c;
	int b = 3;
	int a = b;
	x += 10;
	printf("%d\n", x);
	++x;
	printf("%d\n", x);
	c = (a+b)*2;
	printf("%d\n", c);
	c = a + b * 2;
	printf("%d\n", c);

	return 0;
}
