#include <stdio.h> 
#include <string.h>

typedef struct lens {
	float foclen; // фокусное расстояние
	float fstop; // диафрагма
	char brand[30]; // марка производителя
} LENS;

int main(void)
{
	LENS some_struct[9] = {[2].foclen = 500, [2].fstop = 500 / 2, [2].brand = "Remakrasd"};
	printf("foclen %f\n", some_struct[2].foclen); 
	printf("fstop %f\n", some_struct[2].fstop); 
	printf("brand %s\n", some_struct[2].brand); 
	return 0; 
}

