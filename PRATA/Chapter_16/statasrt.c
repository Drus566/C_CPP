// 16.19
#include <stdio.h>
#include <limits.h>
_Static_assert(CHAR_BIT == 16, "Ошибочно предполагается 16-битовый тип char");
int main(void)
{
	puts("Тип чар имеет 16 битов");
	return 0;
}
