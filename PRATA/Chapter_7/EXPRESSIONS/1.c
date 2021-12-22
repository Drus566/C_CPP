#include <stdio.h>
int main(void)
{
	int ac = 0;
	int sc = 0;
	int nc = 0;
	char ch;

	while ((ch = getchar()) != '#')
	{
		if (ch == ' ')
			sc++;
		if (ch == '\n')
			nc++;	

		ac++;
	}
	printf("%d - все символы\n", ac);
	printf("%d - пробелы\n", sc);
	printf("%d - символ новой строки\n", nc);
	return 0;
}
