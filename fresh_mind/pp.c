#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void pp(int ar[]);

int main(void)
{
	int ar[] = {1, 2, 3};
	printf("%d\n", ar[0]);
	pp(ar);
	printf("%d\n", ar[0]);
	return 0;
}

void pp(int ar[])
{
	ar[0] = 10;
}
