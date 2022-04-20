#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int check_mode(char str[]);

int main(int argc, char *argv[]) {
	int mode = 0;

	if (argc > 1) {
		mode = check_mode(argv[1]);
	}

	char ch;
	while ((ch = getchar()) != EOF) {
		switch (mode) {
			case 0:
				printf("%c", ch);
				break;
			case 1:
				printf("%c", toupper(ch));
				break;
			case 2:
				printf("%c", tolower(ch));
				break;
		}
	}
	return 0;
}

int check_mode(char str[]) {
	if (str[0] == '-') {
		if (str[1] == 'u') {
			return 1;
		} else if (str[1] == 'l') {
			return 2;
		}
		return 0;
	}
	return 0;
}
