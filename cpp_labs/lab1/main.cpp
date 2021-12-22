#include <iostream>
#include <cstring>

using namespace std;

const int LNAME = 25;

class PRODUCT 
{
	char name[LNAME];
	int count;
	float cost;
public:	
	PRODUCT(){};
	PRODUCT(char* NAME, int COUNT, float COST)
	{
		strcpy(name, NAME);
		count = COUNT;
		cost = COST;
		cout << "\n Constructor with parameters for " << this << endl;
	}

	PRODUCT(PRODUCT const&){};
	~PRODUCT(){};

	char *GetName();
	int GetCount() const;
	float GetCost() const;

	void SetName(char* NAME)
	{
		strcpy(name, NAME);
	}
		
	void SetCount(int COUNT)
	{
		count = COUNT;
	}	

	void SetCost(float COST)
	{
		cost = COST;
	}

	void Set(char *NAME, int COUNT, float COST)
	{
		strcpy(name, NAME);
		count = COUNT;
		cost = COST;
		cout << "\n Constructor with parameters for " << this << endl;
	}
	
	void Show()
	{
		cout << "\n Object " << this << " use method Show()" << endl;	
	}
	
};

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
