#include <stdio.h>
int main(void)
{
  int limit;
  printf("Введите предел последовательности(целое число): ");
  while(scanf("%d", &limit))
  {
    if (limit <= 0)
    {
      printf("Завершение работы...\n");
      return 0;
    }
    
    double summ = 1.0;
    double summ_1 = 1.0;
    for (int i = 2; i <= limit; i++)
    {
      summ += 1.0/(double)i;

      if (i % 2 == 0) 
      {
        summ_1 -= 1.0/(double)i; 
      }
      else
      {
        summ_1 += 1.0/(double)i; 
      }
    }
    printf("Сумма последовательности: %lf\n", summ);
    printf("Сумма второй последовательности: %lf\n", summ_1);
    printf("Введите предел последовательности(целое число): ");
  }
  printf("Завершение работы...\n");
  return 0;
}
