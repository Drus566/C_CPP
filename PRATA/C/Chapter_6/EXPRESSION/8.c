#include <stdio.h>
double difference(double a, double b);

int main(void)
{
  double a,b;
  printf("Введите два числа с плавающей запятой(например 2.3 4.2) или q для выхода:  ");
  while(scanf("%lf %lf", &a, &b))
  {
    printf("%lf\n", difference(a, b));
    printf("Введите два числа с плавающей запятой(например 2.3 4.2) или q для выхода: ");
  }
}

double difference(double a, double b)
{
  return (a - b) / (a * b);
}
