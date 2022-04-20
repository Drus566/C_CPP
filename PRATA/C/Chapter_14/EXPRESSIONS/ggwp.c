#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

struct sample {
	int x;
	char y[10];
};

int main(void)
{
	struct sample gg[10];
	for (int i = 0; i < 10; i++)
	{
		printf("%s\n", gg[i].y);
	}
	
	return 0; 
}
