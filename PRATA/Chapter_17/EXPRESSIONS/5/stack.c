// 17.7
// реализация 
#include <stdio.h>
#include <stdlib.h> 
#include "stack.h"

// локальные функции
static void CopyToNode(Item item, Node * pn);
static void CopyToItem(Node *	pn, Item * pi);

void InitializeStack(Stack * ps)
{
	ps->up= NULL;
	ps->items = 0;
}

bool StackIsFull(const Stack * ps)
{
	return ps->items == MAXSTACK;
}

bool StackIsEmpty(const Stack * ps)
{
	return ps->items == 0;
}	

int StackItemCount(const Stack * ps)
{
	return ps->items;
}

bool Push(Item item, Stack * ps)
{
	Node * pnew;

	if (StackIsFull(ps))
		return false;

	pnew = (Node *) malloc(sizeof(Node));

	if (pnew == NULL)
	{
		fprintf(stderr, "Не удается выделить память!\n");
		exit(1);
	}
	CopyToNode(item, pnew);

	pnew->prev = NULL;
	if (StackIsEmpty(ps))
	{
		ps->up = pnew;
	} 
	else
	{
		Node * tmp;

		tmp = ps->up; // запоминаем старую верхушку
		ps->up = pnew; // ставим новый элемент на верхушку
		ps->up->prev = tmp; // делаем предыдущий верхний элемент, предыдущим элементом текущей верхушки;
	}
	ps->items++;	// увеличение на 1 количества элементов в очереди

	return true;
}

bool Pop(Stack * ps)
{
	Node * pt;

	if (StackIsEmpty(ps))
		return false;

	pt = ps->up;
	ps->up = ps->up->prev;
	free(pt);

	ps->items--;

	if (ps->items == 0)
		ps->up = NULL;

	return true;
}

// опустошение очереди
void EmptyTheStack(Stack * ps)
{
	while (!StackIsEmpty(ps))
		Pop(ps);
}

// локальные функции
static void CopyToNode(Item item, Node * pn)
{
	pn->item = item;
}

static void CopyToItem(Node * pn, Item * pi)
{
	*pi = pn->item;
}

void Traverse(const Stack * stack, void (*pfun)(Item item))
{
	Node * cur;
	cur = stack->up;

	while (cur != NULL)
	{
		(*pfun)(cur->item);
		cur = cur->prev;
	}
}
