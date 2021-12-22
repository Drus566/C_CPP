#include <iostream>
#ifndef AREA_H
#define AREA_H
#include "place.cpp"

using namespace std;

class Area : public Place
{
protected:
	int square;
	int x;
	int y;

public:
	Area(int x, int y, int square);
	Area() {}
	~Area() {} 
	Area(const Area&) {}

	int GetX() { return x; }
	int GetY() { return y; } 
	int GetSquare() { return square; }

	void showObjectClass()
	{
		cout << "Area" << endl;
	}	
	
//	virtual int GetSquare() { return square; } 
};

#endif
