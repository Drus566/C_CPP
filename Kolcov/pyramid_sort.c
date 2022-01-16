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

	printf("z: %d\n", z);

	for (;;) 
	{
		left = 2 * z + 1;
		right = left + 1;

		printf("left: %d\n", left);
		printf("right: %d\n", right);
		printf("array[left]: %d\n", array[left]);
		printf("array[right]: %d\n", array[right]);
		printf("array[z]: %d\n", array[z]);

		if (left >= len)
			return;
		else if (right >= len)
			max = left;
		else if (array[left] > array[right])
			max = left;
		else
			max = right;

		printf("max: %d\n");
		printf("array[max]: %d\n", array[max]);

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

	printf("\ni = len / 2\n");
	for (i = len / 2; i >= 0; --i)
	{
		printf("\nStart iter\n");	
		printf("len: %d\n", len);
		printf("i: %d\n", i);
		heapbubble(i, array, len);
	}

	printf("\n NEXT CHAPTER\n");
	for (i = len - 1; i > 0; i--)
	{
		printf("i: %d\n", i);

		tmp = array[0];
		array[0] = array[i];
		array[i] = tmp;
		heapbubble(0, array, i);
	}
}
