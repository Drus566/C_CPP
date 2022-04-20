#include <stdio.h>
int main(void)
{
	long double mass_molecule = 3.0e-23;
	int quart = 950;
	unsigned long long quart_volume;
	printf("Введите объем воды в квартах: ");
	scanf("%llu", &quart_volume);
	printf("\nКоличество молекул воды в объеме в квартах %llu равно %Le\n", quart_volume, quart_volume * quart * mass_molecule);
}
	
