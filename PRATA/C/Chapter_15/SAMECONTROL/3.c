#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

void itobits(char num);

int main(void)
{
	unsigned char byte;

	byte = ~3;
	printf("val = ~3: %d\n", byte);
	itobits(byte);

	byte = 3 & 6;
	printf("\n3 & 6: %d\n", byte);
	itobits(byte);

	byte = 3 | 6;
	printf("\n3 | 6: %d\n", byte);
	itobits(byte);

	byte = 1 | 6;
	printf("\n1 | 6: %d\n", byte);
	itobits(byte);

	byte = 3 ^ 6;
	printf("\n3 ^ 6: %d\n", byte);
	itobits(byte);

	byte = 7 >> 1;
	printf("\n7 >> 1: %d\n", byte);
	itobits(byte);

	byte = 7 << 2;
	printf("\n7 << 2: %d\n", byte);
	itobits(byte);

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
