#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define SIZE 8

void itobits(unsigned char num);
unsigned char convert(char *);

int main(void)
{
	char * pbin = "01001001";
	int i = 0;
	while (pbin[i])
	{
		printf("%c", pbin[i]);
		++i;
	}
	printf("\n");
	unsigned char result;
	result = convert(pbin);
	printf("\nRESULT\n");
	itobits(result);
	printf("Число %d\n", result);

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
	unsigned char byte = 0;
	unsigned char mask = 1;

	for (int i = 0; i < SIZE; i++)
	{
		printf("\nI: %d\n", i);
		if (*(pbin + i) == '1')
		{
			printf("BIT 1\n");
			byte |= mask;
		}
		else
		{
			printf("BIT 0\n");
		}
		itobits(byte);

		if (i != 7)
			byte <<= 1;
	}

	return byte;
}
