#ifndef PRODUCT_H
#define PRODUCT_H
const int LNAME = 25;

class PRODUCT 
{
private:
	char name[LNAME];
	int count;
	float cost;

public:	
	PRODUCT(){};
	PRODUCT(char* NAME, int COUNT, float COST);
	PRODUCT(PRODUCT const&){};
	~PRODUCT(){};

	char *GetName();
	int GetCount() const;
	float GetCost() const;

	void SetName(char* NAME);
	void SetCount(int COUNT);
	void SetCost(float COST);
	void Set(char *NAME, int COUNT, float COST);
	
	void Show();
};

void View(PRODUCT);
PRODUCT NoName(PRODUCT &product);
#endif
