#include <iostream>

using namespace std;

class Place
{ 
public:	
	Place()
	{
		// First way to add to the list
		Add(this);
	}
	
    Place(const Place&) {}
	~Place() {}

	virtual int GetX() = 0;
	virtual int GetY() = 0;
	virtual void showObjectClass() = 0;
 	
	static Place *begin;
	Place *next;

	static void Add(Place *cur)
	{
 		cur->next = begin;
 		begin = cur;
 	}

	static void Show()
	{
		Place *l = begin;
		while(l) 
		{
			cout << "* ";
			l -> showObjectClass();
			l = l->next;
		}
	}
};

//Place *Place::begin;
