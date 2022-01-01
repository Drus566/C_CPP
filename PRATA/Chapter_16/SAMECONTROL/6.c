#include <stdio.h> 
#define CONST 25
#define SPACE ' '
#define PS(X) printf("SPACE FROM PS '%c'\n", X);
#define BIG(X) (3 + (X))
#define SUBSQ(X, Y) (((X) * (X)) + ((Y) * (Y)))

int main(void)
{
	printf("CONST %d\n", CONST);
	printf("SPACE '%c'\n", SPACE);
	PS(SPACE);
	printf("BIG %d\n", BIG(CONST));
	printf("SUBSQ %d\n", SUBSQ(CONST, CONST));
	return 0;
}
