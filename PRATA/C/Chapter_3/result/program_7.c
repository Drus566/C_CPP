#include <stdio.h>
int main(void)
{
	float centimeter_in_inch = 2.54;
	int inch;
	printf("Введите рост в дюймах: ");
	scanf("%d", &inch);
	printf("\nВведенный рост переведенный в сантиметры: %.3f\n", inch * centimeter_in_inch);	
}
