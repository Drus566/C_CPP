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

	for (int i = 0; i < MONTH_LEN; ++i) {
		printf("\nMonth name: %s\n", month[i].name);
		printf("Month abberviation: %s\n", month[i].abbrev);
		printf("Month days: %d\n", month[i].days);
		printf("Month number: %d\n", month[i].number);
	}
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
