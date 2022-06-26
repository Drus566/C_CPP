#include <iostream>
int main(void)
{
	using namespace std;
	int auks, bats, coots;

	// следующий оператор суммирует значения типа double
	// а полученный результат преобразуется в тип int
	auks = 19.99 + 11.99;
	// эти операторы суммируют целочисленные значения
	bats = (int) 19.99 + (int) 11.99; // старый синтаксис С
	coots = int (19.99) + int (11.99); // новый синтаксис С++
	cout << "auks = " << auks << ", bats = " << bats;
	cout << ", coots = " << coots << endl;
	char ch = 'Z';
	cout << "The code for " << ch << " is "; // вывод в формате char
	cout << int(ch) << endl; // вывод в формате int
	cout << "Yes, the code is	";
	cout << static_cast<int>(ch) << endl;

	return 0;
}
