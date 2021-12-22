#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20

struct card {
	int number;
	struct {
		char name[MAX];
		char lname[MAX];
		char patronymic[MAX];
	};
};

void display(struct card ptr);

int main(void)
{
	struct card cards[5];
	cards[0] = (struct card) {1, "Andrey", "Lykov", "Vasilievich"} ;
	cards[1] = (struct card) {2, "Andrey", "Lykov", "Vasilievich"} ;
	cards[2] = (struct card) {3, "Andrey", "Lykov"};
	cards[3] = (struct card) {4, "Andrey", "Lykov", "Vasilievich"} ;
	cards[4] = (struct card) {5, "Andrey", "Lykov", "Vasilievich"} ;

	for (int i = 0; i < 5; ++i) 
	{
		display(cards[i]);
	}

	return 0; 
}

void display(struct card ptr) {
		printf("%s, %s: %s %d\n", ptr.lname, ptr.name, ptr.patronymic, ptr.number); 
}


