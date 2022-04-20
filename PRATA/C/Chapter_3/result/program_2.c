#include <stdio.h>
int main(void)
{
	int code;
	printf("Введите код символа: ");
	scanf("%d", &code);
	printf("Символ по коду %d равен %c\n", code, code);
}

