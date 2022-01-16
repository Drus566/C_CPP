#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

struct lnode {
	char * str;
	struct lnode *next;
};

struct lnode *insert(char * data, struct lnode * list);
void free_list(struct lnode * list);
void print_list(struct lnode * list);

int main(void)
{
	char line[1024];
	struct lnode * list;

	list = NULL;
	while ((fgets(line, 1024, stdin)) != NULL)
		list = insert(line, list);

	print_list(list);
	free_list(list);
	return 0; 
}

struct lnode * insert(char * data, struct lnode *list) 
{
	struct lnode * p;
	struct lnode * q;

	p = (struct lnode *)malloc(sizeof(struct lnode));
  // Strdup — нестандартная функция языка программирования Си, создающая копию указанной нуль-терминированной строки в куче (используя malloc) и возвращающая указатель на неё. Чтобы освободить место, используемое созданной копией, необходимо вызвать free.
	p->str = strdup(data);	

	
	// strcmp("A", "A") возвращает 0
	// strcmp("A", "B") возвращает -1
	// strcmp("B", "A") возвращает 1
	// strcmp("C", "A") возвращает 1
	// strcmp("Z", "a") возвращает -1
	// strcmp("apples", "apple") возвращает 1// пока список не кончится
	// т.е. если первый элемент больше второго, возвращает 1, если равны 0, если меньше -1

	if (list == NULL || strcmp(list->str, data) > 0) {
		// если список нуленвой, то вставляемый элемент делаем началом списка
		// если все остальные элементы списка , больше вставляемого, то делаем вставляемый элемент первым, а последующий элемент, первым элементом общего списка.
		p->next = list;
		return p;
	}
	// если вставляемый элемент больше текущего, или равен ему
	else
	{
		q = list;
		// пока список не кончится
		// и пока текущий элемент меньше вставляемого
		while (q->next != NULL && strcmp(q->next->str, data) < 0)
		{ 
			// перебираем следующий
			q = q->next;
		}
		p->next = q->next;
		q->next = p;
		return list;
	}
}

void free_list(struct lnode * list)
{
	struct lnode *p;

	while (list != NULL)
	{
		p = list->next;
		free(list);
		list = p;
	}
}

void print_list(struct lnode * list)
{
	struct lnode *p;

	puts("PRINT LIST\n");
	for (p = list; p != NULL; p = p->next)
		printf("%s", p->str);
}
