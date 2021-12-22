#include <stdio.h>

int main(void)
{
	int count = 0;
	char ch;

	printf("\nВвод...\n");
	while ((ch = getchar()) != '#')
	{
		switch(ch)
		{
			case '\n':
				printf("\nВвод...\n");
				continue;
			case '.':
				printf("!");
				++count;
				break;
			case '!':
				printf("!!");
				++count;
				break;
			default:
				printf("%s", &ch);
		}
	}
	printf("\nCount of switches: %d\n", count);
	return 0;
}
