#include <stdio.h>

double number_to_cube(double);

int main(void)
{
	double input;
	printf("Введите число в формате double: ");
	scanf("%lf", &input);
	printf("Куб этого числа: %.4f\n", number_to_cube(input));
	return 0;
}

double number_to_cube(double number)
{
	double result = number * number * number;
	return result;
}
