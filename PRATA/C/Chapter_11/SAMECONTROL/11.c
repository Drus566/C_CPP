#include <stdio.h>
#include <string.h>

char * s_gets(char *st, int n);

int main(void)
{
	char ss[30];
	s_gets(ss, 30);
	puts(ss);
	return 0;
}

char * s_gets(char *st, int n)
{
	char * ret_val;
	char * find;
	int i = 0;

	fgets(st, n, stdin);
	find = strchr(st, '\n');

	if (find)
		*find = '\0';

	return st;
}
