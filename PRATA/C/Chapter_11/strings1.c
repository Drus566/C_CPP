#include <stdio.h>
#define MSG "Я - символьная строковая константа"
#define MAXLENGTH 81

int main(void)
{
	char words[MAXLENGTH] = "Я являюсь строкой, хранящейся в массиве";
	const char * pt1 = "Что то указывает на меня.";
	puts("Вот несколько строк:");
	puts(MSG);
	puts(words);
	puts(pt1);
	words[14] = 'ф';
	puts(words);

	return 0;
}
