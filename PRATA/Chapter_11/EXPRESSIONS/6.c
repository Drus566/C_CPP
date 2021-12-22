#include <stdio.h>
#include <string.h>

#define LENGTH 10 
#define COUNT 3
#define SLEN 40

int check_char(char ch, char * str);

int main(void) {
	const char * sample_strings_ptr[COUNT] = {
		"Privet andeuy",
		"PRIVEEET ANDREYY!",
		"NU OBNUMI менЯ КСКАРЕЙ"
	};

	const char sample_strings_ar[COUNT][SLEN] = {
		"GONAYUS PO DVORY",
		"za sobstvennom hvostom",
		"i tak pokuda ne pomru"
	};

	const char search = 'i';

	int i = 0;
	while (i < COUNT) {
		puts(sample_strings_ar[i]);

		int ch = check_char(search, sample_strings_ar[i]);
		if (ch) 
			printf("Найден указанный символ\n"); 
		else 
			printf("Символ не найден\n");

		printf("\n");
		++i;
	}

	
	printf("\n");

	return 0;
}

int check_char(char ch, char * str) {
	while (*str) {
		if (*str == ch) {
			return *str;
		}	
		++str;
	}
	return 0;
}
