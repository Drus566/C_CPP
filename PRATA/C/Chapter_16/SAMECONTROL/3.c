#include <stdio.h> 
#define MIN(X,Y) ((X) > (Y) ? (Y) : (X))


int main(void)
{
	int a = 4;
	int b = 2;
	int z = MIN(a,b);
	printf("z: %d\n", z);
	return 0;
}
