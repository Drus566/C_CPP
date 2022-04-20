#include <stdio.h>

int main(void)
{
	char ch;
	while ((ch = getchar()) != '\n')
	{
		putchar(ch++);
		putchar(++ch);
	}
}
