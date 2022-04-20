#include <stdio.h>
extern int rand(void);
extern void srand(unsigned);

int main(void) 
{
	int count;
	unsigned seed;

	printf("Введите желаемое начальное число.\n");
	while (scanf("%u", &seed) == 1)
	{
		srand(seed); // переустановка начального числа
		for (count = 0; count < 5; count++)
			printf("%d\n", rand());
		printf("Введите следующее начальное число (q для завершения):\n");
	}
	printf("Программа завершена.\n");

	return 0;
}
