#include <stdio.h>
void butler(void); // Прототип функции 

int main(void)
{
	printf("Я вызываю дворецкого.\n");
	butler();
	printf("Да. Принесите мне чай и записываемые DVD-диски.\n");
	return 0;
}

void butler(void)
{
	printf("Вы звонили, сэр?\n");
}
