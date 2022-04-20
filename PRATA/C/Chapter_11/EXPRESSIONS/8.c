#include <stdio.h>
#include <string.h>

#define COUNT 3

char * string_in(char * str1, const char * str2);

int main(void) {
	char sample_str[] = "Hi sunday, i get money";

	const char * sample_strings_ptr[COUNT] = {
		"sun",
		"hueta",
		"moneyyyyyyy"
	};

	int i = 0;
	while (i < COUNT) {
		printf("***NEXT ITER***\n");
		char * ptr;
		ptr = string_in(sample_str, sample_strings_ptr[i]);
		++i;
		
		if (ptr)
			printf("Result %d: char '%c', addr %p\n", i, *ptr, ptr);
		else
			puts("Не найдено");

		printf("\n");
	}

	return 0;
}

char * string_in(char * str1, const char * str2) {

	int cur_pos_str2 = 0;
	int trigger = 0;

	// первое совпадение
	char * coin_ptr;

	while (*str1) {

		// if (str2[cur_pos_str2] == '\0' || str2[cur_pos_str2] == '\n') {
		// 	return coin_ptr;
		// }

		printf("Char: %c, search char: %c\n", *str1, str2[cur_pos_str2]);

		if (str2[cur_pos_str2] == *str1) {
			if (cur_pos_str2 == 0)
				coin_ptr = str1;

			trigger = 1;
			++cur_pos_str2;
		} else {	
			if (trigger)
				return 0;
			else 
				coin_ptr = 0;
		}
		++str1;
	}	

	return coin_ptr;
}
