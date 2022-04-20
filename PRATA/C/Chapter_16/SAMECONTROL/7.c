#include <stdio.h> 
#define PS(X) printf("имя: " #X "; значение: %d; адрес: %p\n", X , & X)

int main(void)
{
	int gg = 3;
	PS(gg);
	return 0;
}
