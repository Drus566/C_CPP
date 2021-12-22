#include <iostream>
#include <cstring>

using namespace std;

class Place
{ 
public:	
	Place()
	{
		// First way to add to the list
		Add(this);
	}

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

Place *Place::begin;

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

Area::Area(int _x, int _y, int _square) : Place()
{
 	x = _x;
 	y = _y;
	square = _square;
}

const int LNAME = 25;

class City : public Area 
{ 
protected:
	char name[LNAME];

public:
	City(int _x, int _y, int _square, char *_name) : Area(_x, _y, _square)
	{
		strcpy(name, _name);	
	}

	void showObjectClass()
	{
		cout << "\nCity" << endl;
	}
	
	char* GetName() { return name; }	
};

class Metropolis : public Area
{
protected:
	int population;

public:
	Metropolis(int _x, int _y, int _square, int _population) : Area(_x, _y, _square)
	{
		population = _population;
	}
	
	void showObjectClass()
	{
		cout << "\nMetropolis" << endl;
	}

	int GetPopulation() { return population; }
};

int main()
{
	Place::begin = 0;

	Area area(25, 30, 130);
	area.showObjectClass();
	cout << "x: " << area.GetX() << endl;
	cout << "y: " << area.GetY() << endl;
	cout << "square: " << area.GetSquare() << endl;

	City city(5, 12, 813901, "Keln");
	city.showObjectClass();
	cout << "x: " << city.GetX() << endl;
	cout << "y: " << city.GetY() << endl;
	cout << "square: " << city.GetSquare() << endl;
	cout << "name: " << city.GetName() << endl;
	
	Metropolis metropolis(1313, 99, 21386393, 7520123);
	metropolis.showObjectClass();
	cout << "x: " << metropolis.GetX() << endl;
	cout << "y: " << metropolis.GetY() << endl;
	cout << "square: " << metropolis.GetSquare() << endl;
	cout << "population: " << metropolis.GetPopulation() << endl;
	
// Second way to add to the list
//	metropolis.Add();
//	city.Add();
//	area.Add();
	cout << "\nList of Places:" << endl;
	Place::Show();	
}
