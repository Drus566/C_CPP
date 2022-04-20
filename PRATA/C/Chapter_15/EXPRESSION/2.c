#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

void itobits(unsigned int num);
unsigned char convert(char *);

int check_digit(char *);

int main(int argc, char * argv[])
{
	if (argc == 3)
	{
		if (check_digit(argv[1]) && check_digit(argv[2]))
		{
			int size1 = strlen(argv[1]);
			int size2 = strlen(argv[2]);

			char bits1[size1];
			char bits2[size2];

			strcpy(bits1, argv[1]);
			strcpy(bits2, argv[2]);
			
			unsigned int n_bits1;
			unsigned int n_bits2;

			n_bits1 = convert(bits1);
			n_bits2 = convert(bits2);

			itobits(n_bits1);
			itobits(n_bits2);
			
			printf("n_bits1: %d\n", n_bits1); 
			printf("n_bits2: %d\n", n_bits2); 
		}
		else
		{
			printf("Введены некорректные данные, введите число в двоичном представлении\n");
		}
	} 
	else
	{
		printf("Введены некорректные данные, введите числа в двоичном представлении\n");
	}

	return 0; 
}

//int main(void)
//{
//	char * pbin = "01001001";
//	int i = 0;
//	while (pbin[i])
//	{
//		printf("%c", pbin[i]);
//		++i;
//	}
//	printf("\n");
//	unsigned char result;
//	result = convert(pbin);
//	printf("\nRESULT\n");
//	itobits(result);
//	printf("Число %d\n", result);
//
//	return 0; 
//}

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

unsigned char convert(char * pbin)
{
	int size = sizeof(unsigned int);
	unsigned int byte = 0;
	unsigned int mask = 1;

	for (int i = 0; i < size; i++)
	{
		if (*(pbin + i) == '1')
			byte |= mask;

		if (i != size - 1)
			byte <<= 1;
	}

	return byte;
}

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
