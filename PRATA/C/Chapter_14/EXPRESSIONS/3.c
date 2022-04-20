#include <stdio.h>
#include <string.h>

char * s_gets(char * st, int n);

#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 100 // максимальное количество книг

struct book {
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
};

void sort_books(struct book * ptr, int count);
void sort_books_by_price(struct book * ptr, int count);

int main(void)
{
	struct book library[MAXBKS];
	int count = 0;
	int index;

	printf("Введите название книги.\n");
	printf("Нажмите [enter] в начале строки, чтобы закончить ввод.\n");

	while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL && library[count].title[0] != '\0')
	{
		printf("Теперь введите ФИО автора.\n");
		s_gets(library[count].author, MAXAUTL);
		printf("Теперь введите цену.\n");
		scanf("%f", &library[count++].value);

		while (getchar() != '\n')
			continue; // очистить входную строку
		if (count < MAXBKS)
			printf("Введите название следующей книги.\n");
	}

	if (count > 0)
	{
		printf("Каталог ваших книг:\n");
		for (index = 0; index < count; index++)
			printf("%s авторства %s: $%.2f\n", library[index].title, library[index].author, library[index].value);
		
		sort_books(&library[0], count);
		sort_books_by_price(&library[0], count);

	}
	else
		printf("Вообще нет книг? Очень плохо.\n");

	return 0; 
}

void sort_books(struct book * ptr, int count)
{
	struct book temp_struct[MAXBKS];

	temp_struct[0].value = ptr->value;
	strcpy(temp_struct[0].title, ptr->title);
	strcpy(temp_struct[0].author, ptr->author);

	for (int i = 1; i < count; ++i)
	{
		for (int j = i - 1; j >= 0; --j)
		{
			if (temp_struct[j].title[0] > (ptr + i)->title[0])
			{
				temp_struct[j + 1] = temp_struct[j];
				if (j == 0)
					temp_struct[j] = *(ptr + 1);
			}
			else
			{
			 	temp_struct[j + 1] = *(ptr + i);
				break;
			}
		}
	}

	printf("\nОтсортированный список\n");
	for (int i = 0; i < count; ++i)
	{
		printf("%s \n", temp_struct[i].title);
	}
}

void sort_books_by_price(struct book * ptr, int count)
{
	struct book temp_struct[MAXBKS];

	temp_struct[0].value = ptr->value;
	strcpy(temp_struct[0].title, ptr->title);
	strcpy(temp_struct[0].author, ptr->author);

	for (int i = 1; i < count; ++i)
	{
		for (int j = i - 1; j >= 0; --j)
		{
			if (temp_struct[j].value > (ptr + i)->value)
			{
				temp_struct[j + 1] = temp_struct[j];
				if (j == 0)
					temp_struct[j] = *(ptr + 1);
			}
			else
			{
			 	temp_struct[j + 1] = *(ptr + i);
				break;
			}
		}
	}

	printf("\nОтсортированный список по ценнику:\n");
	for (int i = 0; i < count; ++i)
	{
		printf("%.2f$ \n", temp_struct[i].value);
	}
}

char * s_gets(char * st, int n)
{
	char * ret_val;
	char * find;

	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		find = strchr(st, '\n'); // поиск новой строки
		if (find)								// если адрес не равен NULL
			*find = '\0';					// поместить туда нулевой символ
		else 
			while (getchar() != '\n')
				continue; // отбросить остаток строки
	}

	return ret_val;
}
