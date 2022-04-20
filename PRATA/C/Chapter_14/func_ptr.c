#include <stdio.h> 
#include <string.h> 
#include <ctype.h>
#define LEN 81

char * s_gets(char * st, int n);
char showmenu(void);
void eatline(void);		// читает до конца строки
void show(void (*fp)(char *), char * str);
void ToUpper(char *); 		// преобразует в верхний регистр
void ToLower(char *); 		// в нижний
void Transpose(char *);		// меняет местами регистры
void Dummy(char *);				// оставляет строку неизменной

int main(void)
{
	char line[LEN];
	char copy[LEN];
	char choice;
	void (*pfun)(char *);

	puts("Введите строку (пустая строка - выход из программы):");
	while (s_gets(line, LEN) != NULL && line[0] != '\0')
	{
		while ((choice = showmenu()) != '\n')
		{
			switch (choice)
			{
				case 'u' : pfun = ToUpper; break;
				case 'l' : pfun = ToLower; break;
				case 't' : pfun = Transpose; break;
				case 'o' : pfun = Dummy; break;
			}
			strcpy(copy, line); // сделать копию для show()
			show(pfun, copy); // использовать выбранную функцию
		}
		puts("Введите строку (пустая строка - выход из программы) :");
	}
	puts("Программа завершена.");
	return 0; 
}

char showmenu(void)
{
	char ans;
	puts("Введите выбранный варинат из меню: ");
	puts("u) нижний регистр          l) верхний регистр");
	puts("t) поменять местами рег    o) исходный регистр");
	puts("n) следующая строка");
	ans = getchar(); // получить ответ
	ans = tolower(ans); 
	eatline();	// избавиться от оставшейся части строки
	while (strchr("ulton", ans) == NULL)
	{
		puts("Введите u, l, t, o или n:");
		ans = tolower(getchar());
		eatline();
	}
	return ans;
}

void eatline(void)
{
	while (getchar() != '\n')
		continue;
}

void ToUpper(char *str)
{
	while(*str)
	{
		*str = toupper(*str);
		str++;
	}
}

void ToLower(char *str)
{
	while(*str)
	{
		*str = tolower(*str);
		str++;
	}
}

void Transpose(char *str)
{
	while(*str)
	{
		if (islower(*str))
			*str = toupper(*str);
		else if (isupper(*str))
			*str = tolower(*str);
		str++;
	}
}

// оставляет строку неизменной
void Dummy(char * str){}

void show(void (*fp)(char *), char * str)
{
	(*fp)(str);
	puts(str);
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
