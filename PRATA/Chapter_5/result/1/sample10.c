#define MESG "COMPUTER BYTES DOG"
#include <stdio.h>

int main(void)
{
	int n = 0;
	while (n < 5)
		printf("%s\n", MESG);
		n++;
	printf("На этом все.\n");
	return 0;
}
