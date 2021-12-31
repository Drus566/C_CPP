// 16.11
#include <stdio.h>
#include "names.h"
#include "names.h" // преднамеренное второе включение

int main(void)
{
	names winner = {"Иван", "Иванов"};
	printf("Победителем стал %s %s\n", winner.first, winner.last);
	return 0; 
}
