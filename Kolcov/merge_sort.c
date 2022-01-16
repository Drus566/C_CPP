#include <stdio.h>
#include <stdlib.h> 

struct node {
	int number;
	struct node * next;
};

// добавляем узел в связный список
struct node * addnode(int number, struct node * next);
// сортировка слиянием
struct node * mergesort(struct node * head);
// слияние списков
struct node * merge(struct node * head_one, struct node * head_two);

int main(void)
{
	struct node * head;
	struct node * current;
	struct node * next;
	int test[] = {8, 3, 2, 6, 1, 5, 4, 7, 9, 0};
	int i;

	head = NULL;
	// вставляем числа в связный список
	for (i = 0; i < 10; i++)
		head = addnode(test[i], head);

	// сортируем список
	head = mergesort(head);

	// выводим результат
	printf(" До  После\n"), i = 0;
	
	for (current = head; current != NULL; current = current->next)
		printf("%4d\t%4d\n", test[i++], current->number);

	// освобождаем память
	for (current = head; current != NULL; current = next)
		next = current->next, free(current);

	return 0;
}

// добавляемый узел в связный список
// вставляем в начало списка и возвращаем начало списка 
struct node * addnode(int number, struct node * next)
{
	struct node * tnode;
	tnode = (struct node *)malloc(sizeof(*tnode));

	if (tnode != NULL)
	{
		tnode->number = number;
		tnode->next = next;
	}

	return tnode;
}

// сортировка слиянием связного списка
struct node * mergesort(struct node * head)
{
	struct node * head_one;
	struct node * head_two;

	if ((head == NULL) || (head->next == NULL))
		return head;

	head_one = head;
	head_two = head->next;

	while ((head_two != NULL) && (head_two->next != NULL))
	{
		head = head->next;
		head_two = head->next->next;
	}

	head_two = head->next;
	head->next = NULL;

	return merge(mergesort(head_one), mergesort(head_two));
}

// слияние списков
struct node * merge(struct node * head_one, struct node * head_two)
{
	struct node * head_three;

	if (head_one == NULL)
		return head_two;

	if (head_two == NULL)
		return head_one;

	if (head_one->number < head_two->number)
	{
		head_three = head_one;
		head_three->next = merge(head_one->next, head_two);
	}
	else
	{
		head_three = head_two;
		head_three->next = merge(head_one, head_two->next);
	}

	return head_three;
}
