#include "Product.h"
#include <iostream>
#include <cstring>

using namespace std;

PRODUCT::PRODUCT(char* NAME, int COUNT, float COST)
{
	Set(NAME, COUNT, COST);
}

void PRODUCT::Set(char *NAME, int COUNT, float COST)
{
	strcpy(name, NAME);
	count = COUNT;
	cost = COST;
	cout << "\n Constructor with parameters for " << this << endl;
}

void PRODUCT::SetName(char* NAME)
{
	strcpy(name, NAME);
}
		
void PRODUCT::SetCount(int COUNT)
{
	count = COUNT;
}	

void PRODUCT::SetCost(float COST)
{
	cost = COST;
}

void PRODUCT::Show()
{
	cout << "\n Object " << this << " use method Show()" << endl;	
}
	
void View(PRODUCT a)
{
	a.Show();
}

PRODUCT NoName(PRODUCT &product)
{
	PRODUCT temp(product);
	temp.SetName("NoName");
	cout << "\n Object use NoName method" << endl;
	return temp;
}
