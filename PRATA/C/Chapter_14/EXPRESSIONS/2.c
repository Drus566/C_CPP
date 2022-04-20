#include <stdio.h> 
#include <string.h>

#define LEN 40
#define MONTH_LEN 12

void get_abbr(const char * str, char * abbr);

struct month_sign {
	char name[LEN];
	char abbrev[3];
	int days;
	int number;
};

const char * months[MONTH_LEN] = { "junuary", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december" };

const int months_days[MONTH_LEN] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int main(void)
{
	struct month_sign month[MONTH_LEN];  
	char abbr[3];

	for (int i = 0; i < MONTH_LEN; ++i) {
		get_abbr(months[i], abbr);

		strcpy(month[i].name, months[i]);
		strcpy(month[i].abbrev, abbr);
		month[i].days = months_days[i];
		month[i].number = i + 1;
	}
	
	int enter_day;
	char enter_month[30];
	int enter_year;

	int month_number = -1;
	int day_work = -1;

	printf("Введите месяц: ");
	scanf("%s", enter_month); 

	printf("Введите день: ");
	scanf("%d", &enter_day); 

	printf("Введите год: ");
	while (scanf("%d", &enter_year) != 1 && enter_year < 2021) 
	{
		printf("Введите год: ");
	}	
	
	// поиск месяца
	for (int i = 0; i < MONTH_LEN; ++i)
	{
		printf("%s\n", month[i].name);
		if (strcmp(enter_month, month[i].name) == 0) 
		{
			month_number = month[i].number;
			break;	
		}
	}

	if (month_number < 0)
		return 0;

	int summ_days = 0;
	for (int i = 2021; i <= enter_year; ++i) 
	{
		if (enter_year == i)
		{
			for (int i = 0; i < month_number; ++i) 
			{
				if (month[i].number == month_number)
				{
					if (enter_day > month[i].days)
					{
						summ_days += month[i].days;	
					}	
					else
					{
						summ_days += enter_day;
					}
				}
				else
				{
					summ_days += month[i].days;	
				}
			}
		}	
		else
		{
			for (int i = 0; i < MONTH_LEN; ++i) 
			{
				summ_days += month[i].days;	
			}
		}
	}

	printf("Дней с %d месяца по %d месяц в количестве: %d\n", 1, month_number, summ_days);
	return 0; 
}

void get_abbr(const char * str, char * abbr)
{
	int i = 0;
	while (i < 3) 
	{
		*abbr = *str;
		++abbr;
		++str;
		++i;
	}
}
