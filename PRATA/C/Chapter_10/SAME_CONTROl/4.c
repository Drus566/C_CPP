#include <stdio.h>
int main(void)
{

	// int *ptr;
	// int torf[2][24] = {12, 14, 16, [23] = 1212, [24] = 55};
	// ptr = torf[0];

	// printf("%d %d\n", *ptr, *(ptr + 2));
	// printf("%d \n", torf[0][23]); 
	// printf("%d \n", torf[0][24]); 
	// printf("%d \n", torf[0][22]); 
	//
	
	int *ptr;
	int fort[2][2] = {{12}, {14, 16}};
	ptr = fort[0];
	printf("%p, %d \n", ptr,*ptr); 
	return 0;
}
