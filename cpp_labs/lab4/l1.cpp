#include <iostream>
#include <cstring>
using namespace std;

const int evNothing = 0;
const int evMessage = 100;
const int cmSetX = 1; // set number
const int cmSetY = 7;
const int cmGetX = 8;
const int cmGetY = 2; // get number
const int cmAdd = 3; // addition number
const int cmSub = 4; // substruction number
const int cmMul = 5; // multiplication number
const int cmDiv = 6; // division number
const int cmEq = 9; // equal numbers?
const int cmQuit = 101; // quit

int regX = 0;
int regY = 0;

struct TEvent
{
	int cmd;
	int x;
	int y;
};

class TObject
{
public:
	TObject();
	virtual int HandleEvent(TEvent &event) = 0;
	virtual void PrintClass();
	virtual void PrettyPrint();
	static void AddObj(TObject *cur);
	
	static TObject *begin;
	TObject *next;
};

void TObject::PrettyPrint()
{
    cout << ":::::::::::::::::::::";
    PrintClass();
    cout << ":::::::::::::::::::::" << endl;
}

void TObject::PrintClass()
{
	cout << "TObject";
}

void TObject::AddObj(TObject *cur)
{
	cur -> next = begin;
	begin = cur;
}

TObject::TObject() 
{
	AddObj(this);
}

class TCalc: public TObject
{
public:
	TCalc();
	int HandleEvent(TEvent &event);
	void PrintClass();
	void SetX(int x);
	void SetY(int y);
	int GetX();
	int GetY();
};

void TCalc::PrintClass()
{
	cout << "TCalc";
}

void TCalc::SetX(int x)
{
	regX = x;
}

void TCalc::SetY(int y)
{
	regY = y;
}

int TCalc::GetX()
{
	return regX;
}

int TCalc::GetY()
{
	return regY;
}

TCalc::TCalc() 
{
	regX = 0;
	regY = 0;
}

int TCalc::HandleEvent(TEvent &event)
{
	switch(event.cmd)
	{
		case cmSetX:
			SetX(event.x);
			cout << "Handle event, setting regX = " << regX << endl; 
			break;
		case cmSetY:
			SetY(event.y);
			cout << "Handle event, setting regY = " << regY << endl;
			break;
		case cmGetX:
			GetX();
			cout << "Handle event, getting regX = " << regX << endl;
			break;
		case cmGetY:
			GetY();
			cout << "Handle event, getting regY = " << regY << endl;
			break;
		default:
			cout << "Not handle event" << endl;
			return 1; 
	}
	return 0;
}

class TAdd : public TCalc
{
protected:
	float sum = 0;
public:
	TAdd();
	int HandleEvent(TEvent &event);
	void Add();
	void Sub();
	void Mul();
	void Div();
	bool Equal();
	void PrintClass();
};

TAdd::TAdd() 
{
	sum = 0;
} 

void TAdd::Add()
{
	sum = regX + regY; 
}

void TAdd::Sub()
{
	sum = regX - regY;
}

void TAdd::Mul()
{
	sum = regX * regY;
}

void TAdd::Div()
{
	sum = regX / regY;
}

bool TAdd::Equal()
{
	return regX == regY;
}

void TAdd::PrintClass()
{
	cout << "TAdd";
}

int TAdd::HandleEvent(TEvent &event)
{
	switch (event.cmd)
	{	
		case cmAdd:
			Add();
			cout << "Handle event, adding regX and regY: " << sum << endl; 
			break;
		case cmSub:
			Sub();
			cout << "Handle event, substraction regX and regY: " << sum << endl;
			break;
		case cmMul:
			Mul();
			cout << "Handle event, multiplication regX and regY: " << sum << endl;
			break;
		case cmDiv:
			Div();
			cout << "Handle event, division regX and regY: " << sum << endl;
			break;
		case cmEq:
			cout << "Handle event, regX == regY ?: " << Equal() << " (0 - false, 1 - true)" << endl;
			break;
		default:
			cout << "Not handle event" << endl;
			return 1;
	}
	return 0;
}

TObject *TObject::begin;

void Execute(TEvent &event)
{
	int stop = 1;
	TObject *obj = TObject::begin;
	while(obj)
	{
		obj -> PrettyPrint();
		stop = obj -> HandleEvent(event);
		if (stop == 0) { break; } 
		obj = obj->next;
	}
}

bool Test(char code, char *OpInt)
{
    for(int i = 0; i < strlen(OpInt); i++)
    {
        if (code == OpInt[i])
        {
            return true;
        }
    }
	return false;
}

int GetIntFromCode(char *str)
{
	char *number = new char[30];
	if (strlen(str) > 1) 
	{
		for(int i = 1; i < strlen(str); i++)
		{
			number[i - 1] = str[i];	
		}
		int num;
		sscanf(number, "%d", &num);
		return num;
	}
	return 0;
}
 
int main()
{
	TObject::begin = 0;
	TCalc calc;
	TAdd add;	

	while(true)
	{
		char *OpInt = "+-*/=?qxXyY";
		char code;
		char *s = new char[30];
		cout << '>';
		cin >> s;

		cout << "Command: " << s[0] << endl;

		code = s[0];		
		TEvent event;

		if (Test(code, OpInt))
		{
			switch(code)
			{
				case '+':
					event.cmd = cmAdd;
					break;
				case '-':
					event.cmd = cmSub;
					break;
				case '/':
					event.cmd = cmDiv;
					break;
				case '*':
					event.cmd = cmMul;
					break;
				case 'x':
					event.cmd = cmSetX;
					event.x = GetIntFromCode(s);
					break;
				case 'X': 
					event.cmd = cmGetX;
					break;
				case 'y':
					event.cmd = cmSetY;
					event.y = GetIntFromCode(s);
					break;
				case 'Y':
					event.cmd = cmGetY;
					break;
				case '=':
					event.cmd = cmEq;
					break;
				case 'q':
					cout << "Quit from programm" << endl;
					return 0;
				default:
					cout << "Not Handle" << endl;
					break;
			}	
		}
		else
		{
			event.cmd = 0; 
		}	
		Execute(event);
	}	
	return 0;
}
