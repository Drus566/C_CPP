#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void * customThreadFunction()
{
	printf("I am a custom thread func\n");
	return NULL;
}

int main(void)
{
	pthread_t thread1, thread2; // thread descriptor
	pthread_create(&thread1, NULL, customThreadFunction, NULL);
	pthread_create(&thread2, NULL, customThreadFunction, NULL);

	if (pthread_equal(thread1,thread2))
	{
		printf("Two thread are EQual..!\n");
	}
	else
	{
		printf("Two thread are not equal\n");
	}
	return 0;
}
