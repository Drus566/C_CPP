#include <stdio.h>
int put2(const char * string);
int main(void)
{
	int count = put2("Пизда");
	printf("%d\n", count);
	return 0;
}

int put2(const char * string)
{
	int count = 0;
	while (*string)
	{
		putchar(*string++);
		count++;
	}

	putchar('\n');
	return (count);
}
