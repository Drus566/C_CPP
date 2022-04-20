#define B "booboo"
#define X 10
#include <stdio.h>
int main(void)
{
	int age;
	char name[40];
	printf("Введите имя: ");
	scanf("%s", name);
	printf("Хорошо, %s, сколько вам лет?\n", name);
	scanf("%d", &age);
	int xp = age + X;
	printf("Неужели, %s! Вам должно быть по меньшей мере %d.\n", B, xp);
	return 0;
}
