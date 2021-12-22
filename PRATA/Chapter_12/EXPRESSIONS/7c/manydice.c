// manydice.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "diceroll.h"

int main(void)
{
	int dice, roll;
	int sides;
	int cast;

	srand((unsigned int) time(0)); // рандомизация начального числа
	printf("Введите количество бросаний или q для завершения.\n");

	while (scanf("%d", &cast) == 1 && cast > 0) {
		int status;
		printf("Сколько граней и сколько костей? \n");

		while (scanf("%d %d", &sides, &dice) == 2 && sides > 0) 
		{
			roll_n_dice(dice, sides, cast);
			break;
		}

		printf("Введите количество бросаний или q для завершения.\n");
		continue;
	}
	printf("Пусть удача не покидает вас!.\n");
	return 0;
}
