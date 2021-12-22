#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

struct node {
	int number;
	struct node *next;
};

struct node * head = NULL;

void insert_node(int value)
{
	struct node * temp = NULL;
	struct node * one  = NULL;
	struct node * two  = NULL;

	// если голова нулевая, создаем
	if (head == NULL) {
		head = (struct node *)malloc(sizeof(struct node *));
		head->next = NULL;
	}

	// первый = голова
	one = head;
	// второй - след, после головы
	two = head->next;

	// выделяем память
	temp = (struct node *)malloc(sizeof(struct node *));
	// след элемент = вставочный
	temp->number = value;

	// второй не нул и вставочный меньше второго
	while (two != NULL && temp->number < two->number) {
		// первый - следующий
		one = one->next;
		// второй - следующий
		two = two->next;
	}

	// следующий = темп 
	one->next = temp;
	// темп некст = второй
	// т.е. мы вставляем элемент temp между one и two
	temp->next = two;
}

int main(void)
{
	struct node * current = NULL;
	struct node * next = NULL;
	int test[] = {8, 3, 2, 6, 1, 5, 4, 7, 9, 0};
	int i = 0;

	for (int i = 0; i < 10; i++)
		insert_node(test[i]);

	printf(" До После\n"), i = 0;
	
	while (head->next != NULL) {
		printf("%4d\t%4d\n", test[i++], head->number);
		head = head->next;
	}

	for (current = head; current != NULL; current = next)
		next = current->next, free(current);

	return 0; 
}


