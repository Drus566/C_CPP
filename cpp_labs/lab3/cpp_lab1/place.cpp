#include <iostream>

using namespace std;

class Place
{ 
public:	
	Place() {}
    Place(const Place&) {}
	~Place() {}

	virtual int GetX() = 0;
	virtual int GetY() = 0;
	virtual int GetSquare() = 0;
	virtual void showObjectClass() = 0;
 	
	static Place *begin;
	Place *next;
};

