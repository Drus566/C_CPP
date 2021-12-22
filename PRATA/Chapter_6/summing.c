#include <stdio.h>
int main(void)
{
	long num;
	// 0 типа L - long 
	long sum = 0L;
	int status;
	
	printf("Введите целое число для последующего суммирования ");
	printf("(или q для завершения программы): ");
	while (scanf("%ld", &num) == 1) 
	{
		sum = sum + num;
		printf("Введите следующее целое число (или q для завершения программы): ");
	}
	printf("Сумма введенных целых чисел равна %ld.\n", sum);

	return 0;
}
