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

	int GetX() { return x; }
	int GetY() { return y; } 

	void showObjectClass()
	{
		cout << "\nArea" << endl;
	}	
	
	virtual int GetSquare() { return square; } 
// 	Second way add to the list
// 	virtual void Add() { Place::Add(this); }
};

#endif
