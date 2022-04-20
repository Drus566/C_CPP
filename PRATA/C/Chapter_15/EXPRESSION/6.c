#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>


struct bits 
{
	unsigned int font_id: 8;
	unsigned int font_size: 4;
	unsigned int align: 3;
	unsigned int is_bold: 1;
	unsigned int is_italic: 1;
	unsigned int is_underline: 1;
};

void show_menu(struct bits);

int main(int argc, char * argv[])
{
	struct bits font;
	char select;	
	int choice;

	show_menu(font);

	while (scanf("%c", &select) == 1 && select != 'g')
	{
		switch (select)
		{
			case 'a':
				printf("Enter font(0-255)\n");			
				scanf("%d", &choice);		

				if (choice < 0 || choice > 255)
				{
					printf("Uncorrect data\n");
					break;
				}

				font.font_id = choice;
				break;	

			case 'b':
				printf("Enter font size(0-127)\n");			
				scanf("%d", &choice);		

				if (choice < 0 || choice > 127)
				{
					printf("Uncorrect data\n");
					break;
				}

				font.font_size = choice;
				break;	
			case 'c':
				printf("Enter align(0-2)\n");			
				scanf("%d", &choice);		

				if (choice < 0 || choice > 2)
				{
					printf("Uncorrect data\n");
					break;
				}

				font.align = choice;
				break;	
			case 'd':
				printf("Enter bold(0-1)\n");			
				scanf("%d", &choice);		

				if (choice < 0 || choice > 1)
				{
					printf("Uncorrect data\n");
					break;
				}

				font.is_bold = choice;
				break;	
			case 'e':
				printf("Enter italic(0-1)\n");			
				scanf("%d", &choice);		

				if (choice < 0 || choice > 1)
				{
					printf("Uncorrect data\n");
					break;
				}

				font.is_italic = choice;
				break;	
			case 'f':
				printf("Enter underline(0-1)\n");			
				scanf("%d", &choice);		

				if (choice < 0 || choice > 1)
				{
					printf("Uncorrect data\n");
					break;
				}

				font.is_underline = choice;
				break;	
			default:
				printf("???\n");
		}
		show_menu(font);

		while (getchar() != '\n')
			continue;
	}

	return 0; 
}

void show_menu(struct bits font)
{
	printf(" ID    SIZE    ALIGN   BOLD    ITALIC    UNDERLINE\n");
	printf("%3d   %4d    %5d   %4d    %6d    %9d\n", font.font_id, font.font_size, font.align, font.is_bold, font.is_italic, font.is_underline);
	printf("a) change font   b) change size   c) change align\n");
	printf("d) bold          e) italic        f) underline\n");
	printf("g) exit\n");
}

