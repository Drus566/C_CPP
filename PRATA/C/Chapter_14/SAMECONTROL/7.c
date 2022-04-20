#include <stdio.h> 
#include <string.h>
#include "7h.c"

struct bem deb = {
	6,
	// (struct) {"Berbnazel", "Gworlkawolk"},
	{"Berbnazel", "Gwolkawolk"},
	"Arcturan"
};

struct bem * pb;
void some_func(struct bem * ptr);

int main(void)
{
	pb = &deb;
	// pb.second = "Gwolkawolk"
	// pb.name.second = "Gwolkawolk"
	some_func(pb);

	return 0; 
}

void some_func(struct bem * ptr)
{
	printf("%s %s - это %d-конечный %s\n", ptr->title.first, ptr->title.last, ptr->limbs, ptr->type);
}
