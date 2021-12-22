#include <stdio.h>
#define SLEN 40
#define LIM 5

int main(void)
{
	const char *mytalents[LIM] = {
		"Мгновенное складывание чисел",
		"Точное умножение", "Накапливание данных",
		"Исполнение инструкций с точностью до буквы",
		"Знание языка программирования С"
	};

	char yourtalents[LIM][SLEN] = {
		"Хождение по прямой",
		"Здоровый сон", "Просмотр телепередач",
		"Рассылка писем", "Чтение электронной почты"
	};
	int i;
	puts("Сравним наши таланты.");
	printf("%-52s\n %-25s\n", "Мои таланты", "Ваши таланты");
	for (i = 0; i < LIM; i++)
		printf("%-50s\n %-50s\n", mytalents[i], yourtalents[i]);
	printf("\nразмер mytalents: %zd, размер yourtalents: %zd\n",
			sizeof(mytalents), sizeof(yourtalents));
	return 0;
}
