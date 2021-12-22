#include <stdio.h>
#include <ctype.h>

void scan(void);
int alphabet(char ch);

int main(void)
{
	scan();
	return 0;
}

void scan(void)
{
	char ch;
	while ((ch = getchar()) != EOF)
	{
		if (isalpha(ch))
		{
			printf("Order number '%c' in alphabet: %d\n", ch, alphabet(ch)); 
		}
		else 
		{
			printf("%d\n", -1);
		}
	}
}

int alphabet(char ch)
{
	int offset;
	if (ch >= 'a' && ch <= 'z')
	{
		offset = 96;
	}
	else if (ch >= 'A' && ch <= 'Z')
	{
		offset = 64;
	}
	return (ch - offset);
}
