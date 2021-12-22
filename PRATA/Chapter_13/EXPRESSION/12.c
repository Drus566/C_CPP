#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <ctype.h>

#define ROWS 20
#define COLS 30
#define LENGTH 33
#define GRADIENT 10 

void translate_to_chars(int src[ROWS][COLS], char dst[ROWS][COLS + 1], char gradient[]);
void export_to_file(FILE * fp, char filename[], char db[ROWS][COLS + 1]);
void load_from_file(FILE * fp, char * filename, int db[ROWS][COLS]);
int find_symbol(char str[], int comparable);

int main(int argc, char * argv[])
{
	int db[ROWS][COLS];
	char c_db[ROWS][COLS + 1];

	char filename[LENGTH] = "krest.txt";
	char export_filename[LENGTH + 6];
	char symbols[GRADIENT] = " .':~*=k%#"; 

	strcpy(export_filename, filename);
	strcat(export_filename, ".export");

	FILE * fp;

	load_from_file(fp, filename, db);
	translate_to_chars(db, c_db, symbols);
	export_to_file(fp, filename, c_db);

	printf("\n\n");

	for (int i = 0; i < ROWS; ++i) {
		for (int j = 0; j < COLS + 1; ++j) {
			printf("%c", c_db[i][j]);
		}
		printf("\n");
	}

	return 0;	
}

void load_from_file(FILE * fp, char * filename, int db[ROWS][COLS]) {
	if ((fp = fopen(filename, "r+")) == NULL) {
		printf("Не удалось открыть файл %s.\n", filename);
		exit(EXIT_FAILURE);	
	}

	int i = 0;
	int j = 0;

	char ch;
	char str[2];

	while ((ch = getc(fp)) != EOF) 
	{
		if (i > ROWS) 
			break;

		if (ch == '\n')
		{
			++i;
			j = 0;
			continue;
		}	
			
		if (isdigit(ch)) {
			str[0] = ch;
			str[1] = '\0';
			db[i][j] = atoi(str);
			++j;
		}
	}

	fclose(fp);
	
	for (int i = 0; i < ROWS; ++i) {
		for (int j = 0; j < COLS; ++j) {
			printf("%d ", db[i][j]);
		}
		printf("\n");
	}
}


void translate_to_chars(int src[ROWS][COLS], char dst[ROWS][COLS + 1], char gradient[]) 
{
	int pos;
	for (int i = 0; i < ROWS; ++i) 
	{
		for (int j = 0; j < COLS; ++j) 
		{
			if (j == 30) {
				dst[i][j + 1] = '\0';
				continue;
			}

			if ((pos = find_symbol(gradient, src[i][j])) > -1) 
			{
				dst[i][j] = gradient[pos]; 
			}
		}
	}
}

int find_symbol(char str[], int comparable)
{
	for (int i = 0; i < GRADIENT; ++i) {
		if (i == comparable) {
			return i;
		}
	}
	return -1;
}

void export_to_file(FILE * fp, char filename[], char db[ROWS][COLS + 1]) {
	if ((fp = fopen(filename, "w")) == NULL) {
		printf("Невозможно сохранить файл %s\n", filename); 
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < ROWS; ++i) {
		for (int j = 0; j < COLS; ++j) {
			putc(db[i][j], fp);
		}
		putc('\n', fp);
	}

	fclose(fp);
}
