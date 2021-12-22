#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]) {
	printf("%d\n", argc);
	if (argc > 2) {
		char ** end;
		double number = strtod(argv[1], end);
		int exp = strtoq(argv[2], end, 10);
		double result = number;

		for (int i = 1; i < exp; ++i) {
			result *= number;	
		}
		printf("%.2f\n", result);
	}
	return 0;
}
