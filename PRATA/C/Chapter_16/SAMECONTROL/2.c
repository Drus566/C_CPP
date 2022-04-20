#include <stdio.h> 
#define FPM 5280
#define FEET 4
#define POD FEET + FEET
#define SIX 6;
#define NEW(X) ((X) + 5)

int main(void)
{
	double dist;
	double miles = 200;
	dist = FPM * miles;
	printf("dist %.2f\n", dist);

	double plort;
	plort = FEET * POD;
	printf("plort %.2f\n", plort);

	double nex;
	nex = SIX;
	printf("nex %.2f\n", nex);

	double y = 0.25;
	double berg = 1;
	double lob = 2;
	double est, nilp;
	y = NEW(y);
	printf("y %.2f\n", y);
	berg = NEW(berg) * lob;
	printf("berg %.2f\n", berg);
	est = NEW(berg) / NEW(y);
	printf("est %.2f\n", est);
	nilp = lob * NEW(-berg);
	printf("nilp %.2f\n", nilp);
	return 0;
}
