// 15.1
#include <stdio.h>
#include <limits.h> // для CHAR_BIT количество битов на символ

char * itobs(int, char *);
void show_bstr(const char *);
int invert_end(int num, int bits);

int main(void)
{
	char bin_str[CHAR_BIT * sizeof(int) + 1];
	int number;

	puts("Вводите целые числа и просматривайте их двоичные представления.");
	puts("Нечисловой ввод завершает программу.");

	while (scanf("%d", &number) == 1)
	{
		itobs(number, bin_str);
		printf("%d представляются как ", number);
		show_bstr(bin_str);
		putchar('\n');
		number = invert_end(number, 4);
		printf("Инвертирование последних 4 битов дает\n");
		show_bstr(itobs(number,bin_str));
		putchar('\n');
	}
	puts("Программа завершена\n");
	return 0;
}

char * itobs(int n, char * ps)
{
	int i;
	const static int size = CHAR_BIT * sizeof(int);

	for (i = size - 1; i >= 0; i--, n >>= 1 )
		ps[i] = (01 & n) + '0'; // предполагается кодировка ASCII или похожая 
	ps[size] = '\0';
	return ps;
}

void show_bstr(const char * str)
{
	int i = 0;
	while (str[i])
	{
		putchar(str[i]);
		if (++i % 4 == 0 && str[i])
			putchar(' ');
	}
}

int invert_end(int num, int bits)
{
	int mask = 0;
	int bitval = 1;

	while (bits-- > 0)
	{
		mask |= bitval;
		bitval <<= 1;
	}
	return num ^ mask;
}
