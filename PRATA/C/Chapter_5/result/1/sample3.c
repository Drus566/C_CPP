#include <stdio.h>

int main(void)
{
	int i = 1;
	double n;
	printf("GGWP\n");
	while (++i < 30)
	{
		n = 1.0 / i;
		printf("%f\n", n);
	}
	printf("END\n\n");
	return 0;
}

