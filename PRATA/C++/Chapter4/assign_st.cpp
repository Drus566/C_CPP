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
	inflatable bouquet = 
	{
		"sunflowers",
		0.20,
		12.49
	};
	inflatable choice;
	cout << "bouquet: " << bouquet.name << " for $";
	cout << bouquet.price << endl;
	choice = bouquet; // присваивание одной стркутуры другой
	cout << "choice: " << choice.name << " for $";
	cout << choice.price << endl;
	return 0;
}
