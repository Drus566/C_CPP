#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COUNT 1000
#define LIMIT 10

void generate_rand(int numbers[]);

int main(void)
{
	int numbers[LIMIT] = {};

	for (int i = 0; i < LIMIT; ++i) {
		generate_rand(numbers);
	}

	for (int i = 0; i < LIMIT; ++i) {
		printf("%d появлялась %d раз(а)\n", i + 1, numbers[i]);
	}	

	return 0;
}

void generate_rand(int numbers[]) {
	srand((unsigned int) time(0));

	for (int i = 0; i < COUNT; ++i) {
		int digit = (int)rand() % 10 + 1;

		for (int j = 0; j < LIMIT; ++j) {
			if (digit == j + 1) {
				++numbers[j];
				break;
			}
		}
	}
}

