#include <stdio.h>
int main(void)
{
	int guess = 1;
	printf("Выберите целое число в интервале от 1 до 100. Я попробую угадать ");
	printf("его.\nНажмите клавишу y, если моя догадка верна и ");
	printf("\nклавишу n в противном случае.\n");
	printf("Вашим числом является %d?\n", guess);
	char response;
	while ((response = getchar()) != 'y') 
	{
		if (response == 'n')
			printf("Ладно, тогда это %d?\n", ++guess);
		else
			printf("Принимаются только варианты y или n.\n");
		while (getchar() != '\n')
			continue;
	}

	printf("Я знал, что у меня получится!\n");
	return 0;
}
