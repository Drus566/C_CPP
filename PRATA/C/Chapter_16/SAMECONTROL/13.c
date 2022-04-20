#include <math.h>
#include <stdio.h>
#include <stdlib.h> 
#define NUM 100

void fill_array(int *);
void show_array(int *);
int sort_array(const void * p1, const void * p2);

int main(int argc, char * argv[])
{
	int array[NUM];
	fill_array(array);
	show_array(array);
	qsort(array, NUM, sizeof(int), sort_array);
	show_array(array);

	return 0; 
}

void fill_array(int * ptr)
{
	int i = 0;
	for (i; i < NUM; ++i)
	{
		ptr[i] = ((int) rand() / (int) rand()) + 5; 
	}
}

void show_array(int * ptr) 
{
	int i = 0;
	printf("START\n");
	for (i; i < NUM; ++i)
	{
		printf("%d ", ptr[i]);	
		if (i % 5 == 0 && i != 0)
		{
			printf("\n");
		}	
	}
	printf("\nEND\n");
}

int sort_array(const void * p1, const void * p2)
{
	const int * a1 = (const int *) p1;
	const int * a2 = (const int *) p2;


	// по убыванию, т.е. второй больше первого
	if (*a1 < *a2)
		// истина
		return -1;
	else if (*a1 == *a2)
		return 0;
	else
		// ложь
		return 1;
}

