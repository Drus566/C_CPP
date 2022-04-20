#include <math.h>
#include <stdio.h>
#include <stdlib.h> 

int main(int argc, char * argv[])
{
	char * end;
	float ss;
	ss = atof(argv[1]);
	double root = strtod(argv[1], &end);
	printf("root: %f\n", root);
	printf("Квадратный корень из %f равен %f\n", root, sqrt(root));
	printf("ss: %f\n", ss);

	return 0; 
}
