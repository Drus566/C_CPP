#include <iostream>

int convert(int);

using namespace std;
int main(void)
{
	int farl;
	int yard;
	cin >> farl;
	yard = convert(farl);
	cout << yard << " yard = " << farl << " farl" << endl;
	return 0;
}

int convert(int farl)
{
	return farl * 220;
}
