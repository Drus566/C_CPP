#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *sayGreetings(void *input)
{
	printf("Hello %s\n", (char *)input);
	pthread_exit(NULL);
}

int main(void)
{
	char name[50];
	printf("Enter your name: \n");
	fgets(name, 50, stdin);

	pthread_t thread;

	pthread_create(&thread,NULL,sayGreetings,name);
	// ожидает завершений потока thread
	pthread_join(thread,NULL);

	return 0;
}
