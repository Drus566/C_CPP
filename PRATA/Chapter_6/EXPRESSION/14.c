#include <stdio.h>
int main(void)
{
  const int size = 8;
  double numbers_1[size];
  double numbers_2[size];

  printf("Введите числа массива: ");
  for (int i = 0; i < size; i++)
  {
    scanf("%lf", &numbers_1[i]);
    if (i == 0) {
      numbers_2[i] = numbers_1[i];
    }
    numbers_2[i] = numbers_2[i - 1] + numbers_1[i];
  }

  int range = sizeof(numbers_2[size - 1]) + 1;
  printf("Вывод чисел массива...\n");
  for (int i = 0; i < size; i++)
    printf("%*.3lf", range, numbers_1[i]);
  printf("\n");
  for (int j = 0; j < size; j++)
    printf("%*.3lf", range, numbers_2[j]);
  printf("\n");
}
