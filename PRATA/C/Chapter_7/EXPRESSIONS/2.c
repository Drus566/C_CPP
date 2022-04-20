#include <stdio.h>
int main(void)
{
	int count = 0;
	char ch;

	printf("\nВвод...\n");
	while ((ch = getchar()) != '#')
	{
		if (ch == '\n')
		{
			count = 0;
			printf("\nВвод...\n");
			continue;
		}

		if (count % 8 == 0)
		{
			printf("\n");
		}

		printf("%c - %d; ", ch, ch);
		++count;
	}
	return 0;
}
