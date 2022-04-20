#include <stdio.h>
char *pr(char *str);
int main(void)
{
	char str[40] = "";
	char *gg;
	gg = pr(str);
}
char *pr(char *str)
{
	char *pc;
	pc = str;

	while (*pc)
		putchar(*pc++);

	printf("\n");
	do {
		putchar(*--pc);
		// printf("\n=======\n%ld\n=========\n", pc - str);
	} while (pc - str);

	return (pc);
}
