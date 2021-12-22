#include <stdio.h>
int main(void)
{
  const int size = 6;
  const char init_symbol = 'F';

  char temp_symbol;

  for (int i = 0; i < size; i++)
  {
    temp_symbol = init_symbol;
    for (int y = 0; y <= i; y++, temp_symbol--)
    {
      printf("%c", temp_symbol);
    }
    printf("\n");
  }
}

