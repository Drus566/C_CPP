#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define SIZE 8

void itobits(unsigned char num);
unsigned char convert(char *);

int main(void)
{
	char * pbin = "01001001";
	unsigned char result;
	result = convert(pbin);
	itobits(result);
	printf("%d\n", result);
	return 0; 
}

void itobits(unsigned char num)
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

	printf("7654 3210\n|||| ||||\n");
	int i = 0;
	while (bits[i])
	{
		putchar(bits[i]);
		if (++i % 4 == 0 && bits[i])
			putchar(' ');
	}
	putchar('\n');
}

unsigned char convert(char * pbin)
{
	int size = sizeof(unsigned char);
	unsigned char byte = 0;
	unsigned char mask = 128;

	for (int i = 0; i < SIZE; i++, byte >>= 1)
	{
		if (*(pbin + i) == '1')
		{
			byte |= mask;
		}
	}

	return byte;
}
