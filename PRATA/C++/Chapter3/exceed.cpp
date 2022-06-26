#include <iostream> 
#define ZERO 0 // создает символ зиро для 0
#include <climits> // определяет INT_MAX как наибольшее значение int

int main() {
	using namespace std;
	short sam = SHRT_MAX; // инициализирует переменную максимальным значением
	unsigned short sue = sam;

	cout << "Sam has " << sam << " dollars and Sue has " << sue;
	cout << " dollars deposited." << endl
			 << "Add $1 to each account." << endl << "Now ";
	sam = sam + 1;
	sue = sue + 1;
	cout << "Sam has " << sam << " dollars and Sue has " << sue << endl;
}

