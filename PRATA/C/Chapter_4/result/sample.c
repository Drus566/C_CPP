#include <stdio.h>
#define Q "\"Его Гамлет был хорош.\""
int main(void)
{
	printf("Он продал эту картину за $%2.2f.\n", 3.345e2);
	printf("%c%c%c\n", 'H', 105, '\41');
	printf("%s \nсодержит %d символов.\n", Q, strlen(Q));
	printf("Является ли %2.2e тем же, что и %2.2f?\n", 1201.0, 1201.0);
}
