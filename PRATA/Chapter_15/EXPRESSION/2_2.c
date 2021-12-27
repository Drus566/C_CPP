#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

int check_digit(char *);
unsigned int convert(char *, int);
void itobits(unsigned int num);
void action(unsigned int num1, unsigned int num2);

int main(int argc, char * argv[])
{
	int common_size = CHAR_BIT * sizeof(unsigned int);

	char bits1[common_size + 1];
	char bits2[common_size + 1];

	// создаем хранилище для чисел
	unsigned int n_bits1;
	unsigned int n_bits2;

	if (argc == 3)
	{
		strcpy(bits1, argv[1]);
		strcpy(bits2, argv[2]);
	}
	else 
	{
		printf("Enter data, first num in binary format:\n");
		scanf("%s", bits1);
		printf("Enter data, second num in binary format:\n");
		scanf("%s", bits2);
	}

	if (!check_digit(bits1) && !check_digit(bits1))
	{
		printf("Uncorrect data\n");
		return 0;
	}

	n_bits1 = convert(bits1, common_size);
	n_bits2 = convert(bits2, common_size);

	itobits(n_bits1);
	itobits(n_bits2);

	action(n_bits1, n_bits2);

	return 0; 
}

// преобразование числа в двоичное представление строки и вывод
void itobits(unsigned int num)
{
	int size = CHAR_BIT * sizeof(num);
	int mask = 1;
	char bits[size + 1];

	for (int i = size - 1; i >= 0; --i)
	{
		bits[i] = (mask & num) + '0';	
		num >>= 1;
	}
	bits[size + 1] = '\0'; 

	int i = 0;
	while (bits[i])
	{
		putchar(bits[i]);
		if (++i % 4 == 0 && bits[i])
			putchar(' ');
	}
	putchar('\n');
}

// конвертация в число
unsigned int convert(char * pbin, int size)
{
	unsigned int byte = 0;
	unsigned int mask = 1;

	int i = 0;

	while(pbin[i])
	{
		byte <<= 1;

		if (pbin[i] == '1')
			byte |= mask;

		++i;
	}

	return byte;
}

// проверка на цифру
int check_digit(char * ptr)
{
	int i = 0;

	while (ptr[i])
	{
		if (!isdigit(ptr[i]))
			return 0;
		++i;
	}

	return 1;
}

void action(unsigned int num1, unsigned int num2)
{
	printf("~num1\n"); 
	itobits(~num1);

	printf("~num2\n"); 
	itobits(~num2);

	printf("num1 & num2\n"); 
	itobits(num1 & num2);

	printf("num1 | num2\n"); 
	itobits(num1 | num2);

	printf("num1 ^ num2\n"); 
	itobits(num1 ^ num2);
}
