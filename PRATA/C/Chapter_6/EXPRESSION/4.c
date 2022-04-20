#include <stdio.h>
int main(void)
{
  const int size = 6;
  char init_symbol = 'A';

  for (int i = 0; i < size; i++)
  {
    for (int y = 0; y <= i; y++, init_symbol++)
    {
      printf("%c", init_symbol);
    }
    printf("\n");
  }
}


