#include <stdio.h>
#define MAX 20

char * s_gets(char * st, int n);

int main(void)
{
	char first[MAX];
	char last[MAX];

	char formal[2 * MAX + 10];
	double prize;

	puts("Введите свое имя:");
	s_gets(first, MAX);
	puts("Введите свою фамилию:");
	s_gets(last, MAX);
	puts("Введите сумму денежного приза:");
	scanf("%lf", &prize);
	sprintf(formal, "%s, %-19s: $%6.2f\n", last, first, prize);
	puts(formal);

	return 0;
}

char * s_gets(char * st, int n)
{
	char * ret_val;
	int i = 0;

	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		while (st[i] != '\n' && st[i] != '\0')
			i++;
		if (st[i] == '\n')
			st[i] = '\0';
		else
			while (getchar() != '\n')
				continue;
	}
	return ret_val;
}
