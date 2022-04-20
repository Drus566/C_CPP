#include <iostream>

double convert(int);

using namespace std;

int main(void)
{
	int celsii;
	double farengeith;
	cout << "Please enter a Celisii value: ";
	cin >> celsii;
	farengeith = convert(celsii);
	cout << celsii << " degrees CElisius = " << farengeith << " Farengeith " << endl;
	return 0;
}

double convert(int celsii)
{
	return 1.8 * celsii + 32;
}
