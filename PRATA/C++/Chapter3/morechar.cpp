#include <iostream> 
int main(void)
{
	using namespace std;
	char ch = 'M'; // присваивает ch код ASCII символа M
	int i = ch; 	// сохраняет этот же код в int
	cout << "The ASCII code for " << ch << " is " << i << endl;

	cout << "Add one to the character code:" << endl;
	ch = ch + 1;
	i = ch;
	cout << "The ASCII code for " << ch << " is " << i << endl;

	// Использование функции-члена cout.put() для отображения символа
	cout.put(ch);

	// Использование cout.put() для отображения символьной константы
	cout.put('!');

	cout << endl << "Done" << endl;

	return 0;
}
