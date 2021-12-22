#include <stdio.h>

void critic(int * const units);

int main(void) {
	int units = 0;

	printf("Сколько фунтов весит маленький бочонок масла?\n");
	scanf("%d", &units);
	while (units != 56) 
	{
		critic(&units);
	}

	printf("Вы знали это!\n");

	return 0;
}

void critic(int * const units)
{
	// необязательное повторное объявление опущено
	printf("Вам не повезло. Попробуйте еще раз.\n");
	scanf("%d", units);
}
