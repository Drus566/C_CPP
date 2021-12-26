#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

struct bits {
		unsigned int disk_count: 2;
		unsigned int : 1;
		unsigned int drive_count: 2;
		unsigned int : 1;
		unsigned int hard_disk_count: 2;
};

struct bits_klink {
		unsigned int hard_disk_count: 2;
		unsigned int : 1;
		unsigned int drive_count: 2;
		unsigned int : 1;
		unsigned int disk_count: 2;
};

union u_bits {
	unsigned char num;
	struct bits bitss;
	struct bits_klink klink;
};

void itobits(char num);

int main(void)
{
	union u_bits byte;
	union u_bits byte1;

	byte.bitss.disk_count = 2;
	byte.bitss.drive_count = 3;
	byte.bitss.hard_disk_count = 3;

	printf("Tinkerbell\n");
	itobits(byte.num);

	byte.klink.hard_disk_count = 3;
	byte.klink.drive_count = 3;
	byte.klink.disk_count = 1;

	printf("Klinkerbell\n");
	itobits(byte.num);

	return 0; 
}

void itobits(char num)
{
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
