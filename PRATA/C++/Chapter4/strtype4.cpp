// strtype4.cpp
#include <iostream>
#include <string>
#include <cstring>

int main(void)
{
	using namespace std;
	char charr[20]; 						
	string str;

	// Длинна строки charr перед вводом
	cout << "Length of string in charr before input: "
		<< strlen(charr) << endl;

	// Длинна строки в str перед вводом
	cout << "Length of string in str before input: "
		<< str.size() << endl;

	cout << "Enter a line of text:\n";
	cin.getline(charr, 20);
	cout << "You entered: " << charr << endl;
	cout << "Enter another line of text:\n";
	getline(cin, str); // теперь cin - аргумент, спецификатор длинны отстутствует 
	cout << "You entered: " << str << endl;

	cout << "Length of string in charr after input: "
		<< strlen(charr) << endl;

	// Длина строки в str после ввода
	cout << "Length of string in str after input: "
		<< str.size() << endl;

	return 0;
}
