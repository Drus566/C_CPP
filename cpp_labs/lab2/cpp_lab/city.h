#ifndef CITY_H
#define CITY_H
#include <iostream>
#include "area.h"

using namespace std;

const int LNAME = 25;

class City : public Area 
{ 
protected:
	char name[LNAME];

public:
	City(int _x, int _y, int _square, char *_name); 

	void showObjectClass()
	{
		cout << "\nCity" << endl;
	}
	
	char* GetName() { return name; }	
};

#endif
