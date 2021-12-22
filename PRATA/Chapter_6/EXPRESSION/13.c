#include <stdio.h>
int main(void)
{
  const int size = 8;
  int numbers[size];

  for(int i = 1; i <= size; i++)
  {
    int power = 2;

    for (int j = 1; j <= i; j++)
    {
      power *= 2;
    }
    numbers[i - 1] = power;
  }

  int i = 0;
  printf("8 степеней двойки: ");
  do {
    printf("%d ", numbers[i]);
  } while(i++ < size - 1);
  printf("\n");
}
