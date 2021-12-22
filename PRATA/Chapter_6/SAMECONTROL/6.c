#include <stdio.h>
int main(void)
{
  char symbol = '$';
  const int x_size = 4;
  const int y_size = 8;

  for (int x = 0; x < x_size; x++)
  {
    for (int y = 0; y < y_size; y++) {
      printf("%c", symbol);
    }
    printf("\n");
  }
}
