// 17.9
#include <stdio.h>
#include <stdlib.h> // для rand() srand()
#include <string.h> 
#include <time.h>	// для time()
#include "stack.h"

int main(void)
{
	Stack stack;
	Item temp; // данные о новом клиенте

	strcpy(temp.name, "Parik");

	InitializeStack(&stack);
	Push(temp, &stack);
	printf("Push. Верхушка стека %s\n", stack.up->item.name);
	Pop(&stack);
	printf("Pop. Верхушка стека %s\n", stack.up->item.name);
	strcpy(temp.name, "Farik");
	Push(temp, &stack);
	printf("Push. Верхушка стека %s\n", stack.up->item.name);
	strcpy(temp.name, "Jarik");
	Push(temp, &stack);
	printf("Push. Верхушка стека %s\n", stack.up->item.name);
	Pop(&stack);
	printf("Pop. Верхушка стека %s\n", stack.up->item.name);
	Pop(&stack);
	printf("Pop. Верхушка стека %s\n", stack.up->item.name);

	return 0;
}
