#include <stdio.h>
#define ROWS 2
#define COLS 2

void print_ar(int rows, int cols, int ar[rows][cols]);
void cp_ar(int (*ar_f)[COLS], int (*ar_s)[COLS], int (*ar_t)[COLS], int rows);

int main(void) 
{
	int ar[ROWS][COLS] = {{2,4},{5,6}};
	int ar_s[ROWS][COLS] = {{1,6},{9,2}};
	int ar_t[ROWS][COLS];

	cp_ar(ar, ar_s, ar_t, ROWS);
	printf("\n");
	print_ar(ROWS, COLS, ar);
	printf("\n");
	print_ar(ROWS, COLS, ar_s);
	printf("\n");
	print_ar(ROWS, COLS, ar_t);

	return 0;
}

void print_ar(int rows, int cols, int ar[rows][cols])
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			printf("%d, ", ar[i][j]); 
		printf("\n");
	}
}

void cp_ar(int (*ar_f)[COLS], int (*ar_s)[COLS], int (*ar_t)[COLS], int rows)
{
	int (*start)[COLS] = ar_f;
	int (*end)[COLS] = ar_f + rows;

	while(start < end)
	{
		int * st = *start;
		int * ed = st + COLS;

		int * s_st = *ar_s;
		int * t_st = *ar_t;

		while(st < ed)
		{
			*t_st = *st + *s_st;

			++st;
			++t_st;
			++s_st;
		}

		++start;
		++ar_s;
		++ar_t;	
	}
}
