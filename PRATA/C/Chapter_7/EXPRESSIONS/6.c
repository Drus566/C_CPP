#include <stdio.h>

int main(void)
{
	int count = 0;
	char prev_ch;
	char ch;

	printf("\nВвод...\n");
	while ((ch = getchar()) != '#')
	{
		if (ch == '\n')
		{
			printf("\nВвод...\n");
			continue;
		} 

		if (prev_ch == 'e' && ch == 'i')
		{
			++count;
		}

		prev_ch = ch;
	}

	printf("\nCount of 'ei': %d\n", count);
	return 0;
}
