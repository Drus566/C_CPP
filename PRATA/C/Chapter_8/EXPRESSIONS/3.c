#include <stdio.h>
#include <ctype.h>

int main(void)
{
	char ch;
	int count_up = 0;
	int count_down = 0;
	int count_other = 0;
	while((ch = getchar()) != EOF)
	{
		if (ch >= ' ') 
		{
			if (isalpha(ch))
			{
				if (islower(ch))
					++count_down;
				else if (isupper(ch))
					++count_up;
			}
			else
				++count_other;
		}
	}
	printf("%d - количество аперкейс символов(буквы)\n", count_up);
	printf("%d - количество ловеркейс символов(буквы)\n", count_down);
	printf("%d - количество остальных символов\n", count_other);
	return 0;
}
