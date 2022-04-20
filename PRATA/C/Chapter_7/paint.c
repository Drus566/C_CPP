#include <stdio.h>
#define COVERAGE 350
int main(void)
{
	int sq_feet;
	int cans;

	printf("Введите количество квадратных футов, которые необходимо покрасить:\n");
	while (scanf("%d", &sq_feet) == 1)
	{
		cans = sq_feet / COVERAGE;
		cans += ((sq_feet % COVERAGE == 0)) ? 0 : 1;
		printf("Для этого потребуется %d %s краски.\n", cans, cans == 1 ? "банка" : "банки");
		printf("Введите следующее значение (или q для завершения):\n");
	}
	return 0;
}
