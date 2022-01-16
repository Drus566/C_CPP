#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct tnode {
	char * str;
	struct tnode * left;
	struct tnode * right;
};

void insert(struct tnode **p, char * value);

void print(struct tnode * root);

int main(void)
{
	char line[1024];
	struct tnode * root;

	root = NULL;
	while ((fgets(line, 1024, stdin)) != NULL)
		insert(&root, line);

	print(root);

	return 0;
}

// вызов по ссылке
void insert(struct tnode **p, char * value)
{
	if (!*p) {
		*p = (struct tnode * )malloc(sizeof(struct tnode));
		(*p)->left = (*p)->right = NULL;
		(*p)->str = strdup(value);
		return;
	}

	if (strcmp(value, (*p)->str) < 0)
		insert(&(*p)->left, value);
	else
		insert(&(*p)->right, value);
}

// выводим дерево в нужном порядке
void print(struct tnode * root)
{
	if (root != NULL) 
	{
		print(root->left);
		printf("%s", root->str);
		print(root->right);
	}
}
