#include <stdio.h>
void some_func(int n);

int main(void) 
{
	int n = 0;
	some_func(n);
	printf("%d\n", n);
	return 0;
}

void some_func(int n)
{
	n = n + 2;
}
