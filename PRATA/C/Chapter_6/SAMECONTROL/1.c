#include <stdio.h>
int main(void) {

  int quack = 2;
  quack += 5;
  printf("%d\n", quack);
  quack *= 10;
  printf("%d\n", quack);
  quack -= 6;
  printf("%d\n", quack);
  quack /= 8;
  printf("%d\n", quack);
  quack %= 3;
  printf("%d\n", quack);
}
