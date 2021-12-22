#include <stdio.h>
#include <string.h>
#define WORDS "наихудшим"
#define SIZE 40

int main(void)
{
	const char * orig = WORDS;
	char copy[SIZE] = "Будьте лучшим, чем могли бы быть.";
	char *ps;

	puts(orig);
	puts(copy);
	ps = strcpy(copy + 7, orig);
	puts(copy);
	puts(ps);

	return 0;
}
