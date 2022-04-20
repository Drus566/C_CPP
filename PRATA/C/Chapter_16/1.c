// 16.1
//
#include <stdio.h>
#define TWO 2
#define OW "Логика - последнее убежище лишенных\
воображения."

#define FOUR TWO*TWO
#define PX printf("X = %d.\n", x)
#define FMT "X = %d.\n"

int main(void)
{
	int x = TWO;
	PX;
	x = FOUR;
	printf(FMT, x);
	printf("%s\n", OW);
	printf("TWO: OW\n");

	return 0;
}
