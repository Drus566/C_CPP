#include <stdio.h>
#include <string.h> // для strlen()
#define DENSITY 62.4
int main()
{
	float weight, volume;
	int size, letters;
	char name[40];
	
	printf("Здравствуйте! Как вас зовут?\n");
	scanf("%s", &name);
	printf("%s, сколько вы весите в фунтах?\n", name);
	scanf("%f", &weight);
	size = sizeof name;
	letters = strlen(name);
	volume = weight / DENSITY;
	printf("Хорошо, %s, ваш объем составляет %2.2f кубических футов.\n", name, volume);
	printf("К тому же ваше имя состоит из %d букв,\n", letters);
	printf("и мы располагаем %d байтами для его сохранения.\n", size);
	return 0;
}
			
