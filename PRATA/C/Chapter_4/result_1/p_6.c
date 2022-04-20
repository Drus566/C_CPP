#include <stdio.h>

int main(void)
{
	char name[40];
	char uname[40];
	printf("Введите имя и фамилию: ");
	int length = scanf("%s %s", name, uname);
	printf("*%10s %10s*\n", name, uname);
	printf("*%10zd %10zd*\n", sizeof name, sizeof uname);
	return 0;
}
