#include <stdio.h>
#include <stdlib.h>

int * make_array(int elem, int val);
void show_array(const int ar[], int n);

int main(void) {
	int * pa;
	int size;
	int value;

	printf("Введите количество элементов: ");
	while (scanf("%d", &size) == 1 && size > 0) {
		printf("Введите значение для инициализации: ");
		scanf("%d", &value);
		pa = make_array(size, value);
		if (pa)
		{
			show_array(pa, size);
			free(pa);
		}
		printf("Введите количество элементов (<1 для завершения): ");
	}
	printf("Программа завершена.\n");
	return 0;
}

int * make_array(int elem, int val) {
	int * ptd;
	ptd = (int *) malloc (elem * sizeof(int));

	for (int i = 0; i < elem; ++i) {
		ptd[i] = val;
	}

	return ptd;
}

void show_array(const int ar[], int n) {
	for (int i = 0; i < n; ++i) {
		if (i != 0 && i % 8 == 0) {
			printf("\n");
		}
		printf("%d ", ar[i]);
	}	
	printf("\n");
}
