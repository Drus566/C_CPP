#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

#define MAX 20
#define CSIZE 4

struct name {
	char fname[MAX];
	char lname[MAX];
};

struct student {
	struct name names;
	double grade[3];
	double average;
};

void set_rating(struct student * students);
void set_avg(struct student * students, int student);
void display(struct student * students);

int main(void)
{
	struct student students[CSIZE] = {
		{
			.names.fname = "Andrey",
			.names.lname = "Lykov"
		},
		{
			.names.fname = "Pavel",
			.names.lname = "Ylanov"
		},
		{
			.names.fname = "Maxim",
			.names.lname = "Miganov"
		},
		{
			.names.fname = "Sergey",
			.names.lname = "Student"
		}
	};

	set_rating(&students[0]);
	display(&students[0]);


	return 0; 
}

void set_rating(struct student * students)
{
	char temp_fname[MAX];
	char temp_lname[MAX];

	printf("Введите имя и фамилию ученика (exit)\n");

	while (scanf("%s %s", temp_fname, temp_lname) == 2) 
	{
		if (strcmp(temp_fname, "exit") == 0 &&
				strcmp(temp_lname, "exit") == 0)
		{
			printf("Выход...\n");
			return;
		}

		int flag = 0;
		int student;

		for (int i = 0; i < CSIZE; i++)
		{
			if (strcmp((students + i)->names.fname, temp_fname) == 0
					&& strcmp((students + i)->names.lname, temp_lname) == 0)
			{
				printf("Ученик найден...\n");
				flag = 1;
				student = i;
				break;
			} 
		}

		if (flag == 0)
		{
			printf("Ученик не найден...\n");
			printf("Введите имя и фамилию ученика...\n");
			continue;
		}

		set_avg(&students[0], student);
		
		printf("\nВведите имя и фамилию ученика\n");
	}
}

void set_avg(struct student * students, int student)
{
	printf("Введите оценки ученика:\n");
	scanf("%lf %lf %lf", &(students + student)->grade[0], &(students + student)->grade[1], &(students + student)->grade[2]);

	printf("Средняя оценка:");
	double avg =  ((students + student)->grade[0] + (students + student)->grade[1] + (students + student)->grade[2]) / 3;
	(students + student)->average = avg;
	printf(" %.2lf\n", avg);
}	

void display(struct student * students)
{
	for (int i = 0; i < CSIZE; ++i)
	{
		if ((students + i)->names.fname[0] != '\0')
		{
				printf("%s %s, %.2lf %2lf %2lf, %2lf\n", (students + i)->names.fname, (students + i)->names.lname, (students + i)->grade[0],(students + i)->grade[1], (students + i)->grade[2], (students + i)->average);
		}
	}
}
