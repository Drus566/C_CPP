// manydice.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "diceroll.h"

int main(void)
{
	int dice, roll;
	int sides;

	srand((unsigned int) time(0)); // рандомизация начального числа
	printf("Введите количество граней кости или 0 для завершения программы.\n");
	while (scanf("%d", &sides) == 1 && sides > 0) 
	{
		int status;
		printf("Сколько костей?\n");
		if ((status = scanf("%d", &dice)) != 1)
		{
			if (status == EOF)
				break; 
			else
			{
				printf("Вы должны ввести целое число");
				printf("Давайте начнем с начала.\n");
				while (getchar() != '\n')
					continue; // отбросить некорректный ввод

				printf("Сколько граней? Для прекращения введите 0.\n");
				continue; // новая итерация цикла
			}
		}
		roll = roll_n_dice(dice, sides);
		printf("Вы бросали %d раз(а), используя %d кости с %d гранями.\n",
				roll, dice, sides);
		printf("Сколько граней? Для прекращения введите 0.\n");
	}

	printf("Функция rollem() была вызвана %d раз(а).\n",
			roll_count);
	printf("Пусть удача не покидает вас!.\n");
	return 0;
}
