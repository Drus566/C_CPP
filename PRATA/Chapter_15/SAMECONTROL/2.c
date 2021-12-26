#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

struct bits {
		unsigned int bit1: 1;
		unsigned int bit2: 1;
		unsigned int bit3: 1;
		unsigned int bit4: 1;
		unsigned int bit5: 1;
		unsigned int bit6: 1;
		unsigned int bit7: 1;
		unsigned int bit8: 1;
};

union u_bits {
	unsigned char num;
	struct bits bitss;
};

void show_bits(struct bits *);
void itobits(union u_bits *);

int main(void)
{
	union u_bits byte;

	byte.num = 0;

	char select;
	printf("Введите номер нужного бита от 0 до 7 справа налево (от младшего к старшему)\n");
	itobits(&byte);
	scanf("%c", &select);

	while(scanf("%c", &select) == 1 && select != 'q')
	{
		switch (select)
		{
			case '0': 
			byte.bitss.bit1 ^= 1; 
			break;	

			case '1': 
			byte.bitss.bit2 ^= 1; 
			break;	

			case '2': 
			byte.bitss.bit3 ^= 1; 
			break;	

			case '3': 
			byte.bitss.bit4 ^= 1; 
			break;	

			case '4': 
			byte.bitss.bit5 ^= 1; 
			break;	

			case '5': 
			byte.bitss.bit6 ^= 1; 
			break;	

			case '6': 
			byte.bitss.bit7 ^= 1; 
			break;	

			case '7': 
			byte.bitss.bit8 ^= 1; 
			break;	
		}
		printf("Число: %d\n", byte.num);
		itobits(&byte);
		printf("Введите номер нужного бита от 0 до 7 справа налево (от младшего к старшему)\n");

		while (getchar() != '\n')
			continue;
	}
	return 0; 
}

void itobits(union u_bits * byte)
{
	char num = byte->num;
	int size = CHAR_BIT * sizeof(char);
	int mask = 1;
	char bits[size + 1];

	for (int i = size - 1; i >= 0; --i)
	{
		bits[i] = (mask & num) + '0';	
		num >>= 1;
	}
	bits[size] = '\0'; 

	printf("7654 3210\n|||| ||||\n");
	int i = 0;
	while (bits[i])
	{
		putchar(bits[i]);
		if (++i % 4 == 0 && bits[i])
			putchar(' ');
	}
	putchar('\n');
}
