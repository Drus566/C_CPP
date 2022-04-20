#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 100 

void func(FILE * fp, int * toggle);

int main(int argc, char * argv[])
{
	if (argc < 2) {
		printf("Аргументы: имя_файла, имя_файла\n");
		exit(EXIT_FAILURE);
	}

	FILE * first;
	FILE * second;

	char f_file[LEN];
	char s_file[LEN];

	strcpy(f_file, argv[1]);
	strcpy(s_file, argv[2]);

	if ((first = fopen(f_file, "r")) == NULL) 
	{
		printf("Не удается открыть файл %s\n", f_file);
		exit(EXIT_FAILURE);
	}

	if ((second = fopen(s_file, "r")) == NULL) 
	{
		printf("Не удается открыть файл %s\n", s_file);
		exit(EXIT_FAILURE);
	}

	int f_file_done = 0;
	int s_file_done = 0;

	while (1) 
	{
		if ((f_file_done == 1) && (s_file_done == 1))
			break;

		if (f_file_done == 0)
			func(first, &f_file_done);

		if (s_file_done == 0)
			func(second, &s_file_done);

		printf("\n");
	}	

	fclose(first);
	fclose(second);

	return 0;
}

void func(FILE * fp, int * toggle)
{
	int count = 0;
	char ch;
	while (ch = getc(fp))
	{
		++count;

		if (ch == EOF) {
			++*toggle;
			break;	
		}

		if (ch == '\n')
		{
			putc(' ', stdout);
			break;
		}

		putc(ch, stdout);
	}
}
