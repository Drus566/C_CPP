#include <stdio.h> 
#ifndef PR_DATE
#define PR_DATE
#endif

#define PS(X) printf("имя: " #X "; значение: %d; адрес: %p\n", X , & X)

int main(void)
{
	#ifdef PR_DATE
		printf("%s\n", __DATE__);
	#endif
	return 0;
}
