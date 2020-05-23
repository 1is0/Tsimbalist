//---------------------------------------------------------------------------

#pragma hdrstop

#include "RealTrainContainer.h"
#include "RealTask2.h"
TStringList *Sl=new TStringList;
String FileName;
Train *addData;
Train *delData;
int TrainContainer::GetSize()
{
	return size;
}
void TrainContainer::Copy(TMemo *Memo1)
{
	if(Form8->OpenDialog1->Execute())
	{
		Form8->OutputButton->Enabled=True;
		Form8->AddButton->Enabled=True;
		Form8->DeleteButton->Enabled=True;
		Form8->CorrectButton->Enabled=True;
		Form8->PlaceButton->Enabled=True;
		Form8->DayButton->Enabled=True;
		Form8->TypeButton->Enabled=True;
		FileName=Form8->OpenDialog1->FileName;
		Form8->Filename->Caption=FileName;
		String date, number, end, time;
		int coupe, reserved, coupeFree, reservedFree;
		Sl->LoadFromFile(FileName);
		size=Sl->Count/8;
		data = new Train[size];
		int j=0;
		Memo1->Lines->Clear();
		Memo1->ReadOnly=True;
		for (int i = 0; i < size; i++)
		{
			date=Sl->Strings[0+j];
			number=Sl->Strings[1+j];
			end=Sl->Strings[2+j];
			time=Sl->Strings[3+j];
			coupe=StrToInt(Sl->Strings[4+j]);
			reserved=StrToInt(Sl->Strings[5+j]);
			coupeFree=StrToInt(Sl->Strings[6+j]);
			reservedFree=StrToInt(Sl->Strings[7+j]);
			j+=8;
			(data+i)->Set(date, number, end, time, coupe, reserved, coupeFree, reservedFree);
			Memo1->Lines->Add(IntToStr(i+1)+"-й поезд");
			Memo1->Lines->Add("День отправления: "+date);
			Memo1->Lines->Add("Номер рейса: "+number);
			Memo1->Lines->Add("Конечный пункт назначения: "+end);
			Memo1->Lines->Add("Время отправления: "+time);
			Memo1->Lines->Add("Купейные места: "+IntToStr(coupe));
			Memo1->Lines->Add("Плацкартные места: "+IntToStr(reserved));
			Memo1->Lines->Add("Свободные купейные места: "+IntToStr(coupeFree));
			Memo1->Lines->Add("Свободные плацкартные места: "+IntToStr(reservedFree));
			Memo1->Lines->Add("");
		}
	}
}
void TrainContainer::InputSize(TForm5 *Form5)
{
	if(Form8->OpenDialog1->Execute())
	{
		FileName=Form8->OpenDialog1->FileName;
		Form8->Filename->Caption=FileName;
		size=StrToInt(Form5->Amount->Text);
		data = new Train[size];
		Sl->LoadFromFile(FileName);
		Sl->Clear();
		Sl->SaveToFile(FileName);
	}
	else
	{
		Form8->Close();
    }
}
void TrainContainer::Input(TForm9 *Form9,int i)
{
	String date, number, end, time;
	int coupe, reserved, coupeFree, reservedFree;
	date=Form9->Date->Text;
	Sl->Add(date);
	Form9->Date->Clear();
	number=Form9->Number->Text;
	Sl->Add(number);
	Form9->Number->Clear();
	end=Form9->End->Text;
	Sl->Add(end);
	Form9->End->Clear();
	time=Form9->Time->Text;
	Sl->Add(time);
	Form9->Time->Clear();
	coupe=StrToInt(Form9->Coupe->Text);
	Sl->Add(coupe);
	Form9->Coupe->Clear();
	reserved=StrToInt(Form9->Reserved->Text);
	Sl->Add(reserved);
	Form9->Reserved->Clear();
	coupeFree=StrToInt(Form9->CoupeFree->Text);
	Sl->Add(coupeFree);
	Form9->CoupeFree->Clear();
	reservedFree=StrToInt(Form9->ReservedFree->Text);
	Sl->Add(reservedFree);
	Form9->ReservedFree->Clear();
	(data+i)->Set(date, number, end, time, coupe, reserved, coupeFree, reservedFree);
	Sl->SaveToFile(FileName);
}
void TrainContainer::Output(TMemo *Memo1)
{
	String date, number, end, time;
	int coupe, reserved, coupeFree, reservedFree;
	Memo1->Lines->Clear();
	Memo1->ReadOnly=True;
	for (int i = 0; i < size; i++)
	{
		(data+i)->Get(date, number, end, time, coupe, reserved, coupeFree, reservedFree);
		Memo1->Lines->Add(IntToStr(i+1)+"-й поезд");
		Memo1->Lines->Add("День отправления: "+date);
		Memo1->Lines->Add("Номер рейса: "+number);
		Memo1->Lines->Add("Конечный пункт назначения: "+end);
		Memo1->Lines->Add("Время отправления: "+time);
		Memo1->Lines->Add("Купейные места: "+IntToStr(coupe));
		Memo1->Lines->Add("Плацкартные места: "+IntToStr(reserved));
		Memo1->Lines->Add("Свободные купейные места: "+IntToStr(coupeFree));
		Memo1->Lines->Add("Свободные плацкартные места: "+IntToStr(reservedFree));
		Memo1->Lines->Add("");
	}
}
void TrainContainer::InputAdd(int addsize)
{
	addData=new Train[addsize];
	for (int i = 0; i < size; i++)
	{
		(addData+i)->Copy(data+i);
	}
}
void TrainContainer::Add(TForm9 *Form9,int i)
{
	String date, number, end, time;
	int coupe, reserved, coupeFree, reservedFree;
	date=Form9->Date->Text;
	Sl->Add(date);
	Form9->Date->Clear();
	number=Form9->Number->Text;
	Sl->Add(number);
	Form9->Number->Clear();
	end=Form9->End->Text;
	Sl->Add(end);
	Form9->End->Clear();
	time=Form9->Time->Text;
	Sl->Add(time);
	Form9->Time->Clear();
	coupe=StrToInt(Form9->Coupe->Text);
	Sl->Add(coupe);
	Form9->Coupe->Clear();
	reserved=StrToInt(Form9->Reserved->Text);
	Sl->Add(reserved);
	Form9->Reserved->Clear();
	coupeFree=StrToInt(Form9->CoupeFree->Text);
	Sl->Add(coupeFree);
	Form9->CoupeFree->Clear();
	reservedFree=StrToInt(Form9->ReservedFree->Text);
	Sl->Add(reservedFree);
	Form9->ReservedFree->Clear();
	(addData+i)->Set(date, number, end, time, coupe, reserved, coupeFree, reservedFree);
	Sl->SaveToFile(FileName);
}
void TrainContainer::FinishAdd(int addsize)
{
	size=addsize;
	delete[]data;
	data=addData;
}
void TrainContainer::Delete(int num)
{
	Sl->LoadFromFile(FileName);
	Sl->Clear();
	Sl->SaveToFile(FileName);
	String date, number, end, time;
	int coupe, reserved, coupeFree, reservedFree;
	delData=new Train[size-1];
	for (int i = 0, t = 0; i < size; i++)
	{
		if ((i + 1) == num)
		{
			continue;
		}
		(delData + t)->Copy(data + i);
		t++;
	}
	size--;
	delete[] data;
	data=delData;
    for (int i = 0; i < size; i++)
	{
		(data + i)->Get(date, number, end, time, coupe, reserved, coupeFree, reservedFree);
		Sl->Add(date);
		Sl->Add(number);
		Sl->Add(end);
		Sl->Add(time);
		Sl->Add(coupe);
		Sl->Add(reserved);
		Sl->Add(coupeFree);
		Sl->Add(reservedFree);
		Sl->SaveToFile(FileName);
	}
}
void TrainContainer::Set(int num)
{
	String date, number, end, time;
	int coupe, reserved, coupeFree, reservedFree;
	for (int i = 0, t = 0; i < size; i++, t++)
	{
		if ((i + 1) == num)
		{
			(data + i)->Get(date, number, end, time, coupe, reserved, coupeFree, reservedFree);
			Form9->Date->Text=date;
			Form9->Number->Text=number;
			Form9->End->Text=end;
			Form9->Time->Text=time;
			Form9->Coupe->Text=IntToStr(coupe);
			Form9->Reserved->Text=IntToStr(reserved);
			Form9->CoupeFree->Text=IntToStr(coupeFree);
			Form9->ReservedFree->Text=IntToStr(reservedFree);
		}
	}
    Sl->LoadFromFile(FileName);
	Sl->Clear();
	Sl->SaveToFile(FileName);
}
void TrainContainer::Change(int num)
{
	String date, number, end, time;
	int coupe, reserved, coupeFree, reservedFree;
	Train* changeData = new Train[size];
	for (int i = 0, t = 0; i < size; i++, t++)
	{
		if ((i + 1) == num)
		{
			date=Form9->Date->Text;
			Form9->Date->Clear();
			number=Form9->Number->Text;
			Form9->Number->Clear();
			end=Form9->End->Text;
			Form9->End->Clear();
			time=Form9->Time->Text;
			Form9->Time->Clear();
			coupe=StrToInt(Form9->Coupe->Text);
			Form9->Coupe->Clear();
			reserved=StrToInt(Form9->Reserved->Text);
			Form9->Reserved->Clear();
			coupeFree=StrToInt(Form9->CoupeFree->Text);
			Form9->CoupeFree->Clear();
			reservedFree=StrToInt(Form9->ReservedFree->Text);
			Form9->ReservedFree->Clear();
			(changeData+i)->Set(date, number, end, time, coupe, reserved, coupeFree, reservedFree);
		}
		else
		{
			(changeData+t)->Copy(data+i);
        }
	}
	delete[] data;
	data=changeData;
    for (int i = 0; i < size; i++)
	{
		(data + i)->Get(date, number, end, time, coupe, reserved, coupeFree, reservedFree);
		Sl->Add(date);
		Sl->Add(number);
		Sl->Add(end);
		Sl->Add(time);
		Sl->Add(coupe);
		Sl->Add(reserved);
		Sl->Add(coupeFree);
		Sl->Add(reservedFree);
	}
	Sl->SaveToFile(FileName);
}
void TrainContainer::EndPlace(String place,TMemo *Memo1)
{
	String date, number, end, time;
	int coupe, reserved, coupeFree, reservedFree,sold;
	Memo1->Lines->Clear();
	Memo1->ReadOnly=True;
	for (int i = 0; i < size; i++)
	{
		if (place==(data+i)->GetEnd())
		{
			(data+i)->Get(date, number, end, time, coupe, reserved, coupeFree, reservedFree);
			Memo1->Lines->Add(IntToStr(i+1)+"-й поезд");
			Memo1->Lines->Add("День отправления: "+date);
			Memo1->Lines->Add("Номер рейса: "+number);
			Memo1->Lines->Add("Конечный пункт назначения: "+end);
			Memo1->Lines->Add("Время отправления: "+time);
			Memo1->Lines->Add("Общее количество мест: "+IntToStr(coupe+reserved));
			Memo1->Lines->Add("Проданные места: "+IntToStr((coupe+reserved)-(coupeFree+reservedFree)));
			Memo1->Lines->Add("");
		}
	}
}
void OutPut(TMemo *Memo1,String& date, String& number, String& end, String& time, int& coupe, int& reserved, int& coupeFree, int& reservedFree)
{
	Memo1->Lines->Add("Номер рейса: "+number);
	Memo1->Lines->Add("Конечный пункт назначения: "+end);
	Memo1->Lines->Add("Время отправления: "+time);
	Memo1->Lines->Add("Купейные места: "+IntToStr(coupe));
	Memo1->Lines->Add("Плацкартные места: "+IntToStr(reserved));
	Memo1->Lines->Add("Свободные купейные места: "+IntToStr(coupeFree));
	Memo1->Lines->Add("Свободные плацкартные места: "+IntToStr(reservedFree));
	Memo1->Lines->Add("");
}
void TrainContainer::DayOfWeek(TMemo *Memo1)
{
	String date, number, end, time;
	int coupe, reserved, coupeFree, reservedFree,sold;
	Memo1->Lines->Clear();
	Memo1->ReadOnly=True;
	int count=0;
	for (int i = 0; i < size; i++)
	{
		if ("Понедельник"==(data+i)->GetDate())
		{
			if(count<1)
			{
				Memo1->Lines->Add("Понедельник: ");
				Memo1->Lines->Add("");
				count++;
			}
			(data+i)->Get(date, number, end, time, coupe, reserved, coupeFree, reservedFree);
			Memo1->Lines->Add(IntToStr(i+1)+"-й поезд");
			OutPut(Memo1,date, number, end, time, coupe, reserved, coupeFree, reservedFree);
		}
	}
	count=0;
	for (int i = 0; i < size; i++)
	{
		if ("Вторник"==(data+i)->GetDate())
		{
			if(count<1)
			{
				Memo1->Lines->Add("Вторник: ");
				Memo1->Lines->Add("");
				count++;
			}
			(data+i)->Get(date, number, end, time, coupe, reserved, coupeFree, reservedFree);
			Memo1->Lines->Add(IntToStr(i+1)+"-й поезд");
			OutPut(Memo1,date, number, end, time, coupe, reserved, coupeFree, reservedFree);
		}
	}
	count=0;
	for (int i = 0; i < size; i++)
	{
		if ("Среда"==(data+i)->GetDate())
		{
			if(count<1)
			{
				Memo1->Lines->Add("Среда: ");
				Memo1->Lines->Add("");
				count++;
			}
			(data+i)->Get(date, number, end, time, coupe, reserved, coupeFree, reservedFree);
			Memo1->Lines->Add(IntToStr(i+1)+"-й поезд");
			OutPut(Memo1,date, number, end, time, coupe, reserved, coupeFree, reservedFree);
		}
	}
	count=0;
	for (int i = 0; i < size; i++)
	{
		if ("Четверг"==(data+i)->GetDate())
		{
			if(count<1)
			{
				Memo1->Lines->Add("Четверг: ");
				Memo1->Lines->Add("");
				count++;
			}
			(data+i)->Get(date, number, end, time, coupe, reserved, coupeFree, reservedFree);
			Memo1->Lines->Add(IntToStr(i+1)+"-й поезд");
			OutPut(Memo1,date, number, end, time, coupe, reserved, coupeFree, reservedFree);
		}
	}
	count=0;
	for (int i = 0; i < size; i++)
	{
		if ("Пятница"==(data+i)->GetDate())
		{
			if(count<1)
			{
				Memo1->Lines->Add("Пятница: ");
				Memo1->Lines->Add("");
				count++;
			}
			(data+i)->Get(date, number, end, time, coupe, reserved, coupeFree, reservedFree);
			Memo1->Lines->Add(IntToStr(i+1)+"-й поезд");
			OutPut(Memo1,date, number, end, time, coupe, reserved, coupeFree, reservedFree);
		}
	}
	count=0;
    for (int i = 0; i < size; i++)
	{
		if ("Суббота"==(data+i)->GetDate())
		{
			if(count<1)
			{
				Memo1->Lines->Add("Суббота: ");
				Memo1->Lines->Add("");
				count++;
			}
			(data+i)->Get(date, number, end, time, coupe, reserved, coupeFree, reservedFree);
			Memo1->Lines->Add(IntToStr(i+1)+"-й поезд");
			OutPut(Memo1,date, number, end, time, coupe, reserved, coupeFree, reservedFree);
		}
	}
	count=0;
	for (int i = 0; i < size; i++)
	{
		if ("Воскресенье"==(data+i)->GetDate())
		{
			if(count<1)
			{
				Memo1->Lines->Add("Воскресенье: ");
				Memo1->Lines->Add("");
				count++;
			}
			(data+i)->Get(date, number, end, time, coupe, reserved, coupeFree, reservedFree);
			Memo1->Lines->Add(IntToStr(i+1)+"-й поезд");
			OutPut(Memo1,date, number, end, time, coupe, reserved, coupeFree, reservedFree);
		}
	}
}
void TrainContainer::TrainAndSeat(String num,TMemo *Memo1)
{
	String date, number, end, time;
	int coupe, reserved, coupeFree, reservedFree,sold;
	Memo1->Lines->Clear();
	Memo1->ReadOnly=True;
	for (int i = 0; i < size; i++)
	{
		if (num==(data+i)->GetNumber())
		{
			if (Form11->Coupe->Checked)
			{
				(data+i)->Get(date, number, end, time, coupe, reserved, coupeFree, reservedFree);
				Memo1->Lines->Add(IntToStr(i+1)+"-й поезд");
				Memo1->Lines->Add("День отправления: "+date);
				Memo1->Lines->Add("Конечный пункт назначения: "+end);
				Memo1->Lines->Add("Время отправления: "+time);
				Memo1->Lines->Add("Свободные купейные места: "+IntToStr(coupeFree));
				Memo1->Lines->Add("");
			}
			else
			{
            	(data+i)->Get(date, number, end, time, coupe, reserved, coupeFree, reservedFree);
				Memo1->Lines->Add(IntToStr(i+1)+"-й поезд");
				Memo1->Lines->Add("День отправления: "+date);
				Memo1->Lines->Add("Конечный пункт назначения: "+end);
				Memo1->Lines->Add("Время отправления: "+time);
				Memo1->Lines->Add("Свободные плацкартные места: "+IntToStr(reservedFree));
				Memo1->Lines->Add("");
            }
		}
	}	
}
//---------------------------------------------------------------------------
#pragma package(smart_init)
