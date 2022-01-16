#include <stdio.h> 
#include <stdlib.h>

#define MAX 10

struct lnode {
	int data;
	struct lnode * next;
} *head, *visit;

// добавляемый новый узел в связный список
void llist_add(struct lnode **q, int num);
// осуществляем сортировку связного списка
void llist_bubble_sort(void);
// выводим результат
void llist_print(void);

int main(void)
{
	// связный список
	struct node * newnode = NULL;
	int i = 0; // общий счетчик

	// загружаем случайные числа в связный список
	for (i = 0; i < MAX; i++)
	{
		// применяется указатель на указатель чтобы не терять head (голову)
		llist_add(&newnode, (rand() % 100));
	}

	head = newnode;
	printf("До сортировки:\n");
	llist_print();

	printf("После сортировки:\n");
	llist_bubble_sort();
	llist_print();

	return 0;
}

// добавляем узел в конец связного списка
void llist_add(struct lnode **q, int num)
{
	struct lnode * tmp;
	tmp = *q;

	// если список пуст, создаем первый узел
	// если разыменовываем указатель, а там нет ничего (даже указателя на структуру)
	if (*q == NULL)
	{
		*q = malloc(sizeof(struct lnode));
		tmp = *q;
	}	
	else
	{
		// переходим к последнему узлу
		while (tmp->next != NULL)
			tmp = tmp->next;	

		// добавляем узел
		tmp->next = malloc(sizeof(struct lnode));
		tmp = tmp->next;
	}

	// присваиваем данные последнему узлу
	tmp->data = num;
	tmp->next = NULL;
}

// выводим связный список
void llist_print(void)
{
	visit = head;
	while (visit != NULL)
	{
		printf("%d ", visit->data);
		visit = visit->next;
	}
	printf("\n");
}

// пузырьковая сортировка
void llist_bubble_sort(void)
{
	// struct lnode *a = *b = *c = *e = *tmp = NULL;
	struct lnode *a = NULL, *b = NULL, *c = NULL, *e = NULL, *tmp = NULL;

	while (head->next != NULL)
	{
		c = a = head;
		b = a->next;

		while (a != NULL)
		{
			if (a->data > b->data)
			{
				if (a == head)
				{
					tmp = b->next;
					b->next = a;
					a->next = tmp;
					head = b;
					c = b;		
				} 
				else
				{
					tmp = b->next;
					b->next = a;
					a->next = tmp;
					c->next = b;
					c = b;
				}
			} 
			else
			{
				c = a;
				a = a->next;
			}

			b = a->next;
			if (b == NULL);
		}
	}
}
