#include <stdio.h>

int main(void)
{
	char * p1 = "Клингтон";
	p1[0] = 'Ф';
	printf("Клингтон");
	printf(": берегитесь %sцев!\n", "Клингтон");
	return 0;
}
