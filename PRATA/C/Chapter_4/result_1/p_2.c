#include <stdio.h>
int main(void)
{
	char name[20];

	printf("Введите имя: ");
	int length_name = scanf("%s", name);
	printf("\"%s\"\n", name);
	printf("\"%20s\"\n", name);
	printf("\"%-20s\"\n", name);
	printf("%*s\n", length_name + 3 , name);


}
