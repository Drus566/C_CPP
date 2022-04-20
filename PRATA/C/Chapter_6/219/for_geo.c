#include <stdio.h>
int main(void)
{
	double debt;
	for (debt = 100.0; debt < 150.0; debt = debt * 1.1)
		printf("Теперь ваша задолженность составляет $%.2f.\n", debt);
	return 0;
}
