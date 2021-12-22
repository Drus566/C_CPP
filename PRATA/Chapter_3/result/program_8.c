#include <stdio.h>
int main(void)
{
	float cup;

	printf("Введите объем в чашках: ");
	scanf("%f", &cup);
	printf("Количество чашек %.2f, равно следующему количеству", cup);
	printf("\nпинт: %.2f", cup * 2);
	printf("\nунц: %.2f", cup / 8);
	printf("\nстоловых ложек: %.2f", (cup / 8) / 2);
	printf("\nчайных ложек: %.2f\n", ((cup / 8) / 2) / 3);
}

