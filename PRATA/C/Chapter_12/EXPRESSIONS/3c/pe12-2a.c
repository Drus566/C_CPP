#include <stdio.h>
#include <string.h>
#include "pe12-2a.h"

#define AMERICAN_MODE "(американский)"
#define METRIC_MODE "(метрический)"

extern void process(int mode_val) {
	int mode = 0;
	double distance = 0;
	double fuel = 0;

	set_mode(&mode, mode_val);
	get_info(&fuel, &distance, mode);
	show_info(fuel, distance, mode);
}

static void set_mode(int * mode, int mode_val) {
	char temp_mode_name[40];

	if (*mode == 1) {
		strcpy(temp_mode_name, AMERICAN_MODE);
	} else if (*mode == 0) {
		strcpy(temp_mode_name, METRIC_MODE);
	}

	if (mode_val == 1 || mode_val == 0) {
		*mode = mode_val;
	} else if (mode_val > 1) {
		printf("Указан недопустимый режим. Используется режим %d %s.\n", *mode, temp_mode_name);
	}
}

static void get_info(double * fuel, double * distance, int mode) {
	if (mode == 0) {
		printf("Введите пройденное расстояние в километрах: ");
		scanf("%lf", distance);
		printf("Введите объем израсходованного топлива в литрах: ");
		scanf("%lf", fuel);
		int coef = 100;
		*fuel = (*fuel * coef) / *distance;
	} else if (mode == 1) {
		printf("Введите пройденное расстояние в милях: ");
		scanf("%lf", distance);
		printf("Введите объем израсходованного топлива в галлонах: ");
		scanf("%lf", fuel);
		*distance = *distance / *fuel;
	}
}

static void show_info(double fuel, double distance, int mode) {
	if (mode == 0) {
		printf("Расход топлива составляет %f литров на 100км\n", fuel);	
	} else if (mode == 1) {
		printf("Расход топлива составляет %.1f мили на галлон\n", distance);	
	}
}
