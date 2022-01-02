#include <stdio.h> 
#define GARM(X,...) (X / (__VA_ARGS__))

int main(void)
{
	int count = 3;
	float x1 = 2;
	float x2 = 3;
	float x3 = 4;
	double result;
	result = GARM(3, ((1/x1) + (1/x2) + (1/x3)));

	printf("%.2f\n", result);

	return 0; 
}
