#include <stdio.h>

int main(void)
{
	int num;

  printf("Введите число \n");
  scanf("%d", &num);

	for (int div = 2; (div * div) <= num; div++)	
		if (num % div == 0)
			printf("%d делится на %d и %d\n", num, div, num / div);

  return 0;
}
