#include <stdio.h>
int main(void) {
	char ss[10];
	int gg[10];
	printf("%d\n", gg[0]);
	int i = 0;
	printf("'%c'\n", ss[0]);
	while (ss[i]) {
		printf("GGWP");
		printf("%c\n", ss[i]);
		++i;
	}
	return 0;
}
