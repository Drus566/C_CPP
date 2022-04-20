#include <stdio.h>
#define JUST_CHECKING
#define LIMIT 4

int main(void)
{
	int i;
	int total = 0;

	for (i = i; i <= LIMIT; i++)
	{
		total += 2*i*i + 1;
#ifdef JUST_CHECKING
		printf("i=%d, промежуточная сумма = %d\n", i, total);
#endif
	}
	printf("Итоговая сумма = %d\n", total);

	return 0; 
}
