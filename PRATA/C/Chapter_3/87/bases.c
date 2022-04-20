#include <stdio.h>
int main(void)
{
	int x = 100;
	printf("десятичное = %d; восьмеричное = %o; шестнадцатиричное = %x\n", x, x, x);
	printf("десятичное = %d; восьмеричное = %#o; шестнадцатиричное = %#x\n", x, x, x);
	return 0;
}
