//---------------------------------------------------------------------------

#pragma hdrstop

#include "RealTrain.h"
String Train::GetEnd()
{
	return end;
}
String Train::GetDate()
{
    return date;
}
String Train::GetNumber()
{
    return number;
}
void Train::Set(String& date, String& number, String& end, String& time, int& coupe, int& reserved, int& coupeFree, int& reservedFree)
{
	this->date=date;
	this->number=number;
	this->end=end;
	this->time=time;
	this->coupe=coupe;
	this->reserved=reserved;
	this->coupeFree=coupeFree;
	this->reservedFree=reservedFree;
}
void Train::Get(String& date, String& number, String& end, String& time, int& coupe, int& reserved, int& coupeFree, int& reservedFree)
{
	date=this->date;
	number=this->number;
	end=this->end;
	time=this->time;
	coupe=this->coupe;
	reserved=this->reserved;
	coupeFree=this->coupeFree;
	reservedFree=this->reservedFree;
}
void Train::Copy(Train *t)
{
	date=t->date;
	number=t->number;
	end=t->end;
	time=t->time;
	coupe=t->coupe;
	reserved=t->reserved;
	coupeFree=t->coupeFree;
	reservedFree=t->reservedFree;
}
//---------------------------------------------------------------------------
#pragma package(smart_init)
