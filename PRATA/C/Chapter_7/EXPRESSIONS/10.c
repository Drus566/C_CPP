#include <stdio.h>
#include <unistd.h>

#define base_tax 0.15
#define over_tax 0.28

#define alone_tax_wage 17850
#define head_tax_wage 23900
#define married_cooperative_tax_wage 29750
#define married_separate_tax_wage 14875

void print_options(void);

int main(void)
{

	print_options();

	char ch;
	while ((ch = getchar()) != 'q')
	{
		// граница облагаемой суммы
		float tax_wage;

		switch (ch)
		{
			case '1':
				tax_wage = alone_tax_wage;
				break;
			case '2':
				tax_wage = head_tax_wage;
				break;
			case '3':
				tax_wage = married_cooperative_tax_wage;
				break;
			case '4':
				tax_wage = married_separate_tax_wage;
				break;
			default:
				print_options();
				continue;
		}

		// заработок
		float pay;
		printf("Сколько вы зарабатываете?\n");

		int nxt = scanf("%f", &pay);
		if (nxt != 1 || pay <= 0)
		{
			printf("Введено некорректное значение, попробуйте заново\n\n");
			continue;
		}

		// налог 
		float tax; 

		if (pay > tax_wage)
		{
			// базовый налог
			tax = tax_wage * base_tax;
			// сверх базовая сумма
		 	float over_wage = pay - tax_wage;	
			// налог сверх базовой суммы
			tax += over_wage * over_tax; 
		} 
		else 
		{
			tax = base_tax * pay;
		}

		printf("\n*************************************************");
		printf("\nДоход до вычета налогов: %f\n", pay);
		printf("Доход после вычета налогов: %f\n", pay - tax);
		printf("Сумма налога: %f\n", tax);
		printf("*************************************************\n\n");

		sleep(2);

		print_options;
	}

	return 0;
}

void print_options(void)
{
	printf("Выберите категорию: \n");
	printf("1) Одинокий		2) Глава семейства\n");
	printf("3) Состоит в браке, совместное ведение хозяйства\n");
	printf("4) Состоит в браке, раздельное ведение хозяйства\n");
	printf("Или нажмите q для выхода\n");
}
