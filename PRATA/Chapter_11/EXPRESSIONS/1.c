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
	printf("Введите строчку: ");
	fgets(ar, len, stdin);
}

