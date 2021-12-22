#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#define STOP '|'

int main(void)
{
	char c;								// прочитанный символ
	char prev;						// предыдущий прочитанный символ
	long n_chars = 0L;		// количество символов
	int n_lines = 0;			// количество строк
	int n_words = 0;			// количество слов
	int p_lines = 0;			// количество неполных строк
	bool inword = false;	// == true если символ находится внутри слова
	printf("Введите текст анализа (| для завершения):\n");
	prev = '\n';
	while ((c = getchar()) != STOP)
	{
		n_chars++;
		if (c == '\n')
			n_lines++;
		if (!isspace(c) && !inword)
		{
			inword = true; // начало нового слова
			n_words++; // считать слова
		}
		if (isspace(c) && inword)
			inword = false; // достигнут конец слова
		prev = c;
	}
	if (prev != '\n')
		p_lines = 1;
	printf("символов = %ld, слов = %d, строк = %d, ", n_chars, n_words, n_lines);
	printf("неполных строк = %d\n", p_lines);
	return 0;
}

