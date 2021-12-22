#include <stdio.h>

char get_first(void);
char get_choice(void);
float get_number(void);
void calculate(char op);
void print_menu(void);

int main(void)
{
	int choice;
	char op;

	// получаем символ
	while ((choice = get_choice()) != 'e')
	{
		// делаем выбор операции
		switch (choice)
		{
			case 'a':
				op = 'a';	
				break;
			case 'b':
				op = 'b';	
				break;
			case 'c':
				op = 'c';	
				break;
			case 'd':
				op = 'd';	
				break;
		}

		calculate(op);
	}

	return 0;
}


void calculate(char op)
{
	printf("Введите первое число\n");
	float first_n = get_number();
	printf("Введите второе число\n");
	float second_n = get_number();

	switch (op)
	{
		case 'a':
			printf("%.1f + %.1f = %.1f\n", first_n, second_n, first_n + second_n);
			break;
		case 'b':
			printf("%.1f - %.1f = %.1f\n", first_n, second_n, first_n - second_n);
			break;
		case 'c':
			printf("%.1f * %.1f = %.1f\n", first_n, second_n, first_n * second_n);
			break;
		case 'd':
			while (second_n == 0)
			{
				printf("Введите число отличное от 0\n");
				second_n = get_number();
			}
			printf("%.1f / %.1f = %.1f\n", first_n, second_n, first_n / second_n);
			break;
	}
}

float get_number(void)
{
	float number;

	while (scanf("%f", &number) != 1)
	{
		printf("Некорректный ввод\n");
		printf("Попробуйте снова ввести число...\n");
		while (getchar() != '\n')
			continue;
	}

	while (getchar() != '\n')
		continue;
		
	return number;
}

void print_menu(void)
{
	printf("Выберите желаемую операцию:\n");
	printf("a. сложение			b. вычитание\n");
	printf("c. умножение			d. деление\n");
	printf("e. завершение\n");
}

char get_choice(void)
{
	print_menu();

	char ch = get_first();
	while (ch != 'a' && ch != 'b' && ch != 'c' && ch != 'd' && ch != 'e')
	{
		printf("Выберите a, b, c, d, e\n");
		ch = get_first();
	}
	return ch;
}

char get_first(void)
{
	char ch;
	ch = getchar();

	while (getchar() != '\n')
		continue;
	return ch;
}
