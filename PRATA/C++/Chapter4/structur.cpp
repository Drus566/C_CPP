// structur.cpp
#include <iostream>

struct inflatable
{
	char name[20];
	float volume;
	double price;
};

int main(void)
{
	using namespace std;
	inflatable guest = 
	{
		"Glorious Gloria",
		1.88,
		29.99
	};

	inflatable pal = 
	{
		"Audia Artur",
		3.12,
		32.99
	};
	// ПРИМЕЧАНИЕ: некоторые реализации требуют использования
	// static inflatable guest = 
	
	cout << "Expand your guest list with " << guest.name;
	cout << " and " << pal.name << "!\n";
	cout << "You can have both for $";
	cout << guest.price + pal.price << "!\n";

	return 0;
}
