#include <stdio.h>

char get_first(void);

int main(void)
{
	char ch;

	ch = get_first();
	putchar(ch);

	return 0;
}

char get_first(void)
{
	int ch;

	while ((ch = getchar()) == ' ')
		continue;

	// while (getchar() != '\n')
	// 	continue;

	return ch;
}
