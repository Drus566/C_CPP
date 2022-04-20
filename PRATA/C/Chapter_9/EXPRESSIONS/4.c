#include <stdio.h>
#include <stdlib.h>

double min(double x, double y);
void chline(char ch, char i, char j);
void print(char ch, int i, int j);
double average_harmonic(double i, double j);

int main(void)
{
	chline('b', 'd', 'z');
	printf("%.2f\n", average_harmonic(25.2, 9.1));
	printf("%.2f\n", min(0.2, 0.3));
	print('X', 30, 8);
	return 0;
}

void print(char ch, int i, int j)
{
	for(int k = 1; k <= j; k++)
	{
		for(int v = 1; v <= i; v++)
		{
			printf("%c", ch);
		}
		printf("\n");
	}	
}

void chline(char ch, char i, char j)
{
	if (ch >= i && ch <= j)
	{
		printf("%c\n", ch);
	}
}

double min(double x, double y)
{
	if (x < y)
	{
		return x;
	}
	else if (y < x)
	{
		return y;
	}
}

double average_harmonic(double i, double j)
{
	i = 1/i;
	j = 1/j;
	double average = (i + j) / 2;
	return 1/average;
}
