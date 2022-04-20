#include <stdio.h>

int main(void)
{
	int count;
	char ch;
	while((ch = getchar()) != EOF)
	{
		if (ch != '\n')
			count++;
	}
	printf("%d - количество символов\n", count);
	return 0;
}
