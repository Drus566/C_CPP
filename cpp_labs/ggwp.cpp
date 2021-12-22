#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	char *OpInt = "+-*/=?q";
	char *code_test = "?";

	for(int i = 0; i < strlen(OpInt); i++)
	{
		if(code_test[0] == OpInt[i])
		{
			cout << "code: " << code_test << " include in operations" << endl;
		}
	}

 	char code;
	cin >> code;
	return 0;
}
