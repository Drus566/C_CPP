#include <iostream> 
int main(void)
{
	using namespace std;

	int chest = 42;
	int waist  = 42;
	int inseam = 42;

	cout << "Monsieur cuts a striking figure!\n";
	cout << "chest = " << chest << " (42 in decimal)\n";
	cout << hex; // манипулятор для смены основания системы счисления
	cout << "waist = " << waist << " (0x42 in hex)\n";
	cout << oct;
	cout << "inseam = " << inseam << " (042 in octal)\n";

	return 0; 
}
