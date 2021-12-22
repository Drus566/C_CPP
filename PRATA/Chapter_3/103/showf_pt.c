#include <stdio.h>
int main(void)
{
	float aboat = 32000.0;
	double abet = 2.14e9;
	long double dip = 5.32e-5;
	float toobig = 3.4E38 * 100.0f;


	printf("%f может быть записано как %e\n", aboat, aboat);
	printf("И его %a в шестнадцатиричной, представляющий степени 2, форме записи\n", aboat);
	printf("%f может быть записано как %e\n", abet, abet);
	printf("%Lf может быть записано как %Le\n", dip, dip);
	printf("%e\n", toobig);

	return 0;
}
