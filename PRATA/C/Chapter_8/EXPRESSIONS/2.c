#include <stdio.h>

int main(void)
{
	char ch;
	while((ch = getchar()) != EOF)
	{
		if (ch < ' ') 
		{
			if (ch == '\n')
				printf("%d - код ASCII символа '\\n'\n", ch);
			if (ch == '\t')
				printf("%d - код ASCII символа '\\t'\n", ch);
		}
		else
		{
			printf("%d - код ASCII символа '%c'\n", ch, ch);
		}
	}
	return 0;
}
