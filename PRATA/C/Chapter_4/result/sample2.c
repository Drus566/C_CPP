#include <stdio.h>
#define BOOK "\"Война и мир\""
int main(void)
{
	float cost = 12.99;
	float percent = 80.0;

	printf("Данный экземпляр книги %s стоит $%.2f\
\nЭто %.1f%% от цены в прайс листе.\n", BOOK, cost, percent); 
	return 0;
}
