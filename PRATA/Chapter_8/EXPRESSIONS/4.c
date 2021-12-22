#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int main(void)
{
	int count_letters = 0;
	int count_words = 0;

	char ch;
	bool prev_char = false;

	while((ch = getchar()) != EOF)
	{
		if (ch == '\n')
		{
			if (prev_char)
				++count_words;

			prev_char = false;
		}

		if (ch >= ' ' && isalpha(ch)) 
		{
			++count_letters;
			prev_char = true;
		}

		if (ispunct(ch) || (ch == ' '))
		{
			if (prev_char)
				++count_words;
			prev_char = false;
		} 
	}

	printf("Количество букв - %d\n", count_letters);
	printf("Количество слов - %d\n", count_words);
	printf("Среднее количество букв в словах - %d\n", count_letters / count_words);

	return 0;
}
