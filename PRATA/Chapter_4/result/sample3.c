#include <stdio.h>
int main(void)
{
	printf("%4X\n", 0x8A);
	printf("%10.3f\n", 232.346);
	printf("%12.2e\n", 233);
	printf("%-30s\n", "ggwp");
	printf("*%15lu*\n", 123333333);

	printf("%#4x\n", 0x8a);
	printf("*%-12.2E*\n", 234);
	printf("*%-+10.3f*\n", 233);
	printf("*%8.8s*\n", "123456789");

	printf("*%6.4d*\n", 12400);
	printf("*%*o*\n", 4, 7);
	printf("*%2c*\n", 'g');
	printf("%+0.2f\n", 3.0);
	printf("%-7.5s\n", "GGWPBRO");
	return 0;
}

