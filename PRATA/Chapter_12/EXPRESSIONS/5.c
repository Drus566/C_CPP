#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COUNT 100

void sort_decrease(int * nums, int num);

int main(void)
{
	srand((unsigned int) time(0));
	int * ptd;	
	ptd = (int *) malloc (COUNT * sizeof(int));

	printf("Первоначальный список\n");
	for (int i = 0; i < COUNT; ++i) {
		ptd[i] = (int)rand() % 10 + 1;
		printf("%d ", ptd[i]);
		if (i != 0 && i % 20 == 0) {
			printf("\n");
		}
	}
	printf("\n");

	sort_decrease(ptd, COUNT);

	printf("\nОтсортированный список\n");
	for (int i = 0; i < COUNT; ++i) {
		printf("%d ", ptd[i]);
		if (i != 0 && i % 20 == 0) {
			printf("\n");
		}
	}
	printf("\n");
	free(ptd);
	return 0;
}

void sort_decrease(int * nums, int num) {	
	int temp;
	int top, seek;

	for (top = 0; top < num - 1; top++)
		for (seek = top + 1; seek < num; seek++)
			if (nums[top] < nums[seek])
			{
				temp = nums[top];
				nums[top] = nums[seek];
				nums[seek] = temp;
			}
}
