#include <stdio.h>

#define MSG "Я особенный"

int main()
{
	char ar[] = MSG;
	const char *pt = MSG;

	printf("адрес \"Я особенный.\": %p \n", "Я особенный.");
	printf("                   адрес ar: %p\n", ar);
	printf("                   адрес pt: %p\n", pt);
	printf("                   адрес MSG: %p\n", MSG);
	printf("адрес \"Я особенный.\": %p \n", "Я особенный.");

	return 0;
}
