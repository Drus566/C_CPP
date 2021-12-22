#include <stdio.h>
int main(void)
{
	int top = 101;
	int bottom = 0;
	int guess = 50;
	printf("Выберите целое число в интервале от 1 до 100. Я попробую угадать ");
	printf("его.\nНажмите клавишу y, если моя догадка верна и ");
	printf("\nклавишу '>' в если случае если больше, и '<' в случае если меньше.\n");
	printf("Вашим числом является %d?\n", guess);
	char response;

	while ((response = getchar()) != 'y') 
	{

		if (response == EOF)
			return 0;

		if (response == '<')
		{
			top = guess;
			guess -= (top - bottom) / 2;
			printf("Ладно, тогда это %d?\n", guess);
		} 
		else if (response == '>')
		{
			bottom = guess;
			guess += (top - bottom) / 2;
			printf("Ладно, тогда это %d?\n", guess);
		}
		else
			printf("Некорректный ввод\n");

		while (getchar() != '\n')
			continue;
	}

	printf("Я знал, что у меня получится!\n");
	return 0;
}

