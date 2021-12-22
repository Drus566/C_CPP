#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int length = 30;
	int count;	

	printf("Введите количество слов, которое необходимо ввести\n");

	while(scanf("%d", &count) == 1 && count > 0) {
		char (*ptd)[count];
		ptd = (char (*)[count]) malloc(length * count * sizeof(int)); 
		
		printf("Теперь введите %d слов\n", count);

		for (int i = 0; i < count; ++i) {
			scanf("%s", ptd[i]); 
			printf("%s\n", ptd[i]);
		}

		while (getchar() != '\n')
			continue;

		free(ptd);

		printf("Введите количество слов, которое необходимо ввести\n");
		continue;
	}

	return 0;
}
