#include <stdio.h>

int main(void)
{
	int iter;
	int counter = 0;
	int value = 1;
	unsigned int sum;
	printf("Введите сумму интераций: \n");
	scanf("%d", &iter);
	printf("***Начало***\n");
	while (++counter <= iter)
	{
		sum = value + value;
		printf("%d\n", sum);
		++value;
	}
	printf("***Конец***\n");

	return 0;
}
