#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <stdbool.h>

#define LIM 30

void itobits(char num);
char * s_gets (char * st, int n);

int main(void)
{
	unsigned char byte[LIM];

	printf("Маска\n");
	puts("Введите число (или пустую строку для выхода): ");

	while (s_gets(byte, LIM) && byte[0] != '\0')
	{
		printf("%ld\n", strtol(byte,NULL,16));
		printf("%#lo\n", strtol(byte,NULL,8));
		printf("%#lx\n", strtol(byte,NULL,16));
		printf("%c\n", strtol(byte,NULL,16));

		int length = sizeof(byte) / CHAR_BIT;

		char number = strtol(byte,NULL,10);
		itobits(number);
	}

	return 0; 
}

void itobits(char num)
{
	int size = CHAR_BIT * sizeof(char);
	int mask = 1;
	char bits[size + 1];

	for (int i = size - 1; i >= 0; --i)
	{
		bits[i] = (mask & num) + '0';	
	  num >>= 1;
	}

	bits[size] = '\0'; 

	int i = 0;
	while (bits[i])
	{
		putchar(bits[i]);
		if (++i % 4 == 0 && bits[i])
			putchar(' ');
	}
	putchar('\n');
}

char * s_gets (char * st, int n)
{
	char * ret_val;
	int i = 0;

	ret_val = fgets(st, n, stdin);
	if (ret_val) {
		while (st[i] != '\n' && st[i] != '\0')
			i++;
		if (st[i] == '\n')
			st[i] = '\0';
		else
			while (getchar() != '\n')
				continue;
	}

	return ret_val;
}
