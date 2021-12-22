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


class TObject
{	
protected:
	TShema *owner;
public:
	TObject();
	~TObject();
	virtual void HandleEvent(TEvent&);
	virtual void ClearEvent(TEvent&);
};

class TShema : public TObject
{
protected:
	TItem *last;
public:
	TShema();
	~TShema();	
	virtual void Insert(TObject*);
	virtual void HandleEvent(TEvent&);
};

class TDevice : public TShema
{
protected:
	int EndState;
public:
	virtual void GetEvent(TEvent&);
	virtual void Execute();
	virtual int Valid();
	virtual void EndExec();
};

class TRec : public TObject
{
protected:
	TReg *sum;
	TReg *reg;
public:
	TCalc();
	void HandleEvent(TEvent&);
	void GetEvent(TEvent&);
	void Execute();
	float GetSum();
	void PutSum(float);
	void Help();
};

class TAdd : public TObject
{
public:
	void HandleEvent(TEvent&);
	void Add();
};
	
TObject::TObject()
{ 
	owner = 0;
}

TShema::TShema()
{
	last = 0;
}

TCalc::TCalc()
{
	TObject *r;
	sum = new TReg;
	reg = new TReg;
	r = new TAdd;
	Insert(sum);
};

TCalc::HandleEvent(TEvent &event)
{
	if (event.what == evMessage)
	{
		switch (event.command)
		{
			cmQuit:
				EndExec();
				ClearEvent(event);
				break;
			cmGet:
				cout << GetSum() << endl;
				ClearEvent(event);
				break;
			cmSet:
				PutSum(event.A);
				ClearEvent(event);
				break;
			default:
				TSheme::HandleEvent(event);
		}
	}
}

TSheme::HandleEvent(TEvent &event)
{	
	TItem *r;	
	if (event.what == evMessage)
	{
		r = last;
		while (event.what != evNothing && r != 0)
		{
			r -> HandleEvent(event);
			r = r -> next;
		}
	}
}
	
TAdd::HandleEvent(TEvent &event)
{
	if (event.what == evMessage)
	switch (event.command)
	{
		cmAdd:
			(owner -> reg) -> SetX(event.A);
			Add();
			ClearEvent(event);
			break;
	}
}

TAdd::Add()
{
	float a, b;
	a = (owner -> sum) -> GetX();
	b = (owner -> reg) -> GetX();
	(owner -> sum) -> SetX(a + b);
}

	
