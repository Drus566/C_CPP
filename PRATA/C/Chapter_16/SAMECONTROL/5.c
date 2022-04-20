#include <stdio.h> 
#define VIEW(X) printf(#X " = %d\n", X); 

int main(void)
{
	VIEW(3 + 4);
	VIEW(4 * 12);
	return 0;
}
