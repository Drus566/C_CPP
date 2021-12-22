#include <stdio.h>
int main(void)
{
	float t_float;
	char name[40];

	printf("Введите рост в дюймах и имя: ");
	scanf("%f %s", &t_float, name);
	printf("%s, ваш рост составляет %.3f сантимов\n", name, t_float / 3.2);

	return 0;
}
