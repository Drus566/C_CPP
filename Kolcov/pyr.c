#include <stdio.h>
#include <stdlib.h>

// максимальная длина массива
#define MAXARRAY 5

// сортировка
void heapsort(int ar[], int len);

// помогает heapsort() выталкивать элементы, начиная с позиции pos
void heapbubble(int pos, int ar[], int len);

int main(void)
{
	int array[MAXARRAY];
	int i = 0;

	// инициализация массива
	for (i = 0; i < MAXARRAY; i++)
		array[i] = rand() % 100;

	printf("До сортировки: ");

	for (i = 0; i < MAXARRAY; i++)
		printf(" %d ", array[i]);

	printf("\n");

	// сортировка
	heapsort(array, MAXARRAY);

	printf("После сортировки\n");

	for (i = 0; i < MAXARRAY; i++)
		printf(" %d ", array[i]);

	printf("\n");

	return 0;
}

void heapbubble(int pos, int array[], int len)
{
	int z = 0;
	int max = 0;
	int tmp = 0;
	int left = 0;
	int right = 0;

	z = pos;

	for (;;) 
	{
		// ищем максимальное, то что побольше вверх, то что поменьше вниз
		left = 2 * z + 1;
		right = left + 1;

		if (left >= len)
			return;
		// если правой ветки нет, то левая максимальная
		else if (right >= len)
			max = left;
		else if (array[left] > array[right])
			max = left;
		else
			max = right;

		if (array[z] > array[max])
			return;

		tmp = array[z];
		array[z] = array[max];
		array[max] = tmp;
		z = max;
	}
}

// массив, длинна массива
void heapsort(int array[], int len)
{
	int i = 0;
	int tmp = 0;

	for (i = len / 2; i >= 0; --i)
	{
		heapbubble(i, array, len);
	}

	printf("*******\n");
	for (i = 0; i < MAXARRAY; i++)
		printf(" %d ", array[i]);

	printf("\n");
	printf("*******\n");


	for (i = len - 1; i > 0; i--)
	{
		tmp = array[0];
		array[0] = array[i];
		array[i] = tmp;
		heapbubble(0, array, i);
	}
}
