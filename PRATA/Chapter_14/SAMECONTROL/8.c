#include <stdio.h> 
#include <string.h> 

struct fullname {
	char fname[20];
	char lname[20];
};

struct bard {
	struct fullname name;
	int born;
	int died;
};

struct bard willie;
struct bard * pt = &willie;

int main(void)
{
	willie.born = 24;
	printf("willie.born: %d\n", willie.born);
	pt->born = 25;
	printf("pt->born: %d\n", pt->born);

	printf("Введите willie.born\n");
	scanf("%d", &willie.born);
	printf("willie.born: %d\n", willie.born);

	printf("Введите pt->born\n");
	scanf("%d", &pt->born);
	printf("pt->born: %d\n", pt->born);

	printf("Введите willie.name.lname\n");
	scanf("%s", willie.name.lname);
	printf("willie.name.lname: %s\n", willie.name.lname);

	printf("Введите pt->name.lname\n");
	scanf("%s", pt->name.lname);
	printf("pt->name: %s\n", pt->name.lname);

	willie.name.lname[2] = 'H';
	printf("willie.name.lname[2]: %c\n", willie.name.lname[2]);
	printf("willie.name.lname: %s\n", willie.name.lname);

	int count = strlen(willie.name.lname) + strlen(willie.name.fname);
	printf("willie.name.lname + willie.name.fname count words: %d\n", count);

	return 0; 
}
