#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 10		// максимальное количество книг

struct book {
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
};

char * s_gets(char * st, int n);

void display_books(struct book library[MAXBKS], int count);
int add_books(struct book *, int count, int size);
int del_books(struct book *, int count);

int main(void)
{
	struct book library[MAXBKS]; // массив структур
	int count = 0;
	int index, filecount;
	FILE * pbooks;
	int size = sizeof (struct book);

	if ((pbooks = fopen("book.dat", "a+b")) == NULL)
	{
		fputs("Не удается открыть файл book.dat\n", stderr);
		exit(1);
	}

	rewind(pbooks); // переход в начало
	while (count < MAXBKS && fread(&library[count], size, 1, pbooks) == 1)
	{
		if (count == 0)
			puts("Текущее содержимое файла book.dat:");
		printf("%s авторства %s: $%.2f\n", library[count].title, library[count].author, library[count].value);
		count++;
	}

	if (count == MAXBKS)
	{
		fputs("Файл book.dat заполнен.", stderr);
		exit(2);
	}

	fclose(pbooks);

	char flag;

	printf("Введите действие: \n");
	printf("a. Удалить запись\n");
	printf("b. Изменить запись\n");
	printf("c. Добавить книги\n");

	scanf("%c", &flag);
	switch (flag) 
	{
		case 'a':
			count = del_books(&library[0], count);
			break;
		case 'b':
			break;
		case 'c':
			count = add_books(&library[0], count, size);
			break;
	}

	display_books(library, count);
	puts("Программа завершена.\n");

	return 0; 
}

int del_books(struct book * library, int count)
{

	printf("Введите название книги\n");
	char temp_title[20];
	int next = 0;

	while (scanf("%s", temp_title) == 1)
	{
		if (strcmp(temp_title, "exit") == 0) 
			break;

		for (int i = 0; i < count; i++)
		{
			if (strcmp((library + i)->title, temp_title) == 0)
			{
				printf("Книга найдена. Удаление...\n");		
				(library + i)->title[0] = '\0';
				(library + i)->author[0] = '\0';
				(library + i)->value = 0;
				next = 0;
				break;
			}
			else
			{
				if (i == count - 1) {
					printf("Книга не найдена, повторите снова..\n");
					printf("Введите название книги..\n");
					next = 1;
				}
			}
		}	
		if (next == 0)
			break;
	}
}

int add_books(struct book * library, int count, int size)
{
	puts("Введите названия новых книг.");
	puts("Нажмите [enter] в начале строки, чтобы закончить ввод.");

	while(getchar() != '\n')
		continue;
	getchar();

	while (count < MAXBKS && s_gets((library + count)->title, MAXTITL) != NULL && (library + count)->title[0] != '\0')
	{
		puts("Теперь введите имя автора.");
		s_gets((library + count)->author, MAXAUTL);
		puts("Теперь введите цену книги.");
		scanf("%f", &(library + count++)->value);
		while (getchar() != '\n')
			continue;
		if (count < MAXBKS)
			puts("Введите название следующей книги.");
	}

	return count;
}

void display_books(struct book library[MAXBKS], int count)
{
	FILE * pbooks;
	int size = sizeof (struct book);

	if ((pbooks = fopen("book.dat", "w+b")) == NULL)
	{
		fputs("Не удается открыть файл book.dat\n", stderr);
		exit(1);
	}

	if (count == MAXBKS)
	{
		fputs("Файл book.dat заполнен.", stderr);
		exit(2);
	}

	if (count > 0)
	{
		puts("Каталог ваших книг:");
		for (int index = 0; index < count; index++)
			if (library[index].title[0] != '\0')
				printf("%s авторства %s: $%.2f\n", library[index].title, library[index].author, library[index].value);

		fwrite(&library[count], size, count, pbooks);
	}
	else 
		puts("Вообще нет книг? Очень плохо.\n");

	fclose(pbooks);
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
