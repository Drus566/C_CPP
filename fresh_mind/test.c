#include <stdio.h>
int main(void)
{
	float a=0.5;
	int n = *((int*) &a);
	float b = *((float*) &(++n));
	printf("После %e следующее число: %e, разница (%e)\n", a, b, b-a);
}
