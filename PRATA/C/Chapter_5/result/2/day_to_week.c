#include <stdio.h>
#define DAYS_IN_WEEK 7

int main(void)
{
	int week;
	int days;
	int d_days;
	printf("Введите количество дней: ");
	scanf("%d", &days);
	while (days > 0)
	{
		week = days / DAYS_IN_WEEK;
		d_days = days % DAYS_IN_WEEK;
		printf("%d дней(день), соответсвтует %d неделям(неделе) и %d дням(дню)\n",
						days, week, d_days);
		scanf("%d", &days);
	}
	
	return 0;
}
