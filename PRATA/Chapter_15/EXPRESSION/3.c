#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

void check_on_bits(int num);

int main(int argc, char * argv[])
{
	int num = 2022;
	check_on_bits(num);
	return 0; 
}

void check_on_bits(int num)
{
	int size = CHAR_BIT * sizeof(num);
	int mask = 1;
	char bits[size + 1];

	for (int i = size - 1; i >= 0; --i)
	{
		bits[i] = (mask & num) + '0';	
		num >>= 1;
	}
	bits[size] = '\0'; 

	// вывод
	int count_on_bits = 0;
	int i = 0;
	while (bits[i])
	{
		if (bits[i] == '1')
			++count_on_bits;
			
		putchar(bits[i]);
		if (++i % 4 == 0 && bits[i])
			putchar(' ');
	}
	putchar('\n');
	printf("Count of enable bit: %d\n", count_on_bits);
}
