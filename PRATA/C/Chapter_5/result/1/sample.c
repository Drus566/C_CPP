#include <stdio.h>
int main(void)
{
	int x;
	int y;
	int z;
	y = x = (2 + 3)/4;
	x = (12 + 6)/2*3;
	z = 3 + 2*(x=7/2);
	printf("%d\n", y);
	printf("%d\n", z);
	printf("%d\n", x);
	return 0;
}
