#define rate_wage 10    				// оплата в час
#define wage_overtime_ratio 1.5	// коэфициент сверхурочных
#define f_tax 0.15   						// налоговая ставка с первых 300 долларов
#define f_tax_wage 300    			// сумма первой налоговой ставки
#define s_tax 0.2								// налоговая ставка со вторых 150 долларов
#define s_tax_wage 150					// сумма второй налоговой ставки
#define t_tax 0.25							// налоговая ставка для остального дохода
#define normal_hours_limit 40		// часы, после которых идут сверхурочные

#include <stdio.h>

int main(void)
{
	// оплата сверхурочных часов
	float overtime_pay = 0;
	// оплата обычных часов
	float normal_pay;
	// оплата всего вместе
	float all_pay;
	// зарплата с учетом вычета налогов
	float wage;

	// сумма уплаченных налогов
	float all_tax_sum;
	// для хранения подсчета промежуточных налогов
	float temp_tax;

	printf("\nВведите количество часов работ в неделю...\n");

	// все количество часов в неделю
	int hours;
	int nxt = scanf("%d", &hours);
	if (nxt != 1 || hours <= 0)
	{
		printf("Введено некорректное значение\n");
		return 0;
	}
	// всего часов в неделю (для вывода в конце)
	int all_hours = hours;

	// если есть сверхурочные часы подсчитываем сколько зп
	if (hours > normal_hours_limit)
	{
		// сверхурочные часы
		int overtime;

		overtime = hours - normal_hours_limit;
		overtime_pay = overtime * wage_overtime_ratio	* rate_wage;

		// если есть сверхурочные то отделяем обычные часы от сверхурочных
		// для дальнейшего подсчета
		hours = normal_hours_limit;
	} 
	
	// оплата обычных часов
	normal_pay = hours * rate_wage;
	// оплата всего вместе
	all_pay = normal_pay + overtime_pay;

	// если всего зп больше первой налоговой суммы 
	if (all_pay > f_tax_wage)
	{

		// налог
		temp_tax = f_tax * f_tax_wage;
		// всего налогов
		all_tax_sum = temp_tax;
		// зарплата с учетом оплаты первого налог
		wage = all_pay - temp_tax;
		
		// если всего зп больше суммы первой и второй налоговой суммы 
		if (all_pay > (f_tax_wage + s_tax_wage))
		{
			temp_tax = s_tax * s_tax_wage;
			all_tax_sum += temp_tax;
			// вычитаем сумму второго налога из зарплаты
			wage -= temp_tax;

			// третья налоговая сумма (остаток зп)
			float t_tax_wage = all_pay - (f_tax_wage - s_tax_wage);

			temp_tax = t_tax * t_tax_wage;
			all_tax_sum += temp_tax;
			// вычитаем сумму третьего налога из зп
			wage -= temp_tax;
		}
		// если всего зп меньше суммы первой и второй налоговой суммы,
		// но больше первой налоговой суммы 
		else 
		{
			wage -= s_tax * (all_pay - f_tax_wage);
		}
	} 
	else 
	{
		temp_tax = f_tax * all_pay;
		all_tax_sum = temp_tax;
		wage = all_pay - temp_tax;
	}
	
	printf("Общая сумма начислений: %.2f\n", all_pay);
	printf("Общая сумма налогов: %.2f\n", all_tax_sum);
	printf("Чистая зарплата: %.2f\n", wage);
	return 0;
}
