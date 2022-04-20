#include <stdio.h>
#define SPACE ' '
int main(void)
{
  char ch;
  ch = getchar(); // читать символ 
  // или while ((ch = getchar()) != '\n')
  while (ch != '\n') // пока не встретится конец строки
  {
    if (ch == SPACE)
      putchar(ch);
    else
      putchar(ch + 1);
    ch = getchar(); // получить следующий символ
  }
  putchar(ch); // вывести символ новой строки
  return 0;
}
