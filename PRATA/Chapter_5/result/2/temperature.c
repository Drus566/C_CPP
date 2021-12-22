#include <stdio.h>

void Temperatures(double);

int main(void)
{
	double t_fahrenheit;
	int t_bool;

	printf("Введите температуру по Фаренгейту: ");
	t_bool = scanf("%lf", &t_fahrenheit);
	
	while (t_bool == 1)
	{
		Temperatures(t_fahrenheit);		
		printf("Введите температуру по Фаренгейту или q для выхода: ");
		t_bool = scanf("%lf", &t_fahrenheit);
	}

	return 0;
}

void Temperatures(double value)
{
	float const c_const = 5.0;
	float const c_const1 = 9.0;
	float const c_const2 = 32.0;
	float const k_const = 273.16;
	
	double temp_by_celsia = c_const / c_const1 * (value - c_const2);
	double temp_by_celvin = temp_by_celsia + k_const;

	printf("%.2lf по Фаренгейту соответствует %.2lf по цельсия и %.2lf по кельвинам\n",
				 value, temp_by_celsia, temp_by_celvin);
}
