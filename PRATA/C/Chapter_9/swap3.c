#include <stdio.h>
void interchange(int * u, int * v);

int main(void)
{
	int x = 5, y = 10;

	printf("First x = %d and y = %d.\n", x, y);
	interchange(&x, &y);
	printf("Then x = %d and y = %d.\n", x, y);

	return 0;
}

void interchange(int * u, int * v)
{
	int temp;

	temp = *u;
	*u = *v;
	*v = temp;
}
