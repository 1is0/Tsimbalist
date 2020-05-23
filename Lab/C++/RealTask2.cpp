//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "RealTask2.h"
#include "RealTrainContainer.h"
#include "InputAmountOrNumber.h"
#include "RealInputTrain.h"
#include "InputString.h"
#include "InputTrainAndSeat.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm8 *Form8;
bool input=false;
bool add=false;
bool del=false;
bool change=false;
bool place=false;
int i;
int addsize;
TrainContainer trains;
//---------------------------------------------------------------------------
__fastcall TForm8::TForm8(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm5::FormClose(TObject *Sender, TCloseAction &Action)
{

}
//---------------------------------------------------------------------------
void __fastcall TForm8::CopyButtonClick(TObject *Sender)
{
	trains.Copy(Memo1);
}
//---------------------------------------------------------------------------

void __fastcall TForm8::InputButtonClick(TObject *Sender)
{
	Form5->Label1->Caption="Количество поездов:";
	Form5->Show();
	input=true;
}
//---------------------------------------------------------------------------
void __fastcall TForm5::Button1Click(TObject *Sender)
{
	if (Form5->Amount->Text=="")
	{
		ShowMessage("Введите количество поездов!");
	}
	else if (StrToInt(Form5->Amount->Text)==0)
	{
		ShowMessage("Введите корректное число");
	}
	else if(input)
	{
		Form5->Close();
		Form9->Show();
		trains.InputSize(Form5);
		i=0;
	}
	else if(add)
	{
		Form5->Close();
		Form9->Show();
		addsize=trains.GetSize()+StrToInt(Form5->Amount->Text);
		trains.InputAdd(addsize);
		i=trains.GetSize();
	}
    else if (del)
	{
		Form5->Close();
		trains.Delete(StrToInt(Form5->Amount->Text));
		Form5->Amount->Clear();
		del=false;
	}
    else if(change)
	{
		Form9->Label10->Caption=Form5->Amount->Text+" поезд";
		Form5->Close();
		Form9->Show();
		trains.Set(StrToInt(Form5->Amount->Text));
	}
}
void __fastcall TForm9::Button1Click(TObject *Sender)
{
	if(input)
	{
		if (StrToInt(Form9->CoupeFree->Text)<=StrToInt(Form9->Coupe->Text)&&StrToInt(Form9->ReservedFree->Text)<=StrToInt(Form9->Reserved->Text))
		{
			Form9->Label10->Caption=IntToStr(i+2)+" поезд";
			trains.Input(Form9,i);
			i++;
			if (i>=StrToInt(Form5->Amount->Text))
			{
				Form5->Amount->Clear();
				Form8->OutputButton->Enabled=True;
				Form8->AddButton->Enabled=True;
				Form8->DeleteButton->Enabled=True;
				Form8->CorrectButton->Enabled=True;
				Form8->PlaceButton->Enabled=True;
				Form8->DayButton->Enabled=True;
				Form8->TypeButton->Enabled=True;
				input=false;
				Form9->Close();
			}
		}
		else
		{
			ShowMessage("Введите корректное число мест!");
		}
	}
	else if(add)
	{
		Form9->Label10->Caption=IntToStr(i+2)+" поезд";
		if (StrToInt(Form9->CoupeFree->Text)<=StrToInt(Form9->Coupe->Text)&&StrToInt(Form9->ReservedFree->Text)<=StrToInt(Form9->Reserved->Text))
		{
		   trains.Add(Form9, i);
		   i++;
		   if (i>=addsize)
				{
					Form5->Amount->Clear();
					add=false;
					trains.FinishAdd(addsize);
					Form9->Close();
				}
		}
		else
		{
			ShowMessage("Введите корректное число мест!");
		}
	}
	else if(change)
	{
		if (StrToInt(Form9->CoupeFree->Text)<=StrToInt(Form9->Coupe->Text)&&StrToInt(Form9->ReservedFree->Text)<=StrToInt(Form9->Reserved->Text))
		{
		trains.Change(StrToInt(Form5->Amount->Text));
		Form9->Close();
		Form5->Amount->Clear();
		change=false;
		}
        else
		{
			ShowMessage("Введите корректное число мест!");
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm8::OutputButtonClick(TObject *Sender)
{
	trains.Output(Memo1);
}
//---------------------------------------------------------------------------

void __fastcall TForm8::AddButtonClick(TObject *Sender)
{
	Form5->Label1->Caption="Количество поездов:";
	Form5->Show();
	add=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm8::DeleteButtonClick(TObject *Sender)
{
	Form5->Label1->Caption="Номер поезда:";
	Form5->Show();
	del=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm8::CorrectButtonClick(TObject *Sender)
{
	Form5->Label1->Caption="Номер поезда:";
	Form5->Show();
	change=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm8::PlaceButtonClick(TObject *Sender)
{
	Form10->Label1->Caption="Пункт назначения:";
	Form10->Show();
    place=true;
}
//---------------------------------------------------------------------------
void __fastcall TForm10::Button1Click(TObject *Sender)
{
	trains.EndPlace(Form10->String->Text,Form8->Memo1);
	Form10->Close();
	String->Clear();
}
//---------------------------------------------------------------------------

void __fastcall TForm8::DayButtonClick(TObject *Sender)
{
	trains.DayOfWeek(Form8->Memo1);
}
//---------------------------------------------------------------------------
void __fastcall TForm11::Button1Click(TObject *Sender)
{
	trains.TrainAndSeat(Number->Text,Form8->Memo1);
	Number->Clear();
	Form11->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm8::TypeButtonClick(TObject *Sender)
{
	Form11->Show();
}
//---------------------------------------------------------------------------


