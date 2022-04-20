#include <stdio.h>
void b(void);
void a(void);
void c(void);

int main(void)
{
	a();
	printf("\n******\n");
	b();
	printf("\n******\n");
	c();
	printf("\n******\n");
	return 0;
}

void b(void)
{
	int x = 100;
	while (x++ < 103)
	printf("%4d\n", x);
	printf("ggwp%4d\n", x);
}

void a(void)
{
	int x = 0;
	while (++x < 3)
		printf("%4d", x);
}


void c(void)
{
	char ch = 's';
	while (ch < 'w')
	{
		printf("%c", ch);
		ch++;
	}
	printf("%c\n", ch);
}
