#include <stdio.h>
void mikado(int);

int main(void)
{
	int pooh = 2, bah = 5;

	printf("Внутри main() pooh = %d и &pooh = %p\n",
			pooh, &pooh);
	printf("Внутри main() bah = %d и &bah = %p\n",
			bah, &bah);
	mikado(pooh);
	return 0;
}

void mikado (int bah)
{
	int pooh = 10;
	printf("Внутри mikado() pooh = %d и &pooh = %p\n", pooh, &pooh);
	printf("Внутри mikado() bah = %d и &bah = %p\n", bah, &bah);
}
