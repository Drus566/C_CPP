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
void show_reservationed_places(struct place places[MAXPLACES]);
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

	int count_empty = 0;
	for (int i = 0; i < MAXPLACES; i++) {
		if (fread(&places[i], size, 1, file_places) == 1)
		{
			if (places[i].busy == 1)
				printf("\nID:%d BUSY:%d CONFIRM:%d\n FNAME: %s\n LNAME %s\n", places[i].id, places[i].busy, places[i].confirm, places[i].fname, places[i].lname);
			else
				++count_empty;
		}
	}

	if (count_empty == MAXPLACES)
		printf("Файл пуст...\n");

	char choice;
	show_menu();

	int flag = 0;

	while ((choice = getchar()) != 'f') {

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
				show_reservationed_places(places);
				break;
			case 'd':
				reserve_place(&places[0]);
				break;
			case 'e':
				unreserve_place(&places[0]);
				break;
			default:
				printf("Вопрос озадачил!\n");
		}

		show_menu();
	}

	rewind(file_places);
	fwrite(places, size * MAXPLACES, 1, file_places);

	puts("\nПрограмма завершена.\n");
	fclose(file_places);

	return 0; 
}

void unreserve_place(struct place * ptr) 
{
	printf("\nВведите номер места для разбронирования.\n");
	printf("Нажмите [q] чтобы закончить ввод.\n\n");

	int r_place;

	while (scanf("%d", &r_place) == 1 && r_place != 'q')
	{
		while (getchar() != '\n')
			continue;

		--r_place;

		if (r_place < 0 || r_place > 12) {
			printf("Существуют только 1-12 места\n");
			printf("Введите номер места для разбронирования.\n");	
			printf("Нажмите [q] чтобы закончить ввод.\n\n");

			while (getchar() != '\n')
				continue;

			continue;
		}

		if ((ptr + r_place)->busy == 0) 
		{
			printf("Место не забронировано...\n");
			printf("Введите номер места для разбронирования.\n");	
			printf("Нажмите [q] чтобы закончить ввод.\n\n");

			while (getchar() != '\n')
				continue;

			continue;
		}

		(ptr + r_place)->busy = 0;
		(ptr + r_place)->fname[0] = '\0';
		(ptr + r_place)->lname[0] = '\0';

		printf("Место разбронировано...\n");

		printf("\nВведите номер места для разбронирования...\n");
		printf("Нажмите [q] чтобы закончить ввод.\n\n");
	}

	while (getchar() != '\n')
		continue;
}

void reserve_place(struct place * ptr)
{
	printf("\nВведите номер места.\n");
	printf("Нажмите [q] чтобы закончить ввод.\n\n");

	int r_place;	

	while (scanf("%d", &r_place) == 1 && r_place != 'q')
	{
		while (getchar() != '\n')
			continue;

		--r_place;

		if (r_place < 0 || r_place > 11) {
			printf("Существуют только 1-12 места\n");
			printf("Введите номер места.\n");	
			printf("Нажмите [q] чтобы закончить ввод.\n\n");
			continue;
		}

		if ((ptr + r_place)->busy == 1) 
		{
			printf("Место занято...\n");
			printf("Введите номер места.\n");	
			printf("Нажмите [q] чтобы закончить ввод.\n\n");
			continue;
		}

		(ptr + r_place)->busy = 1;
		(ptr + r_place)->busy = 1;
		printf("Введите имя:\n");
		s_gets((ptr + r_place)->fname, MAXNAME);

		printf("Введите фамилию:\n");
		s_gets((ptr + r_place)->lname, MAXNAME);

		printf("Место забронировано...\n");

		printf("\nВведите номер места.\n");
		printf("Нажмите [q] чтобы закончить ввод.\n\n");
	}

	while (getchar() != '\n')
		continue;
}

void show_reservationed_places(struct place places[MAXPLACES])
{
	struct place t_places[MAXPLACES];
	char t_fname[MAXNAME];
	int r_count = 0;

	for (int i = 0; i < MAXPLACES; i++)
	{

		if (i == 0)
		{
			t_places[i] = places[i];
			continue;
		}

		for (int j = i - 1; j >= 0; j--)
		{
			if (t_places[j].fname[0] > places[i].fname[0])
				t_places[j + 1] = t_places[j];
			else 
			{
				t_places[j + 1] = places[i];
				break;
			}
		}
	}

	if (r_count == MAXPLACES)
		printf("\nНет забронированных мест...\n");
	else
		for (int i = 0; i < MAXPLACES; i++)
			if (t_places[i].busy == 1)
				printf("\nID:%2d; BUSY:%d; CONFIRM:%d\n FNAME: %s\n LNAME: %s\n", t_places[i].id, t_places[i].busy, t_places[i].confirm, t_places[i].fname, t_places[i].lname);
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
	printf("Количество свободных мест: %d\n", counter);
}

void show_free_places(struct place * ptr)
{
	for (int i = 0; i < MAXPLACES; i++)
	{
		if ((ptr + i)->busy == 0) 
		{
			printf("\nID:%2d; BUSY:%d\n", (ptr + i)->id, (ptr + i)->busy);
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
		(ptr + i)->id = i + 1;
		(ptr + i)->busy = 0;
		(ptr + i)->confirm = 0;
		(ptr + i)->fname[0] = '\0';
		(ptr + i)->lname[0] = '\0';
	}
}
