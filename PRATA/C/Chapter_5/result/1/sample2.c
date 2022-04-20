#include <stdio.h>
int main(void)
{
	int x;
	int y;
	int z;
	int g;
	int z1;
	int z2;
	y = 30.0 / (4.0 * 5.0);
	x = 30.0 / 4.0 * 5.0;
	z = 30 / 4 * 5;
	z1 = 30 / 4.0 * 5;
	g = 30 * 5 / 4;
	z2 = 30 / 4 * 5.0;

	printf("%d\n", x);
	printf("%d\n", y);
	printf("%d\n", z);
	printf("%d\n", g);
	printf("%d\n", z1);
	printf("%d\n", z2);
	return 0;
}

