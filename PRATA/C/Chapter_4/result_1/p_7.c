#include <stdio.h>
#include <float.h>

int main(void)
{
	double d_test = 1.0/3.0;
	float f_test = 1.0/3.0;
	printf("%.4f, %.4f\n", d_test, f_test);
	printf("%.12f, %.12f\n", d_test, f_test);
	printf("%.16f, %.16f\n", d_test, f_test);
	printf("FLT_DIG %f, DBL_DIG %f\n", FLT_DIG, DBL_DIG);
	printf("1.0/0.3=%f\n", 1.0/0.3);

	return 0;
}
