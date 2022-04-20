#include <stdio.h> 
#define COUNT 20
int sample (int * ar, int count, int search);

int main(void)
{
	int ars[COUNT] = { 1, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 14, 28, 30, 45, 66, 81, 82, 83, 91 };
	printf("%d\n", sample(&ars[0], COUNT, 1));
	printf("%d\n", sample(&ars[0], COUNT, 91));
	printf("%d\n", sample(&ars[0], COUNT, -1));
	printf("%d\n", sample(&ars[0], COUNT, 100));
	return 0; 
}

int sample (int * ar, int count, int search)
{
	int left = 0;
	int right = COUNT - 1;	
	int pos;

	while (left <= right)
	{
		pos = (left + right) / 2;

		if (search < ar[pos])
			right = pos - 1;
		else if (search > ar[pos])
			left = pos + 1;
		else
			return 1;
	}
	return -1;
}
