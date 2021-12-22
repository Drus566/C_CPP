#include <stdio.h>
#include "pe12-2a.h"

int main(void)
{
	int mode;
	printf("Введите 0 для метрического режима или 1 для американского режима: ");
	scanf("%d", &mode);

	while (mode >= 0)
	{
		set_mode(mode);
		get_info();
		show_info();
		printf("Введите 0 для метрического режима или 1 для американского режима");
		printf(" (-1 для завершения): ");
		scanf("%d", &mode);
	}

	printf("Программа завершена.\n");
	return 0;
}
