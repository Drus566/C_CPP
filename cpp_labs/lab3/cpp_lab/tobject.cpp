class TObject
{
public:
	virtual void Show() = 0;
};

class TPlace: public TObject
{
protected:
	int x;
	int y;
	int square;

	TArea *head;
	TItem *last;

public:
	TPlace(int x, int y, int square, TArea*);
	TPlace(TPlace&);
	~TPlace();

	int GetX() { return x; }
	int GetY() { return y; }
	int GetSquare() { return square; }
	
	TArea *GetHead();
	
	void SetX(int x);
	void SetY(int y);
	void SetSquare(int square);

	void SetHead(TArea *p);
	void Insert(TObject *p);

	virtual void Show() = 0;
};


		
