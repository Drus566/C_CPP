#include "diceroll.h"
#include <stdio.h>
#include <stdlib.h> // для rand()

static int rollem(int sides) // закрытая функция
{
	int roll;
	roll = rand() % sides + 1;
	return roll;
}

int roll_n_dice(int dice, int sides, int cast)
{
	int d;
	int total = 0;

	if (sides < 2) {
		printf("Требуются, по меньше мере, 2 грани.\n");
		return -2;
	}

	if (dice < 1)
	{
		printf("Требуется, по меньшей мере, 1 кость.\n");
		return -1 ;
	}

	printf("Имеет %d бросаний %d костей с %d гранями.\n", dice, sides, cast);
	for (d = 0; d < cast; d++)
	{
		int total = 0;
		for (int i = 0; i < dice; ++i) {
			total += rollem(sides);
		}	
		printf("%d ", total);
	}
	printf("\n");
}

