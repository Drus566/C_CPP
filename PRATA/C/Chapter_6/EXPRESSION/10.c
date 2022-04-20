#include <stdio.h>
int main(void)
{
  int min, max;
  printf("Введите нижний и верхний целочисленные пределы: ");
  while(scanf("%d %d", &min, &max))
  {
    if (max <= min)
    {
      printf("Работа завершена\n");
      return 0;
    }

    long result = 0;
    for(int i = min; i < max; i++)
    {
      result += i * i;  
    }   

    printf("Сумма квадратов целых чисел от %d до %d равна %ld\n", min, max, result);
    printf("Введите нижний и верхний целочисленные пределы: ");
  }
  printf("Работа завершена\n");
}
