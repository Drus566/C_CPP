#include <stdio.h>
#define COUNTER 11
int main(void)
{
	int number;
	int counter;
	printf("Введите целое число: \n");
	scanf("%d", &number);
	counter = number + COUNTER;
	while (++number < counter)
		printf("%d\n", number);

	return 0;
}
