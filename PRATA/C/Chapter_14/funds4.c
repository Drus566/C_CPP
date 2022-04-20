#include <stdio.h> 
#define FUNDLEN 50
#define N 2

struct funds {
	char bank[FUNDLEN];
	double bankfund;
	char save[FUNDLEN];
	double savefund;
};

double sum(const struct funds money[], int n);

int main(void)
{
	struct funds jones[N] = {
		{
			"Garlic-Melon Bank",
			4032.28,
			"lucky",
			3212.3
		},
		{
			"Honest jone",
			3212.9,
			"Party hard",
			1213.1
		}
	};
	printf("Общая сумма на счетах у Джонсов составляет $%.2f.\n", sum(jones, N));

	return 0; 
}

double sum(const struct funds money[], int n)
{
	double total;
	int i;

	for (i = 0, total = 0; i < n; i++)
		total += money[i].bankfund + money[i].savefund;

	return(total);
}
