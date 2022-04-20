#include <stdio.h>

void print_menu();
int max_min(int, int);

int main(void)
{
	print_menu();
	max_min(0, 10);
	return 0;
}

void print_menu()
{
	printf("1) копировать файлы	2) переместить файлы\n");
	printf("3) удалить файлы		4) выйти из программы\n");
	printf("Введите номер выбранного варианта: ");

	int x;

	while (scanf("%d", &x) != 1)
	{
		scanf("%*s");
	}
}

int max_min(int min, int max)
{
	int x;
	while (scanf("%d", &x) != 1 || (x < min || x > max))
	{
		print_menu();
		scanf("%*s");
	}
	return x;
}
