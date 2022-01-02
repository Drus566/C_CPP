#include <stdio.h> 
#include <math.h> 
#define GARM(X,...) (X / (__VA_ARGS__))

typedef struct polar_v {
	double magnitude;
	double angle;
} Polar_V;

typedef struct rect_v {
	double x;
	double y;
} Rect_V;

Rect_V polar_to_rect(Polar_V);

int main(void)
{
	Polar_V input;
	Rect_V result;
	
	puts("Введите magnitude и angle; введите q для выхода:");
	while (scanf("%lf %lf", &input.magnitude, &input.angle) == 2)
	{
		result = polar_to_rect(input);
		printf("X: %0.2f, Y: %0.2f\n", result.x, result.y);
	}

	printf("Программа завершена\n");
	return 0; 
}

Rect_V polar_to_rect(Polar_V pv)
{
	Rect_V rv;

	rv.x = pv.magnitude * cos(pv.angle);
	rv.y = pv.magnitude * sin(pv.angle);

	return rv;
}

