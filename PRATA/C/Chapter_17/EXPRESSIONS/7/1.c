#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

#define MAX 41

void show_words(const Tree * pt);
void print_item(Item item);

int main(void)
{
	FILE * fp;
	char words[MAX];

	Tree tree_words;
	Item temp;

	if ((fp = fopen("wordy", "a+")) == NULL)
	{
		fprintf(stdout, " Не удается открыть файл \"wordy\".\n");
		exit(EXIT_FAILURE);
	}

	InitializeTree(&tree_words);

	if (TreeIsFull(&tree_words))
		puts("TREE IS FULL");

	while (fscanf(fp, "%40s", words) == 1)
	{
		strcpy(temp.word, words);
		AddItem(&temp, &tree_words);
	}
			
	if (fclose(fp) != 0)
		fprintf(stderr, "Ошибка при закрытии файла\n");

	temp.repeat = 0;
	strcpy(temp.word, "che");
	show_words(&tree_words);
	printf("%d\n", InTree(&temp, &tree_words));

	return 0;
}

void print_item(Item item)
{
	printf("\nWORD: %s\nCOUNT: %d\n", item.word, item.repeat);
}

void show_words(const Tree * pt)
{
	if (TreeIsEmpty(pt))
		puts("Записи отсутствуют!");
	else
		Traverse(pt, print_item);
}
