//---------------------------------------------------------------------------

#pragma hdrstop

#include "TrainContainer.h"
#include "Task2.h"
TStringList *Sl=new TStringList;
String FileName;
void TrainContainer::Copy(TMemo *Memo1)
{
	if(Form6->OpenDialog1->Execute())
	{
		FileName=Form6->OpenDialog1->FileName;
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
			Memo1->Lines->Add(IntToStr(i+1)+"-й игрок");
			Memo1->Lines->Add("Дата отправления: "+date);
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
	size=StrToInt(Form5->Amount->Text);
	data = new Train[size];
}
/*void TrainContainer::Input(int i)
{
	String date, number, end, time;
	int coupe, reserved, coupeFree, reservedFree;
	date=Form7->Country->Text;
	Sl->Add(date);
	Form4->Country->Clear();
	team=Form4->Team->Text;
	Sl->Add(team);
	Form4->Team->Clear();
	name=Form4->Name->Text;
	Sl->Add(name);
	Form4->Name->Clear();
	surname=Form4->Surname->Text;
	Sl->Add(surname);
	Form4->Surname->Clear();
	patronymic=Form4->Patronymic->Text;
	Sl->Add(patronymic);
	Form4->Patronymic->Clear();
	number=Form4->Number->Text;
	Sl->Add(number);
	Form4->Number->Clear();
	age=StrToInt(Form4->Age->Text);
	Sl->Add(age);
	Form4->Age->Clear();
	height=Form4->Height->Text;
	Sl->Add(height);
	Form4->Height->Clear();
	weight=Form4->Weight->Text;
	Sl->Add(weight);
	Form4->Weight->Clear();
	(data+i)->set(country, team, name, surname, patronymic, number, age, height, weight);
	Sl->SaveToFile("Sportsmen_empty.txt");
}*/
//---------------------------------------------------------------------------
#pragma package(smart_init)
