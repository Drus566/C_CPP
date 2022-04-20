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
			printf("\nВвод...\n");
			continue;
		}

		if (ch == '.')
		{
			printf("!");
			++count;
		}
		else if (ch == '!')
		{
			printf("!!");
			++count;
		}
		else
		{
			printf("%s", &ch);
		}

	}
	printf("\nCount of switches: %d\n", count);
	return 0;
}
