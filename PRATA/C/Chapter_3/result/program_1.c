#include <stdio.h>
#include <inttypes.h>
#include <math.h>

int main(void)
{
	int test_int;
	short test_short;
	long test_long;
	long long test_long_long;
	char test_char;
	_Bool test_bool;

	int32_t test_int32_t;
	int_least8_t test_int_least8_t;
	intmax_t test_intmax_t;
	uintmax_t test_uintmax_t;

	double test_double;
	float test_float;

	printf("Целочисленные типы:\n\n");
	printf("Int размер в байтах: %ld, от -%.f до %.f\n", sizeof(test_int), ((pow(2, sizeof(test_int) * 8)) / 2), ((pow(2, sizeof(test_int) * 8)) / 2) - 1);
	printf("Short размер в байтах: %ld, от -%.f до %.f\n", sizeof(test_short), ((pow(2, sizeof(test_short) * 8)) / 2), ((pow(2, sizeof(test_short) * 8)) / 2) - 1);
	printf("Long размер в байтах: %ld, от -%.f до %.f\n", sizeof(test_long), ((pow(2, sizeof(test_long) * 8)) / 2), ((pow(2, sizeof(test_long) * 8)) / 2) - 1);
	printf("Long long размер в байтах: %ld, от -%.f до %.f\n", sizeof(test_long_long), ((pow(2, sizeof(test_long_long) * 8)) / 2), ((pow(2, sizeof(test_long_long) * 8)) / 2) - 1);
	printf("char размер в байтах: %ld, от -%.f до %.f\n", sizeof(test_char), ((pow(2, sizeof(test_char) * 8)) / 2), ((pow(2, sizeof(test_char) * 8)) / 2) - 1);
	printf("_Bool размер в байтах: %ld, от -%.f до %.f\n", sizeof(test_bool), ((pow(2, sizeof(test_bool) * 8)) / 2), ((pow(2, sizeof(test_bool) * 8)) / 2) - 1);

	printf("\n\nПереносимые типы:\n\n");
	printf("Int32_t размер в байтах: %ld, от -%.f до %.f\n", sizeof(test_int32_t), ((pow(2, sizeof(test_int32_t) * 8)) / 2), ((pow(2, sizeof(test_int32_t) * 8)) / 2) - 1);
	printf("Int_least8_t размер в байтах: %ld, от -%.f до %.f\n", sizeof(test_int_least8_t), ((pow(2, sizeof(test_int_least8_t) * 8)) / 2), ((pow(2, sizeof(test_int_least8_t) * 8)) / 2) - 1);
	printf("intmax_t размер в байтах: %ld, от -%.f до %.f\n", sizeof(test_intmax_t), ((pow(2, sizeof(test_intmax_t) * 8)) / 2), ((pow(2, sizeof(test_intmax_t) * 8)) / 2) - 1);
	printf("Uintmax_t размер в байтах: %ld, от -%.f до %.f\n", sizeof(test_uintmax_t), ((pow(2, sizeof(test_uintmax_t) * 8)) / 2), ((pow(2, sizeof(test_uintmax_t) * 8)) / 2) - 1);

/* 
	printf("\n\nЧисла с плавающей точкой:\n\n");
	printf("double размер в байтах: %ld, от -%e до %e\n", sizeof(test_double), ((pow(2, sizeof(test_double) * 8)) / 2), ((pow(2, sizeof(test_double) * 8)) / 2) - 1);
	printf("float размер в байтах: %ld, от -%.f до %.f\n", sizeof(test_float), ((pow(2, sizeof(test_float) * 8)) / 2), ((pow(2, sizeof(test_float) * 8)) / 2) - 1);
*/

	printf("\n\nПереполнение, потеря значимости:\n\n");
	test_int = pow(2, sizeof(test_int) * 8) / 2;
	printf("int: %d, %d\n", test_int, test_int + 1);	
	test_long = pow(2, sizeof(test_long) * 8) / 2;
	printf("long: %ld, %ld\n", test_long, test_long + 1);
	test_short = pow(2, sizeof(test_int) * 8) / 2;
	printf("short: %hd, %hd\n", test_short, test_short + 1);
	test_char = pow(2, sizeof(test_char) * 8) / 2;
	printf("char: %hhd, %hhd\n", test_char, test_char + 1);
	test_double = pow(2, sizeof(test_double) * 8) / 2;
	test_double = 3.4E-324;
	printf("double: %e, %e\n", test_double, test_double / 10.0f);
	test_float = 3.4E38;
	printf("float: %e, %e\n", test_float, test_float * 100.0f);
}

