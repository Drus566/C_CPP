#include <stdio.h>

void trystat(void);

int main(void) {
	int count;
	for (count = 1; count <= 3; count++) {
		printf("Начинается итерация %d:\n", count);
		trystat();
	}

	return 0;
}

void trystat(void) {
	int fade = 1;
	static int stay;

	printf("fade = %d и stay = %d\n", fade++, stay++);
}
