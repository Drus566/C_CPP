#include <stdio.h>
#define STLEN 4 
int main(void)
{
	char words[STLEN];
	puts("Введите строку.");
	gets(words);
	printf("Ваша строка, выведенная дважды:\n");
	printf("%s\n", words);
	puts(words);
	puts("Готово.");
	return 0;
}
