#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
	int i, times;

	if (argc < 2 || (times = atoi(argv[1])) < 1)
		printf("Использование: %s положительное-число\n", argv[0]);
	else
		for (i = 0; i < times; i++)
			puts("Хорошего дня!");
	return 0;
}
