#include <stdio.h>
char * check_space(char * str);

int main(void) {
	char sample[30] = "gibroGGWP";
	char * ptr;
	ptr = check_space(sample);
	printf("Ptr - %p, Value - %c\n", ptr, *ptr);
	return 0;
}

char * check_space(char * str) {
	while (*str != '\0') {
		if (*str == ' ')	
			return str;
		str++;
	}	

	return NULL;
}
