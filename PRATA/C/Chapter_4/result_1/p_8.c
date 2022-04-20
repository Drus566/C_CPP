#include <stdio.h>
int main(void)
{
	const float litr_in_gallone = 3.785;
	const float km_in_mile = 1.609;

	float c_mile;
	float c_fuel;

	printf("Введите количество преодоленных миль и количество \
галлонов израсходованного бензина: ");
	scanf("%f %f", &c_mile, &c_fuel);
	float mile_in_gallone = c_mile / c_fuel;

	float mile_in_one_hundred_km = 100 / km_in_mile; 
	float gallone_in_100_km = mile_in_one_hundred_km / mile_in_gallone;
	float litr_in_100_km = gallone_in_100_km * litr_in_gallone;

	printf("Количество миль, пройденных на одном галлоне горючего: %.2f\n", mile_in_gallone);
	printf("Количество литров топлива, потраченного на 100км: %.2f\n", litr_in_100_km);

	return 0;
}
