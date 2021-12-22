#include <stdio.h>
int main(void)
{
	float number_with_dot;
	printf("Введите значение с плавающей точкой: ");
	scanf("%f", &number_with_dot);
	printf("\nЗапись с фиксированной запятой: %f", number_with_dot);
	printf("\nЭкспоненциальная форма записи: %e", number_with_dot);
	printf("\nДвоично-экспоненциальное представление: %a\n", number_with_dot);
	return 0;
}
