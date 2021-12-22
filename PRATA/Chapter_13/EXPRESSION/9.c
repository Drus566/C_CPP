#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 41

int main(void)
{
	FILE *fp;
	char words[MAX];
	int count = 0;
	long last, counter;

	if ((fp = fopen("wordy", "a+")) == NULL)
	{
		fprintf(stdout, " Не удается открыть файл \"wordy\".\n");
		exit(EXIT_FAILURE);
	}
	
	puts("Введите слова для добавления в файл; для завершения");
	puts("введите символ # в начале строки.");

	fseek(fp, 0L, SEEK_END);
	last = ftell(fp);

	char ch;
	for (counter = 1L; counter <= last; counter++)
	{
		fseek(fp, -counter, SEEK_END);
		ch = getc(fp);

		if (counter > 1 && ch == '\n')
			break;
	}

	if (fscanf(fp, "%d", &count) != 1)
	{
		rewind(fp); // возврат в начало файла
	}

	++count;

	while ((fscanf(stdin, "%40s", words) == 1) && (words[0] != '#')) 
	{
		fprintf(fp, "%d: %s\n", count,  words);
		++count;
	}

	while (fscanf(fp, "%s", words) == 1)
		puts(words);

	puts("Готово!");

	if (fclose(fp) != 0)
		fprintf(stderr, "Ошибка при закрытии файла\n");

	return 0;
}
