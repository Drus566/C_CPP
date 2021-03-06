#include <stdio.h>
#define FUNDLEN 50

struct funds {
	char bank[FUNDLEN];
	double bankfund;
	char save[FUNDLEN];
	double savefund;
};

double sum(const struct funds *); // аргумент является указателем

int main(void)
{
	struct funds stan = {
		"Garlic-Melon Bank",
		4032.27,
		"Lucky's Saving and Loan",
		8543.94
	};
	printf("Общая сумма на счетах у Стэна составляет $%.2f.\n", sum(&stan));
	return 0; 
}

// суммирование двух чисел типа double
double sum(const struct funds * money)
{
	return(money->bankfund + money->savefund);
}

