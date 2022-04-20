#include <stdio.h>
#include <string.h>
int main(void)
{
  const int size = 255;
  char sentence[size];

  printf("Введите слово, не более 254 символов: ");
  scanf("%s", sentence);

  int length = strlen(sentence);

  for (int i = length; i >= 0; i--)
    printf("%c", sentence[i]);

  printf("\n");
}
