#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>

#define MAXNAME 40
#define MAXPLACES 12 

struct place {
	int id;
	int busy;
	int confirm;
	char fname[MAXNAME];
	char lname[MAXNAME];
};

void init_places(struct place *);

void show_free_places(struct place *);
void show_count_free_places(struct place *);
void show_reservationed_places(struct place *);
void reserve_place(struct place *);
void unreserve_place(struct place *);

void sort_place(void);
void show_menu(void);
char * s_gets(char *st, int n);

int main(void)
{
	char *locale = setlocale(LC_ALL, "");

	struct place places[MAXPLACES];

	init_places(&places[0]);

	FILE * file_places;

	int size = sizeof(struct place);

	if ((file_places = fopen("place.dat", "r+b")) == NULL)
	{
		fputs("Не удается открыть файл place.dat\n", stderr);
		exit(1);
	}

	rewind(file_places);

	puts("\nТекущее содержимое файла place.dat:\n");
	for (int i = 0; i < MAXPLACES; i++) {
		if (fread(&places[i], size, 1, file_places) == 1)
		{
			printf("\nID:%d BUSY:%d CONFIRM:%d\n FNAME: %s\n LNAME %s\n", places[i].id, places[i].busy, places[i].confirm, places[i].fname, places[i].lname);
		}
	}

	char choice;
	show_menu();

	int flag = 0;

	while ((choice = getchar()) != 'd') {

		while (getchar() != '\n')
			continue;

		switch (choice)
		{
			case 'a':
				show_count_free_places(&places[0]);
				break;
			case 'b':
				show_free_places(&places[0]);
				break;
			case 'c':
				show_reservationed_places(&places[0]);
				break;
			case 'd':
				reserve_place(&places[0]);
				break;
			case 'e':
				unreserve_place(&places[0]);
				break;
			case 'f':
				flag = 1;
				break;
			default:
				printf("Вопрос озадачил!\n");
		}

		if (flag == 1) {
			break;
		}

		show_menu();
	}

	rewind(file_places);
	fwrite(places, size * MAXPLACES, 1, file_places);

	puts("Программа завершена.\n");
	fclose(file_places);

	return 0; 
}

// int add_books(struct book *library, int count)
// {
// 	printf("\nВведите название книги.\n");
// 	printf("Нажмите [enter] в начале строки, чтобы закончить ввод.\n\n");
// 
// 	while (count < MAXBKS && s_gets((library + count)->title, MAXTITL) != NULL && (library + count)->title[0] != '\0')
// 	{
// 		(library + count)->del = 0;
// 
// 		printf("Теперь введите ФИО автора\n");
// 		s_gets((library + count)->author, MAXAUTL);
// 		printf("Теперь введите цену.\n");
// 		scanf("%f", &(library + count++)->value);
// 
// 		while (getchar() != '\n')
// 			continue;
// 
// 		if (count < MAXBKS)
// 			printf("\nВведите название следующей книги.\n");
// 	}
// 
// 	return count;
// }

// void del_books(struct book *library, int count)
// {
// 
// 	char find[MAXTITL];
// 
// 	printf("\nВведите название книги для удаления.\n");
// 	printf("Нажмите [enter] в начале строки, чтобы закончить ввод.\n\n");
// 
// 	int counter = 0;
// 
// 	while (s_gets(find, MAXTITL) != NULL && find[0] != '\0') {
// 		while (counter < count) {
// 			if (strcmp(find, (library + counter)->title) == 0) {
// 				printf("Книга найдена...\n");
// 				printf("%s авторства %s: %.2f\n", (library + counter)->title, (library + counter)->author, (library + counter)->value);
// 				printf("Удаление...\n");	
// 
// 				(library + counter)->title[0] = '\0';	
// 				(library + counter)->author[0] = '\0';	
// 				(library + counter)->value = 0;	
// 				(library + counter)->del = 1;	
// 
// 				break;
// 			}
// 			else 
// 			{
// 				if (counter == count - 1)
// 				{
// 					printf("Книга не найдена...\n");
// 					break;
// 				}
// 			}
// 			++counter;
// 		}	
// 		printf("\nВведите название книги для удаления.\n");
// 		printf("Нажмите [enter] в начале строки, чтобы закончить ввод.\n\n");
// 	}
// }

