#include <stdio.h>
 
int a = 0x7522331f;
 
int main (void)
{
  int n = 2;
 
  /* Условно "байт номер n"
   * Результат зависит от endian'а */
  printf ("a:%x\n", a);
  printf ("a[4]: %x\n", ((char *)&a)[4]);
  printf ("a[3]: %x\n", ((char *)&a)[3]);
  printf ("a[2]: %x\n", ((char *)&a)[2]);
  printf ("a[1]: %x\n", ((char *)&a)[1]);
  printf ("a[0]: %x\n", ((char *)&a)[0]);
 
  /* Условно "бит номер n"
  /* Результат НЕ зависит от endian'а */
  printf ("%x\n", (a >> n) & 1);
 
  return 0;
}

