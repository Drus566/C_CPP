#include <iostream>
int main(void)
{
	using namespace std;
	int yams[3];
	yams[0] = 7;
	yams[1] = 8;
	yams[2] = 6;

	int yamcosts[3] = {20, 30, 5}; // создание и инициализация массива
	// Если компилятор не может инициализировать этот массив,
	// используйте static int yamcosts[3] вместо int yamcosts[3]
	cout << "\nSize of yams array = " << sizeof yams;
	cout << "\nSize of one element = " << sizeof yams[0] << endl;
	return 0;
}
