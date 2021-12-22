#include <iostream>

#include "area.h"
#include "city.h"
#include "metropolis.h"
#include <list>

using namespace std;

int main()
{
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
	
	cout << "\nList of group:" << endl;
	list <Place> group;	
	group.push_front(area);
}
