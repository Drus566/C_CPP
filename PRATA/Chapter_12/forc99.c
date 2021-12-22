#include <stdio.h>

int main()
{
	int n = 8;

	printf(" Первоначально n = %d по адресу %p\n", n, &n);
	for (int n = 1; n < 3; n++)
		printf("		цикл 1: n = %d по адресу %p\n", n, &n);
	printf(" После цикла 1 n = %d по адресу %p\n", n, &n);
	for (int n = 1; n < 3; n++)
	{
		printf("		индекс цикла 2 n = %d по адресу %p\n", n, &n);
		int n = 6;
		printf("			цикл 2: n = %d по адресу %p\n", n, &n);
		n++;
	}

	printf("	После цикла 2 n = %d по адресу %p\n", n, &n);

	return 0;
}
