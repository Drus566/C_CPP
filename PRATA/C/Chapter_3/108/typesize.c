#include <stdio.h>
int main(void)
{
	printf("Тип int имеет размер %zd байт.\n", sizeof(int));
	printf("Тип char имеет размер %zd байт.\n", sizeof(char));
	printf("Тип long имеет размер %zd байт.\n", sizeof(long));
	printf("Тип long long имеет размер %zd байт.\n", sizeof(long long));
	printf("Тип double имеет размер %zd байт.\n", sizeof(double));
	printf("Тип long double имеет размер %zd байт.\n", sizeof(long double));
	return 0;
}
