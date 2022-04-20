#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void * customThreadFunction()
{
	for (int i = 0; i < 5; i++)
	{
		printf("I am a custom thread func\n");
		sleep(1);
		if(i == 3)
		{
			printf("My job is DONE. TERMINATE\n");
			pthread_exit(NULL);
		}
	}

	return NULL;
}

int main(void)
{
	pthread_t thread; // thread descriptor
	pthread_create(&thread, NULL, customThreadFunction, NULL);

	for (int i = 0; i < 5; i++)
	{
		printf("I am process default\n");
		sleep(1);
	}
	return 0;
}
