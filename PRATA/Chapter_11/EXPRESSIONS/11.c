#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define SCOUNT 10 
#define LEN 20

int check_eof(char * str);
int check_exit(char * str);
void print_all(char *strs[], int num);
void source_print(char strs[][LEN], int num);
void sort_by_length(char *strings[], int num);
void sort_by_ascii(char *strings[], int num);
void sort_by_first_word_length(char *strings[], int num);
void set_ptrs(char *pts[], char strings[][LEN], int num); 
void print_menu(void);
int word_length(char * ar);
int check(char ch);

int main(void) {
	char strs[SCOUNT][LEN];
	char message[] = "Введите строку, или 'q' для выхода\n";
	char *pts[SCOUNT]; // массив переменных типа указателя
	
	int count = 0;

	puts(message);
	while (count < SCOUNT && fgets(strs[count], LEN, stdin)) {
		if (check_exit(strs[count])) 
			break;
		
		if (check_eof(strs[count]))
			break;

		++count;
		printf("Введено строк: %d\n", count);
		puts(message);
		continue;
	}

	set_ptrs(pts, strs, count); 

	char ch;
	print_menu();
	while ((ch = getchar()) != 'q') {
		if ('\n' == ch)
			continue;
		if (islower(ch)) {
			switch (ch) {
				case 'a': 
					source_print(strs, count);
					break;
				case 'b':
					sort_by_ascii(pts, count);
					print_all(pts, count);
					break;
				case 'c':
					sort_by_length(pts, count);
					print_all(pts, count);
					break;
				case 'd':
					sort_by_first_word_length(pts, count);
					print_all(pts, count);
					break;
			}
		}
		while (getchar() != '\n')
			continue;
		print_menu();
	}
	return 0;
}

void print_all(char *strs[], int num) {
	for (int i = 0; i < num; ++i)  {
		printf("%s\n", strs[i]);
	}
}

int check_eof(char * str) {
	while (*str) {
		if (*str == EOF)
			return 1;
		++str;
	}
	return 0;
}

int check_exit(char * str) {
	if (*str == 'q')
		return 1;
	return 0;
}

void print_menu() {
	printf("\nВыберите один из вариантов\n");
	printf("a. Вывод исходного списка строк\n");
	printf("b. Вывод строк согласно последовательности сопоставления ASCII\n");
	printf("c. Вывод строк в порядке возрастания длинны\n");
	printf("d. Вывод строк строк в порядке возрастания длины первого слова в строке\n");
	printf("q. Выход из программы\n\n");
}

void sort_by_length(char *strings[], int num) {	
	char *temp;
	int top, seek;
	for (top = 0; top < num - 1; top++)
		for (seek = top + 1; seek < num; seek++)
			if (strlen(strings[top]) > strlen(strings[seek])) 
			{
				temp = strings[top];
				strings[top] = strings[seek];
				strings[seek] = temp;
			}
}

void sort_by_first_word_length(char *strings[], int num) {	
	char *temp;
	int top, seek;
	for (top = 0; top < num - 1; top++)
		for (seek = top + 1; seek < num; seek++)
			if (word_length(strings[top]) > word_length(strings[seek])) 
			{
				temp = strings[top];
				strings[top] = strings[seek];
				strings[seek] = temp;
			}
}

void sort_by_ascii(char *strings[], int num) {	
	char *temp;
	int top, seek;
	for (top = 0; top < num - 1; top++)
		for (seek = top + 1; seek < num; seek++)
			if (strcmp(strings[top], strings[seek]) > 0) 
			{
				temp = strings[top];
				strings[top] = strings[seek];
				strings[seek] = temp;
			}
}

void set_ptrs(char *pts[], char strings[][LEN], int num) {
	for (int i = 0; i < num; ++i) {
		pts[i] = strings[i];
	}
}

void source_print(char strs[][LEN], int num) {
	for (int i = 0; i < num; ++i)  {
		printf("%s\n", strs[i]);
	}
}

int word_length(char * ar) {
	char ch;
	int trigger = 0;
	int i = 0;

	while (*ar) {
		if (check(*ar)) {
			if (trigger) {
				break;
			}
			else {
				++i;
				continue;
			}
		} else {
			trigger = 1;
			++ar;
		}
		++i;
	}

	return i;
}

int check(char ch) {
	int size = 3;
	char symbols[] = {'\t', ' ', '\n' }; 
	int i;

	for (i = 0; i < size; i++) {
		if (ch == symbols[i]) {
			return 1;
		}		
	}

	return 0;
}
