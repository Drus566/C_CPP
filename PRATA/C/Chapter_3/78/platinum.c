#include <stdio.h>
int main(void)
{
	float weight;
	float value;

	printf("Вес в платиновом эквиваленте\n");
	printf("Введите вес в фунтах: \n");
	scanf("%f", &weight);
	value = 1700.0 * weight * 14.5833;
	printf("Вес в платиновом эквиваленте $%.2f.\n", value);
	return 0;
}
