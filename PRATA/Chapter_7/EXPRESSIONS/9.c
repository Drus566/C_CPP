#include <stdio.h>
#include <stdbool.h>

bool isPrime(int n);

int main(void)
{
	unsigned long num;

	printf("Введите целое число для анализа q.\n");
	scanf("%lu", &num);

	for (int i = 0; i <= num; i++)
	{
		if (isPrime(i))
			printf("%lu - простое число\n", i);
	}

	return 0;
}	


bool isPrime(int n)
{
	if (n > 1)
	{
		for (int i = 2; i < n; i++)
			if (n % i == 0)
				return false;	

		return true;
	}
	else
		return false;
}
			
