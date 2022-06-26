#include <iostream>
#include <string>
int main(void)
{
	using namespace std;
	char charr1[20]; 						// создание пустого массива
	char charr2[20] = "jaguar"; // создание инициализированного массива
	string str1; 								// создание пустого объекта строки
	string str2 = "panther";		// создание инициализированного объекта строки 

	cout << "Enter a kind of feline: ";
	cin >> charr1;
	cout << "Enter another kind of feline: ";
	cin >> str1;
	cout << charr1 << " " << charr2 << " "
			<< str1 << " " << str2
			<< endl;
	cout << "The third letter in " << charr2 << " is "
		<< charr2[2] << endl;
	cout << "The third letter in " << str2 << " is "
		<< str2[2] << endl;
	return 0;
}
