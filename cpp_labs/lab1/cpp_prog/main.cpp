#include "Product.h"

void (PRODUCT::*pf)();

int main()
{
	PRODUCT tea("Tea", 19, 20), copy_tea = tea;
	View(tea);	
	PRODUCT some_product = NoName(tea);
	
	PRODUCT products[3];
	products[0].Set("Tea", 1, 21);
	products[1].Set("Milk", 4, 12);
	products[2].Set("Owl", 123, 10.5);

	PRODUCT *another_product;
	another_product = new PRODUCT[3];
	another_product-> Set("Bread", 20, 7);
	another_product-> Set("Sugar", 90, 1);
	another_product-> Set("Water", 130, 5);
	
	pf = &PRODUCT::Show;
	(another_product[1].*pf)();

	return 0;	
}
