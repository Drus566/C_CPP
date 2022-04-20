// 17.4
// компиляция с list.c
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include "stack.h" 	// 
#define MAXSIZE 100

void showsymbols(Item item);
char * s_gets(char * st, int n);

int main(void)
{
	Stack symbols;
	char temp[MAXSIZE];
		
	Item ch;

	InitializeStack(&symbols);
	if (StackIsFull(&symbols))
	{
		fprintf(stderr, "Доступная память отсутствует! Программа завершена.\n");
		exit(1);
	}

	while (s_gets(temp, MAXSIZE) != NULL && temp[0] != '\0')
	{
		for (int i = 0; i < strlen(temp); i++) {
			ch.symbol = temp[i];
			if (Push(ch, &symbols) == false)
			{
				fprintf(stderr, "Проблема с выделением памяти\n");
				break;
			}
		}

		if (StackIsFull(&symbols))
		{
			puts("Список полон");
			break;
		}

		puts("Введите название следующего фильма (или пустую строку для прекращения ввода):");
	}

	// отображение
	if (StackIsEmpty(&symbols))
		printf("Данные не введены");
	else
	{
		printf("Список cимволов:\n");
		Traverse(&symbols, showsymbols);
	}

	printf("Вы ввели %d фильмов\n", StackItemCount(&symbols));

	// очистка
	EmptyTheStack(&symbols);
	printf("Программа завершена\n");

	return 0; 
}

void showsymbols(Item item)
{
	printf("%c\n", item.symbol);
}

char * s_gets(char * st, int n)
{
	char * ret_val;
	char * find;

	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		find = strchr(st, '\n');
		if (find)
			*find = '\0';
		else
			while (getchar() != '\n')
				continue;
	}
	return ret_val;
}
