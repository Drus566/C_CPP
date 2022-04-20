#include <stdio.h>
int main(void)
{
	int age = 20;
	while (age++ <= 65)
	{
		if ((age % 20) == 0)
			printf("Вам %d. Вас повысили в должности.\n", age);
		if (age == 65)
			printf("Вам %d. Получите свои золотые часы.\n", age);
	}
	return 0;
}
