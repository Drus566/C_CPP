#include <stdio.h>

int to_base_n(int number, int base);

int main(void)
{
	to_base_n(672, 8);
	return 0;
}

int to_base_n(int number, int base)
{
	if (base < 2 || base > 8)
	{
		printf("Неверное основание\n");
		return -1;
	}
	else if (number < base)
	{
		printf("%d\n", number % base);
		return 0;
	}

	printf("%d\n", number % base);
	return to_base_n(number / base, base);
}

