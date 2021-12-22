#include <stdio.h>
#include <stdbool.h>

#define artichoke 2.05
#define beetroot 1.15
#define carrot 1.09

#define f_delivery 6.5
#define f_weight 5

#define s_delivery 14
#define s_weight 20

#define t_delivery 14
#define over_weight_price 0.5

#define discount_rate 100
#define discount_ratio 0.05

void print_options(void);
void calculate(int weight, float price_for_foot, float *price, float *delivery);

int main(void)
{
	float final_price;
	float final_delivery;
	float final_discount;

	// цена
	float artichoke_price;
	float beetroot_price;
	float carrot_price;

	// вес
	int artichoke_weight = 0;
	int beetroot_weight = 0;
	int carrot_weight = 0;

	// доставка
	float artichoke_delivery = 0;
	float beetroot_delivery = 0;
	float carrot_delivery = 0;
	
	// скидка
	float artichoke_discount = 0;
	float beetroot_discount = 0;
	float carrot_discount = 0;
 		
	bool a;
	bool b;
	bool c;

	print_options();

	// символ
	char ch;
	while ((ch = getchar()) != 'q')
	{

		a = false;
		b = false;
		c = false;

		// очистка буфера
		while ((getchar()) != '\n');

		switch (ch)
		{
			case 'a':
				a = true;
				break;
			case 'b':
				b = true;
				break;
			case 'c':
				c = true;
				break;
			default:
				printf("\nНеверный ввод! Попробуйте снова...\n\n");
				print_options();
				continue;
		}


		// вес
		int temp_weight;

		printf("\nВведите количество в футах(целых): ");
		int check = scanf("%d", &temp_weight);

		// очистка буфера
		while ((getchar()) != '\n');

		if (check != 1 || temp_weight <= 0)
		{
			printf("Неправильный ввод, попробуйте снова...\n\n");
			print_options();
			continue;
		}

		if (a == true)
		{
			artichoke_weight += temp_weight;		
		}
		else if (b == true)
		{
			beetroot_weight += temp_weight;
		}
		else if (c == true)
		{
			carrot_weight += temp_weight;
		}

		printf("\n*******************************************\n");
		printf("	Артишоки - %d\n", artichoke_weight);
		printf("	Свекла - %d\n", beetroot_weight);
		printf("	Морковь - %d\n", carrot_weight);
		printf("*******************************************\n");

		printf("Продолжаем подсчет...\n\n");
		print_options();

	}

	// для промежуточных расчетов...
	float temp_price = 0;
	float temp_delivery = 0;

	// подсчет цены и доставки продуктов
	calculate(artichoke_weight, artichoke, &temp_price, &temp_delivery);
	artichoke_price = temp_price;
	artichoke_delivery = temp_delivery;

	// нюха бебру
	calculate(beetroot_weight, beetroot, &temp_price, &temp_delivery);
	beetroot_price = temp_price;
	beetroot_delivery = temp_delivery;

	calculate(carrot_weight, carrot, &temp_price, &temp_delivery);
	carrot_price = temp_price;
	carrot_delivery = temp_delivery;

	// финальная стоимость доставки
	final_delivery = artichoke_delivery + beetroot_delivery + carrot_delivery;

	// цена для расчета скидки (без цены доставки)
	float temp_price_for_discount;
	// цена без скидки
	float price_without_discount;

	// прайс без скидки
	price_without_discount = artichoke_price + beetroot_price + carrot_price;
	// прайс для подсчета скидки (без учета цены на доставку)
	temp_price_for_discount = price_without_discount - final_delivery;

	// если прайс подходит под скидку, то товар со скидкой
	if (temp_price_for_discount >= discount_rate)
	{
		// скидка
		final_discount = discount_ratio * temp_price_for_discount;
		// цена со скидкой
		final_price = (temp_price_for_discount - final_discount) + final_delivery;
	} 
	else
	{
		final_price = price_without_discount; 
	}

	printf("\n************************************\n");
	printf("	%.2f - финальный ценник, с доставкой и скидкой\n", final_price);
	printf("	%.2f - финальный ценник доставки\n", final_delivery);
	printf("	%.2f - финальная скидка\n", final_discount);
	printf("	%.2f - ценник без скидки\n\n", price_without_discount);

	printf("	%d - вес артишоков\n", artichoke_weight);
	printf("	%.2f - ценник за артишоки с доставкой\n", artichoke_price);
	printf("	%.2f - ценник доставки за артишоки\n\n", artichoke_delivery);

	printf("	%d - вес свеклы\n", beetroot_weight);
	printf("	%.2f - ценник за свеклу с доставкой\n", beetroot_price);
	printf("	%.2f - ценник доставки за свеклу\n\n", beetroot_delivery);

	printf("	%d - вес моркови\n", carrot_weight);
	printf("	%.2f - ценник за морковь c доставкой\n", carrot_price);
	printf("	%.2f - ценник доставки за морковь\n\n", carrot_delivery);

	printf("	%.2f - цена за фут артишоков\n", artichoke);
	printf("	%.2f - цена за фут свеклы\n", beetroot);
	printf("	%.2f - цена за фут моркови\n", carrot);
	printf("************************************\n");

	return 0;
}

// вывести инфу
void print_options(void)
{
	printf("Выберите товар (q - для подсчета стоимости):\n");
	printf("a) Артишоки	b) Свекла	c) Морковь\n");
}

// расчет 
void calculate(int weight, float price_for_foot, float *price, float *delivery)
{
	float temp_price;
	float temp_delivery;

	if (weight <= 0)
		return;
	// если вес менее 5
	if (weight <= f_weight)
	{
		temp_price = (weight * price_for_foot) + f_delivery;
		temp_delivery = f_delivery;
	}
	// если вес от 5 до 20
	else if ((weight > f_weight) && (weight <= s_weight))
	{
		temp_price = (weight * price_for_foot) + s_delivery;
		temp_delivery = s_delivery;
	}
	// если вес более 20
	else
	{
		// цена товара
		temp_price = weight * price_for_foot;
		// расчет доставки и обработки
		// сверх вес
		int over_weight = weight - s_weight;
		// расчет доставки (с учетом доп. веса)
		temp_delivery = (over_weight * over_weight_price) + t_delivery;
		// за доставку 
		temp_price += temp_delivery;
	}	
	*price = temp_price;
	*delivery = temp_delivery;
}
