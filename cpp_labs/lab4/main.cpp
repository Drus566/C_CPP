struct TEvent
{
	int what;
	union 
	{
		MouseEventType mouse;
		KeyDownEvent keyDown;
		MessageEvent message;
	}
};

struct MouseEventType
{
	int buttons;
	int doubleClick;
	TPoint where;
};

struct KeyDownEvent
{
	union 
	{
		int keyCode;
		union 
		{
			char charCode;
			char scanCode;
		};
	};
};	

struct MessageEvent
{
	int command;
	void infoPtr;
};

void TDerivedClass::HandleEvent(TEvent& event)
{
	TBaseClass::handleEvent(event);
	if(event.what == evCommand)
	{
		switch(event.message.command)
		{
			case cmCommand1:
				ClearEvent(event);
				break;
			case cmCommand2:
				ClearEvent(event);
				break;
			default:
				break;
		}	
	}
}

void TGroup::HandleEvent(TEvent& event)
{
	if(event.what == evCommand)
	{
		switch(event.message.command)
		{
			default:
				while((event.what != evNothing)
				{
					

int TMyApp::Execute()
{
	do {
		endState = 0;
		GetEvent(event);
		HandleEvent(event);	

		if(event.what != evNothing)
		{
			EventError(event);
		}
	} while(!Valid());
			
	return endState;
}

const int evNothing = 0;
const int evMessage = 100;
const int cmSet = 1;
const int cmGet = 2;
const int cmAdd = 3;
const int cmQuit = 101;

struct TEvent
{
	int what
	union {
		int evNothing;
		union {
			int command;
			int a;
		}
	}
}

class TInt
{
	int EndState;

	public: 
	int x;
	Int(int x1);
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
};

void TInit::GetEvent(TEvent &event)
{
	char *OpInt = "+-*/=?q";
	char s[20];
	char code;
	cout << '>';
	cin >> s; code = s[1];
	if (Test(char code, char *OpInt))
	{
		event.what = evMessage;
		switch(code)
		{
			case '+': 
				event.command = cmAdd;
				break;
			case 'q':
				event.command = cmQuit;
				break;
		}
	}	
	else
	{
		event.what == evNothing;
	}
};
		
int TMyApp:Execute()
{
	do {
		endState = 0;
		GetEvent(event);
		HandleEvent(event);
		if (event.what != evNothing) {}
	} while (!Valid());
	return endState;
}

void TInt::HandleEvent(TEvent &event)
{
	if (event.what == evMessage)
	{	
		switch (event.message.command)
		{
			case cmAdd:AddY (event.A);
				ClearEvent(event);
				break;
			case cmQuit:EndExec();
				break;
			case cmQuit:EndExec();
				ClearEvent(event);
				break;
		}
	}
}
		
int TInt::Valid()
{
	if (EndState == 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

void TInt::ClearEvent(TEvent &event)
{
	Event.what := evNothing;
}

void TInt::EndExec()
{
	EndState = 1;
}

void TInt::AddY(int Y)
{
	x += Y;
}

void main()
{
	TInt MyApp;
	MyApp.Execute();
}


int main()
{
	return 0;
}
