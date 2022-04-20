#include <stdio.h>

int main(void)
{
	//int (*ptr)[2];
	//int torf[2][2] = {12, 14, 16};
	//ptr = torf;


  int (*ptr)[2];
	int fort[2][2] = {{12}, {14, 16}};
	ptr = fort;
	printf("%d\n", **(ptr + 1));
	printf("%d\n", **ptr);
	return 0;
}
