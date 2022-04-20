#include <stdio.h>
#define ROWS 3
#define COLS 5

#define ROWS_F 2
#define COLS_F 4

void cp_ar(int rows, int cols, double ar[rows][cols], double (*s_ar)[cols]);
void print_ar(int rows, int cols, double ar[rows][cols]);

int main(void)
{
	double ar[ROWS][COLS] = {
		{1.2,3.4,5.6,7.8,9.10},
		{11.12,13.14,15.16,17.18,19.20},
		{21.22,23.24,25.26,27.28,29.30}
	};
	double s_ar[ROWS][COLS];

	double ar_f[ROWS_F][COLS_F] = {
		{21.1,21.4,31.6,28.8},
		{91.1,1314.12,15.16,111.8},
	};
	double s_ar_f[ROWS_F][COLS_F];

	cp_ar(ROWS, COLS, ar, s_ar);
	print_ar(ROWS, COLS, s_ar);
	printf("\n*******************************\n");
	cp_ar(ROWS_F, COLS_F, ar_f, s_ar_f);
	print_ar(ROWS_F, COLS_F, s_ar_f);

	return 0;
}

void cp_ar(int rows, int cols, double ar[rows][cols], double (*s_ar)[cols])
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			s_ar[i][j] = ar[i][j];	
		}
	}
}

void print_ar(int rows, int cols, double ar[rows][cols])
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			printf("%.2f, ", ar[i][j]);
		}
		printf("\n");
	}
}
