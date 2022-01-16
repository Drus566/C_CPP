#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char * argv[])
{
	int var1 = 0;
	int var2 = 2;
	char * buffer = malloc(sizeof(char) * 10);
	while (var1 < 10) 
	{
		var1++;
		*(++buffer) = 'c';
	}
	printf("%s\n", buffer);
	return 0; 
}
