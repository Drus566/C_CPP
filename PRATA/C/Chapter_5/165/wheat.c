#include <stdio.h>
#define SQUARES 64
int main(void)
{
	const double CROP = 2E16; // Мировой урожай пшеницы в зернах
	double current, total;
	int count = 1;
	printf("Квадрат    добавлено   итого     ");
	printf("процент от \n");
	printf("        зерен       зерен     ");
	printf("мирового урожая\n");
	total = current = 1.0; // Начинаем с одного зернышка
	printf("%4d %13.2e %12.2e %12.2e\n", count, current,
	        total, total/CROP);
	while (count < SQUARES)
	{
		count = count + 1;
		current = 2.0 * current; /* Удвоить количество зерен на следующей клетке */
		total = total + current; /* обновить итоговую сумму */
		printf("%4d %13.2e %12.2e %12.2e\n", count, current, total, total/CROP);
	}
	printf("Вот и все.\n");
	return 0;
}
