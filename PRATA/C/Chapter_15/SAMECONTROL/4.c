#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

void itobits(char num);

int main(void)
{
	unsigned char byte;

	byte = ~0;
	printf("val = ~0: %d\n", byte);
	itobits(byte);

	byte = !0;
	printf("\n!0: %d\n", byte);
	itobits(byte);

	byte = 2 & 4;
	printf("\n2 & 4: %d\n", byte);
	itobits(byte);

	byte = 2 && 4;
	printf("\n2 && 4: %d\n", byte);
	itobits(byte);

	byte = 2 | 4;
	printf("\n2 | 4: %d\n", byte);
	itobits(byte);

	byte = 2 || 4;
	printf("\n2 || 4: %d\n", byte);
	itobits(byte);

	byte = 5 << 3;
	printf("\n5 << 3: %d\n", byte);
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
