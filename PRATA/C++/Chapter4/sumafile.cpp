#include <iostream>
#include <fstream> // поддержка файлового ввода вывода
#include <cstdlib> // поддержка exit()

const int SIZE = 60;

int main(void)
{
	using namespace std;
	char filename[SIZE];
	ifstream inFile; // объект для обработки файлового ввода
	cout << "Enter name of data file: "; // запрос имени файла данных
	cin.getline(filename, SIZE);
	inFile.open(filename);		// ассоциирование inFile с файлом

	if (!inFile.is_open())
	{
		cout << "Could not open the file " << filename << endl;
		cout << "Program terminating.\n";
		exit(EXIT_FAILURE);
	}

	double value;
	double sum = 0.0;
	int count = 0;

	inFile >> value;
	while (inFile.good())
	{
		++count;
		sum += value;
		inFile >> value;
	}

	if (inFile.eof()) // достигнут конец файла
		cout << "End of file reached.\n";
	else if (inFile.fail()) // ввод прекращен из-за несоответствия типа данных
		cout << "Input terminated by data mismatch.\n";
	else // ввод прекращен по непонятной причине
		cout << "Input terminated for unknown reason.\n";

	if (count == 0) // данные для обработки отсутствуют
		cout << "No data processed.\n";
	else
	{
		cout << "Items read: " << count << endl;
		cout << "Sum: " << sum << endl;
		cout << "Average: " << sum / count << endl;
	}
	inFile.close();

	return 0;
}
