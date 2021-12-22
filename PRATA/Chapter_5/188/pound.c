#include <stdio.h>
void pound(int n); // Объявление прототипа функции согласно стандарту ANSI
int main(void)
{
	int times = 5;
	char ch = '!'; // ASCII-код равен 33
	float f = 6.0f;
	pound(times); // аргумент типа int
	pound(ch); // эквивалентно pound((int)ch);
	pound(f); // эквивалентно pound((int)f);

	return 0;
}

void pound(int n)
{
	while (n-- > 0)
		printf("#");
	printf("\n");
}
