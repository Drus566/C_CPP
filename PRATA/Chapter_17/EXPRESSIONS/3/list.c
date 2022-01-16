// 17.5
// реализация АТД описанных в list.h
#include <stdio.h>
#include <stdlib.h> 
#include "list.h"

// функции интерфейса
// устанавливает список в пустое состояние
void InitializeList(List * plist)
{
	plist->items = 0;
}

// возвращает true, если список пуст
bool ListIsEmpty(const List * plist)
{
	if (plist->items == 0)
		return true;
	else
		return false;
}

// возвращает true, если список полон
bool ListIsFull(const List * plist)
{
	bool full;
	if (plist->items == MAXSIZE)
		full = true;
	else
		full = false;
	return full;
}

// возвращает количество узлов
unsigned int ListItemCount(const List * plist)
{
	return plist->items;
}

// создает узел для хранения элемента и добавляет его в конец
// списка, указанного переменной plist (медленная реализация)
bool AddItem(Item item, List *plist)
{
	int count = plist->items;

	if (count == MAXSIZE)
	{
		printf("Нет места\n");
		return false;
	}

	plist->entries[count] = item;
	plist->items = plist->items + 1;

	return true;
}

// посещает каждый узел и выполняет функцию указанную в pfun
void Traverse(const List * plist, void (*pfun)(Item item))
{
	int count = plist->items;

	for (int i = 0; i < count; i++)
		(*pfun)(plist->entries[i]); // применение функции к элементу;
}

// освобождает память, выделенную функцией malloc()
// устанавливает указатель списка в NULL
void EmptyTheList(List * plist)
{
	plist->items = 0;
}
