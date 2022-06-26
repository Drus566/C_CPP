// strtype3.cpp
#include <iostream>
#include <string>
#include <cstring>

int main(void)
{
	using namespace std;
	char charr1[20]; 						// создание пустого массива
	char charr2[20] = "jaguar"; // создание инициализированного массива
	string str1; 								// создание пустого объекта строки
	string str2 = "panther";		// создание инициализированного объекта строки 

	// присвивание объектов string и символьных массивов
	str1 = str2; // копирование str2 в str1
	strcpy(charr1, charr2); // копирование charr2 в charr1	

	// Добавление объектов string и символьных массивов
	str1 += " paste"; 			// добавление " paste" в конец str1
	strcat(charr1, " juice"); // добавление " juice" в конец charr1

	int len1 = str1.size(); // получение длины str1
	int len2 = strlen(charr1); // получение длины charr1

	return 0;
}
