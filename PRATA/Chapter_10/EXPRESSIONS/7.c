#include <stdio.h>
#define ROWS 2
#define COLS 3 


void copy_ar(double (*target)[COLS], double (*source)[COLS], int rows);
void print_ar(double (*target)[COLS], int rows);

int main(void)
{
	double t_ar[ROWS][COLS];
	double s_ar[ROWS][COLS] = {{ 0, 1, 2, }, {24, 23, 22}};

	copy_ar(t_ar, s_ar, ROWS);
	printf("Исходный: ");
	print_ar(s_ar, ROWS);
	printf("Цель: ");
	print_ar(t_ar, ROWS);

	return 0;
}

void print_ar(double (*target)[COLS], int rows)
{
	for (int i = 0; i < rows; i++)
	{
		printf("{ ");
		for (int j = 0; j < COLS; j++) 
		{
			printf("%.1f, ", target[i][j]);
		}
		printf(" }, ");
	}
	printf("\n");
}

void copy_ar(double (*target)[COLS], double (*source)[COLS], int rows)
{
	double (*target_start)[COLS] = target;
	double (*target_end)[COLS] = target + rows;

	double (*source_start)[COLS] = source;	

	while (target_start < target_end)
	{
		double * tar_s = *target_start;
		double * tar_e = *target_start + COLS; 

		double * sou_s = *source_start;
		
		while (tar_s < tar_e)
		{
			*tar_s = *sou_s;
			++sou_s;
			++tar_s;
		}
		++target_start;
		++source_start;
	}
}
