#include <iostream>
int main(void)
{
	using namespace std;;
	cout << "What year was your house built?\n";
	int year;
	cin.get(); //для чтения символа новой строки 
	// или (cin >> year).get();
	cout << "What its street address?\n"; 
	char address[80];
	cin.getline(address,80);
	cout << "Year built: " << year << endl;
	cout << "Address: " << address << endl;
	cout << "Done!\n";
	return 0;

}
