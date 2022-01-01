#include <stdio.h> 
#define CHECK(X,Y) (((((X) % 2) == 0) && (X > Y)) ? 1 : 0)


int main(void)
{
	int a = 4;
	int b = 2;
	int z = CHECK(a,b);
	printf("z: %d\n", z);
	return 0;
}
