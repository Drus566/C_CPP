#include <stdio.h>

int main(void)
{
	int mod_value;
	int value;
	printf("Введите целочисленное значение, он будет в качестве делителя в операции\n"
			"деления по модулю: ");
	scanf("%d", &mod_value);
	printf("Введите делимое: ");
	scanf("%d", &value);

	while (value > 0)
	{
		int result;
		result = value % mod_value;	
		printf("Результат деления по модулю %d на %d равен %d\n", value, mod_value, result);
		printf("Введите делимое, либо число <= 0 для выхода...\n");
		scanf("%d", &value);
	}
	return 0;
}
