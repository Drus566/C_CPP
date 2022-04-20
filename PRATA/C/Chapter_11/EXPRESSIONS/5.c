#include <stdio.h>
#include <string.h>

#define LENGTH 10 

char * check_char(char * str, char ch);

int main(void) {
	char * str;
	printf("Введите строку: ");
	fgets(str, LENGTH, stdin);
	
	char search = 's';
	char * ch = check_char(str, search);
	if (ch) {
		printf("Найден указанный символ: %c\nЕго адрес: %p", *ch, ch); 
	} else {
		printf("Символ не найден");
	}

	printf("\n");
	return 0;
}

char * check_char(char * str, char ch) {
	while (*str) {
		if (*str == ch) {
			return str;
		}	
		++str;
	}
	return 0;
}
