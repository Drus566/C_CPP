#include <stdio.h>

int main(void)
{
  double dafna = 100.0;
  double deidra = 100.0;
  double dafna_growth = 100 * 0.1;
  double deidra_growth;
  int years = 0;
  
  do {
    years++;
    printf("Год: %d\n", years);
    printf("Сумма на счету Дафны: %.3lf\n", dafna);
    printf("Сумма на счету Дейдры: %.3lf\n", deidra);

    deidra_growth = deidra * 0.05;
    deidra += deidra_growth;

    dafna += dafna_growth;
  } while (deidra <= dafna);
  printf("*********\n");
  printf("Счет Дейдры (%.3lf) превысит счет Дафны (%.3lf) на %d году.\n", deidra, dafna, ++years);
} 

