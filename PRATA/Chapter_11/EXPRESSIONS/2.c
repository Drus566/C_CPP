#include <stdio.h>
#include <string.h>

#define LENGTH 10 
void extract(int len, char * ar);

int main(void) {
	char sample_ar[LENGTH];
	extract(LENGTH, sample_ar);
	fputs(sample_ar, stdout);
	printf("\n");
	return 0;
}

void extract(int len, char * ar) {
	char symbols[4] = {'\n', '\t', ' ', '\0'};

	printf("Введите строчку: ");
	char * status = fgets(ar, len, stdin);

	int i = 0;
	char * ptr;

	if (status) {
		while (symbols[i] != '\0') {
			if ((ptr = strchr(ar, symbols[i])) != 0) {
				*ptr = '\0';
			}
			++i;
		}
	}

	// if (status)
	// {
	// 	while ((ar[i] != '\n') || (ar[i] != '\t') || (ar[i] != ' ') || (ar[i] != '\0')) {
	// 		++i;
	// 	}

	// 	*ar = '\0';
	// }
}

