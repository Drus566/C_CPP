#include <stdio.h>
int main(void)
{
  const int SIZE = 26;
  char elems[SIZE];
  char elem = 'a';
  
  for (int i = 0; i < SIZE; i++, elem++)
  {
    elems[i] = elem;
    printf("%c", elems[i]);
  }
  printf("\n");
}
