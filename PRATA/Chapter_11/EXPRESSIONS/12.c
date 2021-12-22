#include <stdio.h>
#include <ctype.h>

int main(void)
{
	int count_words = 0;
	int count_words_upper = 0;
	int count_words_lower = 0;
	int count_puncts = 0;
	int count_digits = 0;
	int toggle = 0;
	char ch;

	while ((ch = getchar()) != EOF) {
		if (ispunct(ch)) {
			++count_puncts;
		} else if (islower(ch)) {
			++count_words_lower;
		} else if (isupper(ch)) {
			++count_words_upper;
		} else if (isdigit(ch)) {
			++count_digits;
		}

		if (isblank(ch)) {
			if (toggle) {
				++count_words;
				toggle = 0;
			} 
		} else if (isalpha(ch)) {
			toggle = 1;
		}
	}

	printf("Количество слов %d\n", count_words);
	printf("Количество прописных букв %d\n", count_words_upper);
	printf("Количество строчных букв %d\n", count_words_lower);
	printf("Количество знаков препинания %d\n", count_puncts);
	printf("Количество цифр %d\n", count_digits);

	return 0;
}
