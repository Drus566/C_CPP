#include <stdio.h>
#include <string.h>

#define LENGTH 10 
#define COUNT 3

char * mystrncpy(char * str1, const char * str2, int n);

int main(void) {
	char sample_str[LENGTH];

	const char * sample_strings_ptr[COUNT] = {
		"Privet andeuy",
		"PRIVEEET ANDREYY!",
		"NU OBNUMI менЯ КСКАРЕЙ"
	};

	int i = 0;
	while (i < COUNT) {
		char * ptr;
		ptr = mystrncpy(sample_str, sample_strings_ptr[i], LENGTH);
		++i;
		fputs(ptr, stdout);
		printf("\n");
	}

	return 0;
}

char * mystrncpy(char * str1, const char * str2, int n) {
	char * start = str1;

	int counter = 0;

	while (counter < n) {
		*str1 = *str2;
		++str1; ++str2;
		++counter;
	}	

	return start;
}
