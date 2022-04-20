#include <iostream>

int convert(int);

using namespace std;

int main(void)
{
	int age;
	int month;
	cout << "Enter your integer age: ";
	cin >> age;
	month = convert(age);
	cout << age << " age = " << month << " month" << endl;
	return 0;
}

int convert(int age)
{
	return age * 12;
}
