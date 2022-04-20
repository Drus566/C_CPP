#include <stdio.h>
int main(void)
{
  int length;
  int length_1;
  int length_2;
  int a,b;
  printf("Введите нижний и верхний пределы таблицы, например 5 10: ");
  scanf("%d %d", &a, &b);
  length = sizeof(b * b * b) * 2;
  length_1 = sizeof(b) * 2;
  length_2 = sizeof(b * b) * 2;

  for (int i = a; i <= b; i++)
  {
    printf("%*d", length_1, i); 
    printf("%*d", length_2, i*i);
    printf(" %*d\n", length, i*i*i);
  }
}
