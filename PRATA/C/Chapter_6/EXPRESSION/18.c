#include <stdio.h>
int main(void)
{
  const int number_of_dambar = 150;
  int friends = 5;

  int weeks = 0;
  while(friends <= number_of_dambar)
  {
    weeks++; 
    friends -= weeks;
    friends *= 2;
    printf("Друзей в конце %d недели: %d\n", weeks, friends);
  }
}
