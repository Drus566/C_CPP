#include <stdio.h>

double min(double x, double y);
void chline(char ch, char i, char j);

int main(void)
{
	chline('b', 'd', 'z');
	printf("%.2f\n", min(0.2, 0.3));
	return 0;
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
