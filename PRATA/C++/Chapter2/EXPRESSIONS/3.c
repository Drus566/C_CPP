#include <iostream>

using namespace std;

void print1(void);
void print2(void);

int main(void)
{

	print1();
	print1();
	print2();
	print2();
	return 0;
}

void print1(void)
{
	cout << "Three blind mice" << endl;
}

void print2(void)
{
	cout << "See how they run" << endl;
}