// void change_books(struct book * library, int count) 
// {
// 	char find[MAXTITL];
// 
// 	printf("\nВведите название книги для редактирования.\n");
// 	printf("Нажмите [enter] в начале строки, чтобы закончить ввод.\n\n");
// 
// 	int counter = 0;
// 
// 	while (s_gets(find, MAXTITL) != NULL && find[0] != '\0') {
// 		while (counter < count) {
// 			if (strcmp(find, (library + counter)->title) == 0) {
// 				printf("Книга найдена...\n");
// 				printf("%s авторства %s: %.2f\n", (library + counter)->title, (library + counter)->author, (library + counter)->value);
// 				printf("Редактирование:\n\n");
// 
// 				printf("Теперь введите название книги\n");
// 				s_gets((library + counter)->title, MAXTITL);
// 				printf("Теперь введите ФИО автора\n");
// 				s_gets((library + counter)->author, MAXAUTL);
// 				printf("Теперь введите цену.\n");
// 				scanf("%f", &(library + counter)->value);
// 
// 				printf("Редактирование закончено...\n");
// 
// 				while (getchar() != '\n')
// 					continue;
// 				
// 				break;
// 			}
// 			else {
// 				if (counter == count - 1)
// 				{
// 					printf("Книга не найдена...\n");
// 					break;
// 				}
// 			}
// 			++counter;
// 		}	
// 
// 		printf("\nВведите название книги для редактирования\n");
// 		printf("Нажмите [enter] в начале строки, чтобы закончить ввод.\n\n");
// 	}
// }

void reserve_place(struct place * ptr)
{
}

void show_reservationed_places(struct place * ptr)
{
	for (int i = 0; i < MAXPLACES; i++)
	{
		if ((ptr + i)->busy == 1) 
		{
			printf("\nID:%d BUSY:%d CONFIRM:%d\n FNAME: %s\n LNAME %s\n", (ptr + i)->id, (ptr + i)->busy, (ptr + i)->confirm, (ptr + i)->fname, (ptr + 1)->lname);
		}
	}
}

void show_count_free_places(struct place * ptr)
{
	int counter = 0;
	for (int i = 0; i < MAXPLACES; i++)
	{
		if ((ptr + i)->busy == 0) 
		{
			++counter;
		}
	}
	printf("COUNT FREE PLACES: %d\n", counter);
}

void show_free_places(struct place * ptr)
{
	for (int i = 0; i < MAXPLACES; i++)
	{
		if ((ptr + i)->busy == 0) 
		{
			printf("\nID:%d BUSY:%d CONFIRM:%d\n FNAME: %s\n LNAME %s\n", (ptr + i)->id, (ptr + i)->busy, (ptr + i)->confirm, (ptr + i)->fname, (ptr + 1)->lname);
		}
	}
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
 
void show_menu(void)
{
	printf("\nВыберите действие:\n\n");
	printf("a) Показать количество мест\n");
	printf("b) Показать список свободных мест\n");
	printf("c) Показать список забронированных мест в алфавитном порядке\n");
	printf("d) Забронировать место для пассажира\n");
	printf("e) Снять броню с места\n");
	printf("f) Выйти из программы\n");
}


void init_places(struct place * ptr)
{
	for (int i = 0; i < MAXPLACES; i++)
	{
		(ptr + i)->id = i;
		(ptr + i)->busy = 0;
		(ptr + i)->confirm = 0;
		(ptr + i)->fname[0] = '\0';
		(ptr + i)->lname[0] = '\0';
	}
}
