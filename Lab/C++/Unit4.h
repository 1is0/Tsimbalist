//---------------------------------------------------------------------------

#ifndef Unit4H
#define Unit4H
class Train
{
	private:
	String date;
	String number;
	String end;
	String time;
	int coupe;
	int reserved;
	int coupeFree;
	int reservedFree;
	public:
	void Set(String& date, String& number, String& end, String& time, int& coupe, int& reserved, int& coupeFree, int& reservedFree);
	void Get(String& date, String& number, String& end, String& time, int& coupe, int& reserved, int& coupeFree, int& reservedFree);
	void Copy(Train *t);
};
//---------------------------------------------------------------------------
#endif
