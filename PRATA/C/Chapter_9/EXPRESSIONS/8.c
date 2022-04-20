#include <stdio.h>

double power(double number, int exponent);

int main(void)
{
	printf("10, 5 %.2f\n", power(10, 5));
	printf("0, -1 %.2f\n", power(0, -1));
	printf("0, 0 %.2f\n", power(0, 0));
	printf("0, 2 %.2f\n", power(0, 2));
	printf("3, -3 %.2f\n", power(3, -3));
	return 0;
}

double power(double number, int exponent)
{
	int temp_exponent = exponent;
	double temp_number = number;
	double result;

	if (exponent < 0)
	{
		temp_exponent = exponent * -1;
	}

	for (int i = 1; i < temp_exponent; i++)
	{
		temp_number *= number;
	}

	if (number == 0 && exponent >= 1)
	{
		result = 0;
	}
	else if (number == 0 && exponent < 1)
	{
		printf("Значение не определено\n");
		result = -1;
	}
	else if (number != 0 && exponent < 0)
	{
		result = 1 / temp_number;
	}
	else if (exponent == 0)
	{
		result = 1;
	}
	else if (exponent > 0)
	{
		result = temp_number;
	}	

	return result;
}
