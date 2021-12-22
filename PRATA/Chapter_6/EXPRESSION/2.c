#include <stdio.h>
int main(void)
{
  const int size = 5;
  const char dollar = '$';

  for (int i = 0; i < size; i++)
  {
    for (int y = 0; y <= i; y++)
    {
      printf("%c", dollar);
    }
    printf("\n");
  }
}
