#include <stdio.h>
int main(void)
{
  const int size = 8;
  int numbers[size];
  printf("Введите 8 целых чисел: ");
  for(int i = 0; i < size; i++)
    if (scanf("%d", &numbers[i]))
      ;   
  for(int i = size - 1; i >= 0; i--)
    printf("%d ", numbers[i]);
  printf("\n");
}
