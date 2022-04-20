#include <stdio.h>
int main(void)
{
	int count = 0;
	int even = 0;
	int odd = 0;
	char ch;

	printf("\nВвод...\n");
	while ((ch = getchar()) != '0')
	{
		if (ch == '\n')
		{
			printf("\nВвод...\n");
			continue;
		}

		count++;
		if (ch % 2 == 0)
		{
			even++;
		} 
		else
		{
			odd++;
		}
	}
	printf("even = %d, average = %d\n", even, count / even);
	printf("odd = %d, average = %d\n", odd, count / odd);

	return 0;
}
