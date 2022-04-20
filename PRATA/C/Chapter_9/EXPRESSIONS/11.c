#include <stdio.h>

void fibonachi(int limit);

int main(void)
{
	fibonachi(111);
	return 0;
}

void fibonachi(int limit)
{
	int temp;
	int prev = 1;
	int next = 1; 
	int result = 0;

	printf("%d\n", 0);

	for (int i = 0; i <= limit; i++)
	{
		if (i == next)
		{
			printf("%d\n", next);
			temp = next;
			next = prev + next;
			prev = temp;
		}
	}
}
