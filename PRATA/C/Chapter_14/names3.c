#include <stdio.h>
#include <string.h> // для strcpy(), strlen()
#include <stdlib.h>  // для malloc(), free()
#define NLEN 30

struct namect {
	char * fname;
	char * lname;
	int letters;
};

void getinfo(struct namect *);
void makeinfo(struct namect *);
void showinfo(const struct namect *);
void cleanup(struct namect *); // освобождение памяти
char * s_gets(char * st, int n);

int main(void)
{
	struct namect person;
	getinfo(&person);
	makeinfo(&person);
	showinfo(&person);
	cleanup(&person);

	return 0; 
}

void getinfo(struct namect * pst)
{
	char temp[NLEN];
	printf("Введите свое имя\n");
	s_gets(temp, NLEN);
	// выделение памяти для хранение имени
	pst->fname = (char *) malloc(strlen(temp) + 1);

	// копирование имени в выделенную память
	strcpy(pst->fname, temp);

	printf("Введите свою фамилию.\n");
	s_gets(temp, NLEN);
	pst->lname = (char *) malloc(strlen(temp) + 1);
	strcpy(pst->lname, temp);
}

void makeinfo(struct namect * pst)
{
	pst->letters = strlen(pst->fname) + strlen(pst->lname);
}

void showinfo(const struct namect * pst)
{
	printf("%s %s, ваше имя и фамилия содержат %d букв.\n", pst->fname, pst->lname, pst->letters);
}

void cleanup(struct namect * pst)
{
	free(pst->fname);
	free(pst->lname);
}

char * s_gets(char * st, int n)
{
	char * ret_val;
	char * find;

	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		find = strchr(st, '\n'); // поиск новой строки
		if (find) 							// если адрес не равен NULL
			*find = '\0';					// поместить туда нулевой символ
		else
			while (getchar() != '\n')
				continue;						// отбросить остаток строки
	}

	return ret_val;
}
