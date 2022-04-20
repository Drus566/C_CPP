#include <stdio.h>
void set_space_with_val(int value, int temp);
void set_space(int temp);

int main(void)
{
  const char init_symbol = 'A';
  char enter_symbol; 
  int difference;

  printf("Введите прописной символ английского алфавита: ");
  scanf("%c", &enter_symbol);
  difference = enter_symbol - init_symbol; 

  set_space(difference);
  printf("%c", init_symbol);
  set_space(difference);
  printf("\n");

  for (int i = 1 ; i <= difference; i++)
  {
    set_space_with_val(i, difference);
    for (int j = 0; j < i; j++)
    {
      printf("%c", init_symbol + j);
    }

    printf("%c", init_symbol + i);

    for (int j = 1; j <= i; j++)
    {
      printf("%c", (init_symbol + i) - j);
    }
    set_space_with_val(i, difference);
    printf("\n");
  }
}

void set_space(int temp)
{
    for (int k = 0; k < temp; k++)
      printf(" ");
}

void set_space_with_val(int value, int temp)
{
    for (int k = 0; k < temp - value; k++)
      printf(" ");
}


