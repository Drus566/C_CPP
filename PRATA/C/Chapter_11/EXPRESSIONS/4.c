#include <stdio.h>
#include <string.h>

#define LENGTH 10 

void extract_word(int length, char * ar);
int check(char ch);

int main(void) {
	char ar[LENGTH];
	extract_word(LENGTH, ar);
	fputs(ar, stdout);
	printf("\n");
	return 0;
}

void extract_word(int length, char * ar) {

	char ch;
	int trigger = 0;

	int i = 0;

	while ((ch = getchar()) != '\n') {
		printf("\nLIMIT: %d, i: %d\n", length, i);
		printf("Symbol: %c\n", ch);
		if (i < length) {
			if (check(ch)) {
				printf("\nIS SPACE\n");
				if (trigger) {
					*ar = '\0';
					break;
				}
				else {
					++i;
					continue;
				}
			} else {
				trigger = 1;
				*ar = ch;
				++ar;
			}
			++i;
		}
	}
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
