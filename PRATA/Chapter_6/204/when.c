#include <stdio.h>
int main(void)
{
	int n = 5;

	while (n++ < 7)
	{
		printf("n = %d\n", n);
		n++;
		printf("Теперь n = %d\n", n);
	}
	printf("Цикл завершен.\n");
	return 0;
}
