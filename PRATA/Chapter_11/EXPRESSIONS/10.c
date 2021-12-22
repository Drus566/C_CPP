#include <stdio.h>
#include <string.h>
#define LEN 30 

void del_spaces(char * str); 
int empty(char * str1);

int main(void) {
	char line[LEN];
	char message[] = "Введите строку, или пустую строку для выхода";

	puts(message);
	while (fgets(line, LEN, stdin)) {
		
		if (empty(line))
			break;

		del_spaces(line);
		puts(line);
		puts(message);
		continue;
	}

	return 0;
}

void del_spaces(char * str) {
	// текущий символ
	char * cur_ch;
	// предыдущий символ
	char * prev_ch;
	// сдвиг
	int shift = 0;
	
	int i = 0;

	while (str[i]) {
		if (str[i] == ' ') {
			++shift;
		}	else {
			str[i - shift] = str[i];
			if (shift > 0) {
				str[i] = '\0';
			}
		}
		++i;
	}
}

int empty(char * str1) {

	if (*str1 == '\n' || *str1 == '\0')
		return 1;
	return 0;	
}
