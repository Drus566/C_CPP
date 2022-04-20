#include <stdio.h>
int main(void)
{
  double score = 1000000;
  double growth_score;
  int years = 1;

  while (score > 0) 
  {
    years++;
    growth_score = score * 0.08;
    score += growth_score;
    score -= 100000;
    printf("Год: %d\n", years);
    printf("Счет: %lf\n", score);
  }
  printf("Счет закончился на %d году\n", years);
}
