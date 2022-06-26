// ptrstr.cpp
#include <iostream>
#include <cstring>
int main(void)
{
	using namespace std;
	char animal[20] = "bear";
	const char * bird = "wren";
	char * ps;
	cout << animal << " and ";
	cout << bird << "\n";
	// cout << ps << "\n" // может отобразить мусор или совершить аварийное завершение программы
	
	cout << "Enter a kind of animal: ";
	cin >> animal;
	// cin >> ps; нельзя, т.к. ps не указывает на выделенное пространство
	ps = animal;
	cout << ps << "!\n";
	cout << "Before using strcpy():\n";
	cout << animal << "at " << (int *) animal << endl;
	cout << ps << " at " << (int *) ps << endl;
	ps = new char[strlen(animal) + 1]; // получение нового хранилища
	strcpy(ps, animal); 	// копирование строки в новое хранилище
	cout << "After using strcpy():\n";
	cout << animal << " at " << (int *) animal << endl;
	cout << ps << " at " << (int *) ps << endl;
	delete [] ps;

	return 0;
}
