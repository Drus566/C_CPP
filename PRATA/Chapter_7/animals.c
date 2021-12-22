#include <stdio.h>
#include <ctype.h>
int main(void)
{
	char ch;
	printf("Дайте мне букву алфавита, и я укажу вам ");
	printf("название животного.\n");
	printf("Введите букву или # для завершения.\n");
	while ((ch = getchar()) != '#')
	{
		if ('\n' == ch)
			continue;
		if (islower(ch))
		{
			switch (ch)
			{
				case 'a':
					printf("архар\n");
					break;
				case 'b':
					printf("бабирусса\n");
					break;
				case 'c':
					printf("коати, носуха обыкновенная\n");
					break;
					default:
					printf("Вопрос озадачил!\n");
			}
		}
		else
			printf("Распознаются только строчные буквы.\n");
		while (getchar() != '\n')
			continue;
		printf("Введите следующую букву или # для завершения.\n");
	}
	printf("До свидания.\n");
	return 0;
}

