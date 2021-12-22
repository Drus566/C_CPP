#include <stdio.h>
#define ROWS 3
#define COLS 5

void mult(int (*ar)[COLS], int rows);
void print(int (*ar)[COLS], int rows);
void init(int (*ar)[COLS], int rows);

int main(void)
{
	int ar[ROWS][COLS];		
	init(ar, ROWS);
	mult(ar, ROWS);
	print(ar, ROWS);
	return 0;
}

void init(int (*ar)[COLS], int rows)
{
	int (*start)[COLS] = ar;
	int (*end)[COLS] = ar + rows;

	int i = 0;
	int j = 0;

	while (start < end)
	{
		int *st = *start;
		int *ed = *start + COLS;

		printf("%d строчка массива...\n", i);

		while (st < ed)
		{
			int num;
			printf("Введите значение %d строки, %d стобца: ", i, j); 

			while (scanf("%d", &num) != 1)
			{
				scanf("%*s");
				printf("Введите целое число\n");	
			}
			*st = num;
			++st;
			++j;
		}
		++start;
		++i;
	}
}

void mult(int (*ar)[COLS], int rows)
{
	int (*start)[COLS] = ar;
	int (*end)[COLS] = ar + rows;

	while (start < end)
	{
		int *st = *start;
		int *ed = *start + COLS;

		while (st < ed)
		{
			*st = *st * 2;
			++st;
		}
		++start;
	}
}

void print(int (*ar)[COLS], int rows)
{
	int (*start)[COLS] = ar;
	int (*end)[COLS] = ar + rows;

	while (start < end)
	{
		int *st = *start;
		int *ed = *start + COLS;
		printf("{ ");
		while (st < ed)
		{
			printf("%d ", *st); 
			++st;
		}
		++start;
		printf("}");
		printf("\n");
	}
}
