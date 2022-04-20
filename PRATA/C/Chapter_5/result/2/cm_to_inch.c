#include <stdio.h>
#define CM_IN_FEET 30.48
#define CM_IN_INCH 2.54

int main(void)
{
	float inch;
	float feet;
	float cm;
	printf("Введите высоту в сантиметрах\n");
	scanf("%f", &cm);
	while (cm >= 0)
	{
		inch = cm / CM_IN_INCH;
		feet = cm / CM_IN_FEET;
		printf("%.2f сантиметров(сантиметр) соответствует %.2f дюймам(дюйму), а также"
				" соответствует %.2f футам(футу)\n",
			  cm, inch, feet);
		printf("Введите высоту в сантиметрах... или отрицательное значение для выхода\n");
		scanf("%f", &cm);	
	}
	return 0;
}
