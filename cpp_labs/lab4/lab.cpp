// Calc code
// signs +,-,*,/,=,?,q
// parameter - int
// consts - commands
const int evNothing = 0;
const int evMessage = 100;
const int cmSet = 1; // set number
const int cmGet = 2; // get number
const int cmAdd = 3; // addition number
const int cmSub = 4; // substruction number
const int cmMul = 5; // multiplication number
const int cmDiv = 6; // division number
// and so on
const int cmQuit = 101; // quit

struct TEvent
{
	int what;
	union {
		int evNothing;
		union {
			int command;
			int a;
		}
	}
};

// Calc object working with integer
class TInt 
{
private:
	int EndState;
public:
	int x;

	TInt(int x1);
	virtual ~Int();

	virtual void GetEvent(TEvent &event);
	virtual int Execute();
	virtual void HandleEvent(TEvent &event);
	virtual void ClearEvent(TEvent &event);

	int Valid();
	void EndExec();
	int GetX();
	void SetX(int newX);
	void AddY(int Y);
	// and so on
};	

bool Test(char code, char *OpInt)
{
	for(int i = 0; i < strlen(OpInt); i++)
    {
        if(code == OpInt[i])
        {
			return true;	
        } 
		else 
		{
			return false;	
		}
    }
} 

// Implementation of basic methods
void TInit::GetEvent(TEvent &event)
{
	char *OpInt = "+-*/=?q"; // strings consists of symbols of operations
	char code;
	
	cout << '>';
	cin >> s;
	code = s[1];
	
	if (Test(char code, char *OpInt) // Test check does the character come in code op
	{
		event.what = evMessage;	
		switch(code)
		{
			case '+':
				event.command = cmAdd;
				break;
			case '-':
				event.command = cmSub;
				break;
			case '/':
				event.command = cmDiv;
				break;
			case '*':
				event.command = cmMul;
				break;
			case '=':
				event.command = cmSet;
				break;
			case '?':
				event.command = cmGet;
				break;
			case 'q': 
				event.command = cmQuit;
				break;
		}
		// selection second parameter, converting him to int and assign field A
	}
	else
	{
		event.what = evNothing;
	}
}

int TMyApp::Execute()
{
	do { 
		endState = 0;
		GetEvent(event); // get event
		HandleEvent(event); // handle event
		if (event.what != evNothing) // event not handle
		{
			// ...
		}
	} while (!Valid());
	return endState;
}

void TInt::HandleEvent(TEvent &event)
{
	if (event.what == evMessage)
	{
		switch (event.message.command)
		{
			case cmAdd:
				AddY(event.a);
				ClearEvent(event);
				break;
			// case cmSub:
				
			// and so on ...
			case cmQuit:
				EndExec();
				ClearEvent(event);	
				break;
		}
	}
}
	
int TInt::Valid();
{
	if (EndState == 0) return 0;
	else return 1;
}

void TInt::ClearEvent(TEvent &event)
{
	event.what = evNothing;
}

void TInt::EndExec()
{
	EndState = 1;
}

void TInt::AddY(int Y)
{
	x += Y;
}

void TInt::SubY(int Y)
{
	x -= Y;
}

void TInt::MulY(int Y)
{
	x *= Y;
}

void TInt::DivY(int Y)
{
	x /= Y;
}

int TInt::Get()
{
	return x;
}

void TInt::SetX(int X)
{
	x = X;
}

void main()
{	
	TInt MyApp;
	MyApp.Execute();
}

