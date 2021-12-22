#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char * argv[]) {
	if (argc < 1) {
		printf("Некорректное количество аргументов\n");
		printf("Введите как минимум символ...\n");
		exit(EXIT_FAILURE);
	}

	char symbol;
	symbol = argv[1][0];

	if (argc > 1) {
		FILE *fp;

		for (int i = 2; i < argc; ++i) {
			int count = 0;
			char ch;

			if ((fp = fopen(argv[i], "r")) == NULL) {
				printf("Невозможно открыть файл %s\n", argv[i]);
				continue;
			}	

			while ((ch = getc(fp)) != EOF)
			{
				if (ch == symbol)
					++count;
			}
			fclose(fp);

			printf("Количество символов '%c' в файле %s равно %d\n", symbol, argv[i], count);
		}
	}
}
