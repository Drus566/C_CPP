#include <stdio.h>
#define SIZE_A 7
#define SIZE 4

void print(int * src, int size);
void cp(int * src, int * dst, int size);

int main(void)
{
	int ar_n[SIZE_A] = {0, 1, 2, 3, 4, 5, 6};
	int ar[SIZE];

	cp(ar_n, ar, SIZE_A);
	print(ar, SIZE);

	return 0;
}

void print(int * src, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d, ", src[i]);
	}
	printf("\n");
}

void cp(int * src, int * dst, int size)
{
	int limit_b = 2;
	int limit_t = 5;
	int i = limit_b;
	for (int j = 0; i <= limit_t; i++, j++)
	{
		dst[j] = src[i];	
	}
}




