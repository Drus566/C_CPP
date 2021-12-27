#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

int check_bit_on_pos(int num, int pos);

int main(int argc, char * argv[])
{
	int num = 2022;
	int pos = 2;
	int result;
	result = check_bit_on_pos(num, pos);
	printf("NUM: %d, POS: %d, RESULT: %d\n", num, pos, result);
	return 0; 
}

int check_bit_on_pos(int num, int pos)
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
	int i = 0;
	while (bits[i])
	{
		putchar(bits[i]);
		if (++i % 4 == 0 && bits[i])
			putchar(' ');
	}
	putchar('\n');

	if (bits[size - 1 - pos] == '0')
		return 0; 
	else
		return 1;
}

