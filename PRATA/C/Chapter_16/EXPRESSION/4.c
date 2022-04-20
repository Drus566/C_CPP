#include <stdio.h> 
#include <time.h>
// возвращает процессорное время в единицах
clock_t clock(void);
// количество процессорного времени в секунде
// CLOCKS_PER_SEC

void diff(float t);

int main(void)
{
	float sec = 10;
	diff(sec);
	return 0; 
}

void diff(float t)
{
	long int delay = t * CLOCKS_PER_SEC;
	printf("Старт счетчика\n");

	double start = clock();
	while ((clock() - start) < delay);
	printf("Прошло %.2f секунд, %.2ld тактов\n", t, delay);
}


