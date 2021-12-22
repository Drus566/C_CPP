
#include <stdio.h>
int main(void)
{
	int num = 0;
	for (printf("Продолжайте вводить числа!\n"); num != 6; )
		scanf("%d", &num);
	printf("Вот то число, которое было нужно!\n");
	return 0;
}
