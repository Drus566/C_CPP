#include <iostream>
#include "area.h"
#ifndef METROPOLIS_H
#define METROPOLIS_H

using namespace std;

class Metropolis : public Area
{
protected:
	int population;

public:
	Metropolis() {} 
	~Metropolis() {}
	Metropolis(const Metropolis&) {}
	Metropolis(int _x, int _y, int _square, int _population); 
	
	void showObjectClass()
	{
		cout << "\nMetropolis" << endl;
	}

	int GetPopulation() { return population; }
};

# endif
