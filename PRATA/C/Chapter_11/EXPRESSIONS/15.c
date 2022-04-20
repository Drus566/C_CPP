#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char ** argv) {
	char * ch = *(++argv);
	char ** end;

	if (argc > 1) {
		while (*ch) {
			if (!isdigit(*ch)) {
				printf("Не числовая\n");
				return 0;
			};
			++ch;
		}	
		int dig = strtoq(*argv, end, 10);
		printf("%d\n", dig);
	}	

	return 0;
}
