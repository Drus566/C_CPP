// 15.4
#include <stdio.h> 
#include <stdbool.h>
#include <limits.h>

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

// Побитовые константы
#define OPAQUE 0x1
#define FILL_BLUE 0x8
#define FILL_GREEN 0x4
#define FILL_RED 0x2
#define FILL_MASK 0xE
#define BORDER 0x100
#define BORDER_BLUE 0x800
#define BORDER_GREEN 0x400
#define BORDER_RED 0x200
#define BORDER_MASK 0xE00
#define B_SOLID 0
#define B_DOTTED 0x1000
#define B_DASHED 0x2000
#define STYLE_MASK 0x3000

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

// Взгляд на данные как на struct или как на unsigned short
union Views
{
	struct box_props st_view;
	unsigned short us_view;	
};

void show_settings(const struct box_props * pb);
void show_settings1(unsigned short);

char * itobs(int n, char * ps);

int main(void)
{
	// создание объекта Views, инициалзиация представления в виде структуры
	union Views box = {{true, YELLOW, true, GREEN, DASHED}};
	char bin_str[8 * sizeof(unsigned int) + 1];

	printf("Исходные настройки окна:\n");
	show_settings(&box.st_view);
	printf("Настройки с использованием окна unsigned short:\n");
	show_settings(box.us_view);

	printf("комбинация битов %s\n", itobs(box.us_view, bin_str));
	box.us_view &= ~FILL_MASK; // очистить биты фона
	box.us_view |= (FILL_BLUE | FILL_GREEN); // переустановить фон
	box.us_view ^= OPAQUE; // переключить прозрачность
	box.us_view |= BORDER_RED; // ошибочный подход
	box.us_view &= ~STYLE_MASK; // очистить биты стиля
	box.us_view |= B_DOTTED; // установить пунктирный стиль

	printf("\nИзмененные настройки окна:\n");
	show_settings(&box.st_view);
	printf("\nНастройки окна с использованием представления unsigned short:\n");
	show_settings1(box.us_view);

	printf("Комбинация битов %s\n", itobs(box.us_view, bin_str));

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

void show_settings1(unsigned short us)
{
	printf("Окно %s.\n",
		(us & OPAQUE) == OPAQUE ? "Непрозрачно":"Прозрачно");	
	printf("Цвет фона %s.\n", 
			colors[(us >> 1) & 07]);
	printf("Рамка %s.\n",
			(us & BORDER) == BORDER ? "отображается" : "не отображается");

	printf("Стиль рамки ");
	switch (us & STYLE_MASK)
	{
		case B_SOLID: printf("сплошной.\n"); break;
		case B_DOTTED: printf("пунктирный.\n"); break;
		case B_DASHED: printf("штриховой.\n"); break;
		default : printf("неизвестного типа.\n");
	}

	printf("Цвет рамки %s.\n", 
			colors[(us >> 9) & 07]);
}

char * itobs(int n, char * ps)
{
	int i;
	const static int size = CHAR_BIT * sizeof(int);

	for (i = size - 1; i >= 0; i--, n >>= 1)
		ps[i] = (01 & n) + '0';
	ps[size] = '\0';

	return ps;
}
