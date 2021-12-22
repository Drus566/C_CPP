#ifndef GROUP_H
#define GROUP_H
#include "place.cpp"

using namespace std;

class Group
{
private:
	Place *begin;
	Place *next;

	int count;
	int num;

public:
	Group();
	~Group();

	void GreatestX();
	void GreatestY();

	void Add(Place *cur);
	void Del(); 
};

#endif
