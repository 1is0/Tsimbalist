//---------------------------------------------------------------------------

#ifndef RealTrainH
#define RealTrainH
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
	String GetEnd();
	String GetDate();
    String GetNumber();
};
//---------------------------------------------------------------------------
#endif
