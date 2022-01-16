#include <pthread.h>
#include <stdio.h>

int count; // общие данные для потоков
int atoi(const char *nptr);
void *potok(void * param); // потоковая функция 

int main(int argc, char * argv[])
{
	pthread_t tid; // идентификатор потока
	pthread_attr_t attr; // аттрибуты потока

	if (argc != 2)
	{
		fprintf(stderr, "usage: 1 <interger value>\n");
		return -1;
	}

	if (atoi(argv[1]) < 0) {
		fprintf(stderr, "Аргумент %d не может быть отрицательным числом\n", atoi(argv[1]));
		return -1;
	}

	// получаем значения аттрибутов по умолчанию
	pthread_attr_init(&attr);

	// создаем новый поток
	pthread_create(&tid, &attr, potok, argv[1]);

	// ждем завершения исполнения потока
	pthread_join(tid, NULL);
	printf("count = %d\n", count);

	return 0;
}

void *potok(void *param)
{
	int i, upper = atoi(param);
	count = 0;

	if (upper > 0) 
	{
		for (i = 1; i <= upper; i++)
			count += i;
	}

	pthread_exit(0);
}
