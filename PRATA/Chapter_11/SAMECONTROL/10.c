#include <stdio.h>

int strlen(char * str);

int main(void)
{
	char sample[10] = "hi bro";
	printf("Длинна \"%s\": %d\n", sample, strlen(sample));
	
	return 0;
}

int strlen(char * str)
{
	int length = 0;
	while(*str != '\0')
	{
		printf("%c\n", *str);
		str++;
		++length;
	}

	return length;
}
