#include <stdio.h>
int main(void)
{
	char name[20];
	char uname[20];

	printf("Введите имя и фамилию: ");
	scanf("%s %s", name, uname);
	printf("\nПриветствую %s %s\n", uname, name);
}
