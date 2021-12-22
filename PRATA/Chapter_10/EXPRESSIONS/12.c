#include <stdio.h>
#define MONTHS 12
#define YEARS 5

int main(void)
{
	const float rain[YEARS][MONTHS] = 
	{
		{4.3,4.3,4.3,3.0,2.0,1.2,0.2,0.2,0.4,2.4,3.5,6.6},
		{4.3,4.3,4.3,3.0,2.0,1.2,0.2,0.2,0.4,2.4,3.5,6.6},
		{4.3,4.3,4.3,3.0,2.0,1.2,0.2,0.2,0.4,2.4,3.5,6.6},
		{4.3,4.3,4.3,3.0,2.0,1.2,0.2,0.2,0.4,2.4,3.5,6.6},
		{4.3,4.3,4.3,3.0,2.0,1.2,0.2,0.2,0.4,2.4,3.5,6.6}
	};

	int year, month;
	float subtot, total;

	printf("ГОД		КОЛИЧЕСТВО ОСАДКОВ (в дюймах)\n");

	float const (*start)[MONTHS] = rain;
	float const (*end)[MONTHS] =  rain + YEARS;

	// year = 0;
	// while (start < end)
	// {
	// 	float const * sub_start = *start;
	// 	float const * sub_end = *start + MONTHS;

	// 	subtot = 0;
	// 	while (sub_start < sub_end)
	// 	{
	// 		subtot += *sub_start;

	// 		sub_start++;
	// 	}
	// 	printf("%5d %15.1f\n", 2010 + year, subtot);
	// 	total += subtot;

	// 	start++;
	// 	year++;
	// }

	for (year = 0, total = 0; year < YEARS; year++)
	{
		for (month = 0, subtot = 0; month < MONTHS; month++)
			subtot += rain[year][month];
		printf("%5d %15.1f\n", 2010 + year, subtot);
		total += subtot; // общая сумма для всех лет
	}

	printf("\nСреднегодовое количество осадков составляет %.1f дюймов.\n\n", total/YEARS);
	printf("СРЕДНЕМЕСЯЧНОЕ КОЛИЧЕСТВО ОСАДКОВ:\n\n");
	printf(" Янв	Фев		Мар		Апр		Май		Июн		Авг		Сен		Окт");
	printf("	Ноя		Дек\n");
	for (month = 0; month < MONTHS; month++)
	{
		for (year = 0, subtot = 0; year < YEARS; year++)
			subtot += rain[year][month];
		printf("%4.1f ", subtot/YEARS);
	}
	printf("\n");
	return 0;
}

