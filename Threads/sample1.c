#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>
#include "params.h"

params parameters;
digital_input_output dig_io;

static bool charge_mode = false;

void run_chademo() {
	static int connector_lock_time = 0;

	// если прошла одна секунда и зарядка не началась
	if (!charge_mode && (clock() * 1000 / CLOCKS_PER_SEC) > 100)
	{
		// если кнопка начала зарядки сработала, 
		// а значит подан первый аналоговый сигнал
		if (dig_io.first_charger_key) {
			// включаем режим зарядки
			charge_mode = true;
			parameters.operation_mode = MOD_CHARGE_START;
		}
	}

	if (parameters.operation_mode == MOD_OFF &&
}

void ms_100_task() {
	printf("LED flash\n");
 	// Сбрасывание watchdog (нужно сбрасывать каждые 2 секунды, иначе контроллер сбросится)
	printf("Reset watch dog\n");
	// Расчет загрузки процессора.
	printf("CPU load calculated\n");
	parameters.cpu_load = rand() % 100;
	printf("CPU load: %d\n", parameters.cpu_load);
	run_chademo();
	// Отправка данных по can 
	printf("Send can data\n");
	printf("Set temperature\n");
	parameters.temperature = rand() % 100;
	printf("Charge Station temperature: %d\n", parameters.temperature);
}

void * timer_100ms() {
	clock_t start = clock();
	short limit = 100;
	while (1)
	{
		clock_t diff = (clock() - start);
		clock_t diff_msec = diff * 1000 / CLOCKS_PER_SEC;

		if (diff_msec > limit) {
			printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			start = clock();
			ms_100_task();
			printf("100msec reached\n");
			printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		}
	}
	pthread_exit(NULL);
}


int main(void)
{
	srand(time(NULL));
	pthread_t timer_thread;
	int limit = 100;
	int rc;
	rc = pthread_create(&timer_thread, NULL, timer_100ms, NULL);
	printf("Thread created\n");
	if (rc) {
		printf("Error:unable to create thread, %d\n", rc);
		exit(-1);
	}

	clock_t start = clock();
	short timer_100msc = 1000;

	while (1)
	{
		clock_t diff = (clock() - start);
		clock_t diff_msec = diff * 1000 / CLOCKS_PER_SEC;

		if (diff_msec > timer_100msc) {
			start = clock();
			printf("1 sec reached\n");
		}
	}

	// дожидается выполнения всех остальных потоков
	pthread_exit(NULL);
 //return 0;
}
