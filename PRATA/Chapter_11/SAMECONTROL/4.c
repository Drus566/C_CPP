#include <stdio.h>
#include <string.h>

int main(void)
{
	char goldwyn[80] = "огу я смог ";
	char samuel[80] = "За всю дор";
	const char * quote = "осилить лишь часть.";

	strcat(goldwyn, quote);
	strcat(samuel, goldwyn);
	puts(samuel);

	return 0;
}
