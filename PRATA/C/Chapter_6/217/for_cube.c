#include <stdio.h>
int main(void)
{
	int num;
	printf("    n   n в кубе\n");
	for (num = 1; num*num*num <= 216; num++)
		printf("%5d %5d\n", num, num*num*num);
	return 0;
}
