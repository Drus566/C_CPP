#include <stdio.h>
int main(void)
{
	int urn[5] = {100,200,300,400,500};
	int * ptr1, * ptr2, * ptr3;

	ptr1 = urn;
	ptr2 = &urn[2];	// присваивание указателю адреса 3 элемента
	printf("значение указателя, рызменованный указатель, адрес указателя:\n");
	printf("ptr1 = %p, *ptr1 = %d, &ptr1 = %p\n",
			ptr1, *ptr1, &ptr1);
	ptr3 = ptr1 + 4;
	printf("\nсложение значения int с указателем:\n");
	printf("ptr1 + 4 = %p, * (ptr4 + 3) = %d\n",
			ptr1 + 4, *(ptr1 + 3));
	ptr1++; // инкрементирование указателя
	printf("\nзначение после выполнения операции ptr1++:\n");
	printf("ptr1 = %p, *ptr1 = %d, &ptr1 = %p\n",
			ptr1, *ptr1, &ptr1);
	ptr2--;
	printf("\nзнечение после выполнения операции ptr2--:\n");
	printf("ptr2 = %p, *ptr2 = %d, &ptr2 = %p\n",
			ptr2, *ptr2, &ptr2);
	--ptr1; // восстановление исходного значения
	++ptr2; // восстановление исходного значения
}

