#include <stdio.h>
#include <limits.h>

void itobits(int num);

int main(void)
{
	int nums[] = {3,13,59,119};
	for (int i = 0; i < 4; i++) 
	{
		printf("\n%d\n", nums[i]);
		itobits(nums[i]);
	}

	return 0; 
}

void itobits(int num)
{
	int size = CHAR_BIT * sizeof(int);
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

