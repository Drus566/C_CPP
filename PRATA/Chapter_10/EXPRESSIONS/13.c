#include <stdio.h>
#define ROWS 3
#define COLS 5

void average_for_each(double (*ar)[COLS], int rows);
double max(double (*ar)[COLS], int rows);
void print(double (*ar)[COLS], int rows);
double average(double (*ar)[COLS], int rows);
void init(double (*ar)[COLS], int rows);
double avg_one(double *ar);

int main(void)
{
	double ar[ROWS][COLS];		
	init(ar, ROWS);
	print(ar, ROWS);
	average(ar, ROWS);
	average_for_each(ar, ROWS);
	max(ar, ROWS);
	return 0;
}

void init(double (*ar)[COLS], int rows)
{
	double (*start)[COLS] = ar;
	double (*end)[COLS] = ar + rows;

	int i = 0;

	while (start < end)
	{
		double *st = *start;
		double *ed = *start + COLS;

		printf("%d строчка массива...\n", i);

		int j = 0;

		while (st < ed)
		{
			double num;
			printf("Введите значение %d строки, %d столбца: ", i, j); 

			while (scanf("%lf", &num) != 1)
			{
				scanf("%*s");
				printf("Введите число\n");	
			}
			*st = num;
			++st;
			++j;
		}
		++start;
		++i;
	}
}

double average(double (*ar)[COLS], int rows)
{
	double (*start)[COLS] = ar;
	double (*end)[COLS] = ar + rows;

	double count = COLS * rows;
	double total = 0;

	while (start < end)
	{
		double *st = *start;
		double *ed = *start + COLS;

		while (st < ed)
		{
			total += *st;
			++st;
		}
		++start;
	}

	double avg = total / count;
	printf("Среднее для всех значений: %.2f\n", avg);

	return avg;
}

void average_for_each(double (*ar)[COLS], int rows)
{
	double (*start)[COLS] = ar;
	double (*end)[COLS] = ar + rows;

	int i = 0;

	while (start < end)
	{
		double a = avg_one(*start);
		printf("Среднее для всех значений %d строки: %.2f\n", i, a);
		++start;
		++i;
	}
}

double max(double (*ar)[COLS], int rows)
{
	double (*start)[COLS] = ar;
	double (*end)[COLS] = ar + rows;

	double max = **ar;

	while (start < end)
	{
		double *st = *start;
		double *ed = *start + COLS;

		while (st < ed)
		{
			if (*st > max)
				max = *st;
			++st;
		}
		++start;
	}

	printf("Максимальное значение: %.2f\n", max);
	return max;
}

void print(double (*ar)[COLS], int rows)
{
	double (*start)[COLS] = ar;
	double (*end)[COLS] = ar + rows;

	while (start < end)
	{
		double *st = *start;
		double *ed = *start + COLS;

		printf("{ ");
		while (st < ed)
		{
			printf("%.2f ", *st); 
			++st;
		}
		++start;
		printf("}");
		printf("\n");
	}
}

double avg_one(double *ar)
{
	double *st = ar;
	double *ed = ar + COLS;

	double count = COLS;
	double total = 0;

	while (st < ed)
	{
		total += *st;
		++st;
	}

	double avg = total / count;
	return avg;
}
