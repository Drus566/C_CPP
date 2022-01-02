#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>
#define NUM 30

void random_val(int *, int, int);
void fill_array(int * ar, int count);

int main(void)
{
	int array[NUM];
	fill_array(array, NUM); 
	random_val(array, NUM, 30);
	return 0;
}

void random_val(int * array, int count, int tact)
{
	if (tact > count) {
		printf("Количество выборок не может быть больше размера массива\n");
		return;
	}

	int selected[count];

	// инициализация массива для проверки 
	for (int i = 0; i < count; ++i)
		selected[i] = 0;
	 

	// семя в зависимости от текущего времени
	srand(time(NULL));

	int chance; 

	// интерируем выборки
	for (int i = 0; i < tact; ++i)
	{
		// выдаем рандом от 0 до count (индекс массива)
		// т.е. если count = 18, то рандом от 0 до 17, поскольку остаток от деления
		chance = rand() % (count);

		// если выборка по такому индексу уже проводилась, то выдаем следующее рандомное число (индекс)
		while (selected[chance] == 1)
			chance = rand() % (count);

		// запоминаем индекс, чтобы дважды не попасть туда же
		selected[chance] = 1;
		
		printf("\nITER: %d\n", i + 1);
		printf("Array[%d]: %d\n", chance, array[chance]);
	}
}

void fill_array(int * ar, int count)
{
	for (int i = 0; i < count; ++i)
		ar[i] = (rand() % (count)) + 1;
}
