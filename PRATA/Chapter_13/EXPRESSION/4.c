#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char * argv[]) {

	FILE *fp;

	for (int i = 1; i < argc; ++i) {
		if ((fp = fopen(argv[i], "rb")) == NULL) 
		{
			printf("Не удается открыть %s\n", argv[i]);
			continue;
		}
		
		printf("Файл %s:\n", argv[i]);

		char ch;
		while ((ch = getc(fp)) != EOF) 
		{
			putc(ch, stdout);
		}
		printf("\n\n");
		fclose(fp);
	}

	return 0;
}

