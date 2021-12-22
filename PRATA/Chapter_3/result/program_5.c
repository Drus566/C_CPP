#include <stdio.h>
int main(void)
{
	long double seconds_in_year = 3.156e+07;
	unsigned short int age;
	printf("Введите возраст (полных лет): ");
	scanf("%hd", &age); 
	printf("%d", age);
	seconds_in_year = age * seconds_in_year;
	printf("\nВы прожили %.Lf секунд...\n", seconds_in_year);	

}
