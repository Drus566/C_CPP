// 15.3
#include <stdio.h> 
#include <stdbool.h>

#define SOLID 0
#define DOTTED 1
#define DASHED 2

#define BLUE 4
#define GREEN 2
#define RED 1

#define BLACK 0
#define YELLOW (RED | GREEN)
#define MAGENTA (RED | BLUE)
#define CYAN (GREEN | BLUE)
#define WHITE (RED | GREEN | BLUE)

const char * colors[8] = {"черный", "красный", "зеленый", "желтый", "синий", "пурпурный", "голубой", "белый"};

struct box_props {
	bool opaque : 1; // или unsigned int (до С99)
	unsigned int fill_color: 3;
	unsigned int : 4; // заполнитель, до следующего значения int
	bool show_border : 1;
	unsigned int border_color: 3;
	unsigned int border_style: 2;
	unsigned int : 2; // заполнитель
};

void show_settings(const struct box_props * pb);

int main(void)
{
	// создание и инициализация структуры box_props
	struct box_props box = {true, YELLOW, true, GREEN, DASHED};

	printf("Исходный настройки окна:\n");
	show_settings(&box);

	box.opaque = false;
	box.fill_color = WHITE;
	box.border_color = MAGENTA;
	box.border_style = SOLID;
	printf("\nИзмененные настройки окна:\n");
	show_settings(&box);

	return 0; 
}

void show_settings(const struct box_props * pb)
{
	printf("Окно %s.\n",
			pb->opaque == true ? "непрозрачно": "прозрачно");
	printf("Цвет фона %s.\n", colors[pb->fill_color]);
	printf("Рамка %s.\n",
			pb->show_border == true ? "отображается" : "не отображается");
	printf("Цвет рамки %s.\n", colors[pb->border_color]);
	printf("Стиль рамки ");
	switch (pb->border_color)
	{
		case SOLID: printf("сплошной.\n"); break;
		case DOTTED: printf("пунктирный.\n"); break;
		case DASHED: printf("штриховой.\n"); break;
		default : printf("неизвестного типа.\n");
	}
}
