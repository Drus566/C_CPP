#include <stdio.h>
int main(void)
{
	int age;
	float assets;
	char pet[30];

	printf("Введите информацию о своем возрасте, сумме в банке и любимом животным.\n");
	scanf("%d %f", &age, &assets);
	scanf("%s", pet);
	printf("%d $%.2f %s\n", age, assets, pet);

	return 0;
}
