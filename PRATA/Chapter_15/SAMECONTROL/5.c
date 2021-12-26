#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

void itobits(char num);

int main(void)
{
	unsigned char byte;

	printf("Маска\n");
	byte = 128;
	itobits(byte);
	printf("Десятичная %d\n", byte);
	printf("Восьмеричная %#o\n", byte);
	printf("Шестнадцатиричная %#x\n", byte);

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
