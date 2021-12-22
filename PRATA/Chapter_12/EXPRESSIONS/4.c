#include <stdio.h>

void callback(void);

int main(void)
{
	for (int i = 0; i < 10; ++i) {
		callback();		
	}
	return 0;
}

void callback(void) {
	static int count = 0;
	printf("Я вызвана %d раз(а)\n", ++count);
}
