#include <iostream>

#include "area.h"
#include "city.h"
#include "metropolis.h"

using namespace std;

class Group
{
	int count;

public:
	Place *begin = 0;
	Place *next;

	Group() 
	{
		count = 0;
	}

	int GreatestParam(int param, int _param)
	{	
		if (param > _param)
		{
			return param; 
		} 
		else 
		{
			return _param;
		}
	}
	
	void GreatestX(Place *l) 
	{
		int x = 0;

		while(l)
		{
			x = GreatestParam(l -> GetX(), x);
			l = l -> next;
		}
			
		cout << "Greatest X in list: " << x << endl;
	} 

	void GreatestY(Place *l)
	{
		int y = 0;
			
		while(l)
		{
			y = GreatestParam(l -> GetY(), y);
			l = l -> next;
		}

		cout << "Greatest Y in list: " << y << endl;
	}

	void GreatestSquare(Place *l)
	{
		int square = 0;
		
		while(l)
		{
			square = GreatestParam(l -> GetSquare(), square);
			l = l -> next;
		}
			
		cout << "Greatest SQUARE in list: " << square << endl;
	}

	void Add(Place *cur)
	{
		cur->next = begin;
		begin = cur;
		count = count + 1;
	}	

	void Del() {} 
	// case:
	// 1 - x
	// 2 - y
    // 3 - square

	void Show(int _case)
	{
		Place *l = begin;

		if(_case == 1)
		{
			GreatestX(l);	
		}
		else if(_case == 2)
		{
			GreatestY(l);
		}
		else if(_case == 3)
		{
			GreatestSquare(l);
		}
	}
	
	void ShowAll()
	{
		Place *l = begin;
		while(l)
		{
			l -> showObjectClass();
			l = l -> next;
		}
	}
};

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
	Group group;
	group.Add(&area);
	group.Add(&city);
	group.Add(&metropolis);
	
	group.ShowAll();
	cout << endl;
	group.Show(1);
	group.Show(2);
	group.Show(3);
}
