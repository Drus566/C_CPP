#include <cstring>
#include "city.h"

City::City(int _x, int _y, int _square, char *_name) : Area(_x, _y, _square)
{
	strcpy(name, _name);	
}


