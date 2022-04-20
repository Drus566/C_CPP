#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void * customThreadFunction()
{
	for (int i = 0; i < 15; i++)
	{
		printf("I am a custom thread func\n");
		sleep(4);
	}

	return NULL;
}

int main(void)
{
	pthread_t thread; // thread descriptor
	int status; // status thread
	status = pthread_create(&thread, NULL, customThreadFunction, NULL); 
	// status 0 if successfully
	
	if (!status)
	{
		printf("Custom Created Successfully.\n");
	}
	else
	{
		printf("Unable to create the custom thread\n");
		return 0;
	}

	for (int i = 0; i < 15; i++)
	{
		printf("I am the process thread created by compiler by default\n");
		sleep(1);
	}
	return 0;
}
