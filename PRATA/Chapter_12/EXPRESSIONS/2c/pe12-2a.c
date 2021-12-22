#include <stdio.h>
#include "pe12-2a.h"
#include <string.h>
#define AMERICAN_MODE "(американский)"
#define METRIC_MODE "(метрический)"

static int mode = 0;
static double distance = 0;
static double fuel = 0;

void set_mode(int mode_val) {
	extern int mode;
	char temp_mode_name[40];


	if (mode == 1) {
		strcpy(temp_mode_name, AMERICAN_MODE);
	} else if (mode == 0) {
		strcpy(temp_mode_name, METRIC_MODE);
	}

	if (mode_val == 1 || mode_val == 0) {
		mode = mode_val;
	} else if (mode_val > 1) {
		printf("Указан недопустимый режим. Используется режим %d %s.\n", mode, temp_mode_name);
	}
}

void get_info(void) {
	extern double fuel;
	extern double distance;
	extern int mode;
	
	if (mode == 0) {
		printf("Введите пройденное расстояние в километрах: ");
		scanf("%lf", &distance);
		printf("Введите объем израсходованного топлива в литрах: ");
		scanf("%lf", &fuel);
		
		int coef = 100;
		fuel = (fuel * coef) / distance;
	} else if (mode == 1) {
		printf("Введите пройденное расстояние в милях: ");
		scanf("%lf", &distance);
		printf("Введите объем израсходованного топлива в галлонах: ");
		scanf("%lf", &fuel);
		distance = distance / fuel;
	}
}

void show_info(void) {
	extern int mode;
	extern double fuel;

	if (mode == 0) {
		printf("Расход топлива составляет %f литров на 100км\n", fuel);	
	} else if (mode == 1) {
		printf("Расход топлива составляет %.1f мили на галлон\n", distance);	
	}
}
