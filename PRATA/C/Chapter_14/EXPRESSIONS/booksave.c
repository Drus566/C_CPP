#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>

#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 100

struct book {
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
	int del;
};

int add_books(struct book *, int count); 
void del_books(struct book *, int count);
void change_books(struct book *, int count);
void display_lib(struct book library[MAXBKS], int count);

void display_menu(void);
char * s_gets(char *st, int n);

int main(void)
{
	char *locale = setlocale(LC_ALL, "");

	struct book library[MAXBKS];
	int count = 0;
	int index, filecount;
	FILE * pbooks;
	int size = sizeof(struct book);

	if ((pbooks = fopen("book.dat", "r+b")) == NULL)
	{
		fputs("Не удается открыть файл book.dat\n", stderr);
		exit(1);
	}

	rewind(pbooks);

	while (count < MAXBKS && fread(&library[count], size, 1, pbooks) == 1)
	{
		if (count == 0)
			puts("Текущее содержимое файла book.dat:");
		if (library[count].del == 0) 
			printf("%s авторства %s: %.2f\n", library[count].title, library[count].author, library[count].value);
		count++;
	}

	filecount = count;

	if (count == MAXBKS)
	{
		fputs("Файл book.dat заполнен.", stderr);
		exit(2);
	}

	char choice;

	display_menu();

	int flag = 0;

	while ((choice = getchar()) != 'd') {

		while (getchar() != '\n')
			continue;

		switch (choice)
		{
			case 'a':
				count = add_books(&library[0], count);
				break;
			case 'b':
				del_books(&library[0], count);
				break;
			case 'c':
				change_books(&library[0], count);
				break;
			case 'l':
				display_lib(library, count);
				break;
			case 's':
				rewind(pbooks);
				fwrite(library, size * count, 1, pbooks);
				break;
			case 'd':
				flag = 1;
				break;
			default:
				printf("Вопрос озадачил!\n");
		}

		if (flag == 1) {
			break;
		}

		display_menu();
	}

	display_lib(library, count);

	rewind(pbooks);
	fwrite(library, size * count, 1, pbooks);

	puts("Программа завершена.\n");
	fclose(pbooks);

	return 0; 
}

int add_books(struct book *library, int count)
{
	printf("\nВведите название книги.\n");
	printf("Нажмите [enter] в начале строки, чтобы закончить ввод.\n\n");

	while (count < MAXBKS && s_gets((library + count)->title, MAXTITL) != NULL && (library + count)->title[0] != '\0')
	{
		(library + count)->del = 0;

		printf("Теперь введите ФИО автора\n");
		s_gets((library + count)->author, MAXAUTL);
		printf("Теперь введите цену.\n");
		scanf("%f", &(library + count++)->value);

		while (getchar() != '\n')
			continue;

		if (count < MAXBKS)
			printf("\nВведите название следующей книги.\n");
	}

	return count;
}

void del_books(struct book *library, int count)
{

	char find[MAXTITL];

	printf("\nВведите название книги для удаления.\n");
	printf("Нажмите [enter] в начале строки, чтобы закончить ввод.\n\n");

	int counter = 0;

	while (s_gets(find, MAXTITL) != NULL && find[0] != '\0') {
		while (counter < count) {
			if (strcmp(find, (library + counter)->title) == 0) {
				printf("Книга найдена...\n");
				printf("%s авторства %s: %.2f\n", (library + counter)->title, (library + counter)->author, (library + counter)->value);
				printf("Удаление...\n");	

				(library + counter)->title[0] = '\0';	
				(library + counter)->author[0] = '\0';	
				(library + counter)->value = 0;	
				(library + counter)->del = 1;	

				break;
			}
			else 
			{
				if (counter == count - 1)
				{
					printf("Книга не найдена...\n");
					break;
				}
			}
			++counter;
		}	
		printf("\nВведите название книги для удаления.\n");
		printf("Нажмите [enter] в начале строки, чтобы закончить ввод.\n\n");
	}
}

void change_books(struct book * library, int count) 
{
	char find[MAXTITL];

	printf("\nВведите название книги для редактирования.\n");
	printf("Нажмите [enter] в начале строки, чтобы закончить ввод.\n\n");

	int counter = 0;

	while (s_gets(find, MAXTITL) != NULL && find[0] != '\0') {
		while (counter < count) {
			if (strcmp(find, (library + counter)->title) == 0) {
				printf("Книга найдена...\n");
				printf("%s авторства %s: %.2f\n", (library + counter)->title, (library + counter)->author, (library + counter)->value);
				printf("Редактирование:\n\n");

				printf("Теперь введите название книги\n");
				s_gets((library + counter)->title, MAXTITL);
				printf("Теперь введите ФИО автора\n");
				s_gets((library + counter)->author, MAXAUTL);
				printf("Теперь введите цену.\n");
				scanf("%f", &(library + counter)->value);

				printf("Редактирование закончено...\n");

				while (getchar() != '\n')
					continue;
				
				break;
			}
			else {
				if (counter == count - 1)
				{
					printf("Книга не найдена...\n");
					break;
				}
			}
			++counter;
		}	

		printf("\nВведите название книги для редактирования\n");
		printf("Нажмите [enter] в начале строки, чтобы закончить ввод.\n\n");
	}
}

void display_lib(struct book library[MAXBKS], int count) 
{
	if (count > 0)
	{
		printf("Каталог ваших книг:\n");
		for (int index = 0; index < count; index++)
			if (library[index].del != 1)
				printf("%s авторства %s: $%.2f\n", library[index].title, library[index].author, library[index].value);
	}
	else
		printf("Книг нет? Плохо!\n");
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
 
void display_menu(void)
{
	printf("\nВыберите действие:\n\n");
	printf("a) Добавить книги\n");
	printf("b) Удалить книги\n");
	printf("c) Изменить книги\n");
	printf("l) Список книг\n");
	printf("s) Сохранить результат\n");
	printf("d) Сохранить и выйти\n\n");
}


