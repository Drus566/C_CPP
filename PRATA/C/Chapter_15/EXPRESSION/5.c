#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

void show_bits(int);
void rotate_l(int, int);

int main(int argc, char * argv[])
{
	int num = 255;
	int shift = 4; 
	show_bits(num);
	rotate_l(num, shift);

	return 0; 
}

void rotate_l(int num, int shift)
{
	int left_mask = 2147483648;
	int mask = 1;

	for (int i = 0; i < shift; i++)
	{
		if ((num & left_mask) == left_mask)
		{
			num <<= 1;
			num |= mask;
		}
		else
		{
			num <<= 1;
		}
		show_bits(num);
	}
}

void show_bits(int num)
{
	int mask = 1;
	
	int size = CHAR_BIT * sizeof(num);
	char bits[size + 1];
	
	for (int i = size - 1; i >= 0; --i)
	{
		bits[i] = (mask & num) + '0';	
		num >>= 1;
	}
	bits[size] = '\0'; 
	
	// вывод
	int i = 0;
	while (bits[i])
	{
		putchar(bits[i]);
		if (++i % 4 == 0 && bits[i])
			putchar(' ');
	}
	putchar('\n');
}
