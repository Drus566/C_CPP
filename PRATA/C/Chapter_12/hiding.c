#include <stdio.h>
int main() {
	int x = 30;
	printf("x во внешнем блоке: %d по адресу %p\n", x, &x);
	{
		int x = 77; // новая переменная x, скрывающая первую x
		printf("x во внутреннем блоке: %d по адресу %p\n", x, &x);
	}

	printf("x во внешнем блоке: %d по адресу %p\n", x, &x);
	while (x++ < 33) // исходная перменная x
	{
		int x = 100; // новая переменная x, скрывающая первую x
		x++;
		printf("x в цикле while: %d по адресу %p\n", x, &x);
	}

	printf("x во внешнем блоке: %d по адресу %p\n", x, &x);
	return 0;
}

