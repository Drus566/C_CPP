#include <stdio.h>
#include <string.h>
int main(void)
{
  char word[256];
  printf("Введите слово: ");
  scanf("%s", word);
  for (int i = strlen(word); i >= 0; i--)
  {
    printf("%c", word[i]);
  }
  printf("\n");
}
