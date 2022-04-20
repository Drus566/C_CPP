#include <stdio.h>
int main(void)
{
	char ch;
	for (ch = 'a'; ch <= 'z'; ch++)
		printf("Значение ASCII для %c равно %d.\n", ch, ch);
	return 0;
}
