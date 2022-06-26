#include <pthread.h>
#include <time.h>
#include <stdio.h>

int main(void)
{
	clock_t start = clock();
	start_timer(10);
	int i = 0;
	for(i = 0; i < 1000; i++) {}
	printf("Cur time: %d\n", current_time());

	do {

	} while (msec < trigger);

	return 0;
}

 
