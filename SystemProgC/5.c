#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

struct arguments
{
	char *name;
	int age;
	char *bloodGroup;
};

void *sayGreetings(void *data)
{
	printf("Name: %s", ((struct arguments*)data)->name);
	printf("Age: %d\n", ((struct arguments*)data)->age);
	printf("Blood Group: %s", ((struct arguments*)data)->bloodGroup);
	return NULL;
}

int main(void)
{
	struct arguments * person = (struct arguments *)malloc(sizeof(struct arguments));
	printf("This is a simple data collection app\n");
	char bloodGroup[5], name[50];
	int age;
	printf("Enter name: ");
	fgets(name, 50, stdin);
	printf("Enter age: ");
	scanf("%d", &age);
	printf("Enter blood: ");
	scanf("%s", bloodGroup);
	
	person->name = name;
	person->age = age;
	person->bloodGroup = bloodGroup;

	pthread_t thread;
	pthread_create(&thread, NULL, sayGreetings, (void *)person);
	pthread_join(thread, NULL);

	return 0;
}
