#include <stdio.h>
#include <string.h>

#define COUNT 3

char * reverse(char * str1);

int main(void) {
	char sample[] = "ABRAKADABRA";
	char * ptr1;
	ptr1 = reverse(sample);
	puts(ptr1);
	return 0;
}

char * reverse(char * str1) {
	
	char * start = str1;
	int length = 0;

	while(*start) {
		++length;	
		++start;
	}

	start = str1;
	char temp_str[length];
	char * end = str1 + (length - 1);

	int l_dir = length - 1;
	int r_dir = 0;

	while (*start) {
		temp_str[r_dir] = *start;

		if (temp_str[l_dir]) {
			*start = temp_str[l_dir];	
		} else {
			*start = *end;
		}

		++start;
		--end;

		--l_dir;
		++r_dir;
	}

	return str1;
}
