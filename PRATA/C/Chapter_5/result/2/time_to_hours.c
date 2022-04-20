#include <stdio.h>
#define M_IN_H 60

int main(void)
{
	unsigned int time;
	unsigned int hours;
	unsigned int minutes;

	printf("Введите время в минутах: ");
	scanf("%u", &time);
	while (time > 0)
	{
		hours = time / M_IN_H;
		minutes = time % M_IN_H;
		printf("%u минут(ы), соответствует %u часам(часу) %u минутам(минуте)\n",
				    time, hours, minutes);
		printf("Чтобы продолжить, введите минуты, чтобы закончить введите 0)\n");
		scanf("%u", &time);
	}
	return 0;
}
