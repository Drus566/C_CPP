#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#define MAX 30

struct player {
	char fname[MAX];
	char lname[MAX];
	int rate;
	int pass;
 	int scamper;	
};

int main(void)
{
	struct player players[20];

	FILE * fp;

	if ((fp = fopen("sample.txt", "r")) == NULL)
	{
		printf("Не удается открыть файл.\n");
		exit(EXIT_FAILURE);
	}

	int i;
	char temp_fname[MAX];
	char temp_lname[MAX];
	int temp_rate;
	int temp_pass;
	int temp_scamper;

	int count = 0;
	while (fscanf(fp, "%d %s %s %d %d %d", &i, temp_fname, temp_lname, &temp_rate, &temp_pass, &temp_scamper) == 6) {
		strcpy(players[count].fname, temp_fname);
		strcpy(players[count].lname, temp_lname);
		players[count].rate = temp_rate;
		players[count].pass = temp_pass;
		players[count].scamper = temp_scamper;
		++count;
	}

	for (int i = 0; i < count; ++i) {
		printf("%d %s %s %d %d %d\n", i, players[i].fname, players[i].lname, players[i].rate, players[i].pass, players[i].scamper);
	}

	printf("Готово.\n");

	fclose(fp);

	return 0; 
}
