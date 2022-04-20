#include <stdio.h> 

double sample (double fst, double scd);
double sample_1 (double fst, double scd);
double sample_2 (double fst, double scd);
double sample_3 (double fst, double scd);

int main(void)
{
	double (*ptr[4])(double, double);
	ptr[0] = sample;
	ptr[1] = sample_1;
	ptr[2] = sample_2;
	ptr[3] = sample_3;

	ptr[0](10.0, 2.5);

	for (int i = 0; i < 4; ++i)
	{
		double result = ptr[i](10.0, 2.5);
		printf("ptr[i]() result %i: %f\n", i, result);

		printf("\n");
		result = (*ptr[i])(10.0, 2.5);
		printf("(*ptr[i])() result %i: %f\n", i, result);
	}

	return 0;
}

double sample (double fst, double scd) { return fst+scd; }
double sample_1 (double fst, double scd) { return fst-scd; }
double sample_2 (double fst, double scd) { return fst*scd; }
double sample_3 (double fst, double scd) { return fst/scd; }
