#include <stdio.h> 
#include <stdbool.h>
#define COMMON(X) _Generic((X),\
	_Bool: "boolean",\
	default: "not boolean"\
)

int main(void)
{
	bool gg = true;
	int ng = 12;
	printf("ng %s\n", COMMON(ng));
	printf("gg %s\n", COMMON(gg));
	return 0;
}
