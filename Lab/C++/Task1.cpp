//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Task1.h"
#include "Sportsmen.h"
#include "InputSportsmen.h"
#include "InputAmountOrNumber.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
Sportsmen sportsmen(1);
bool input=false;
bool add=false;
bool del=false;
bool change=false;
int addsize=0;
int i=0;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm5::FormClose(TObject *Sender, TCloseAction &Action)
{

}
void __fastcall TForm3::Button1Click(TObject *Sender)
{
	sportsmen.Copy(Memo1);
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button2Click(TObject *Sender)
{
	Form5->Label1->Caption="Количество спортсменов:";
	Form5->Show();
	sportsmen.Clear();
	input=true;
}
//---------------------------------------------------------------------------
void __fastcall TForm5::Button1Click(TObject *Sender)
{
	if (Form5->Amount->Text=="")
	{
		ShowMessage("Введите количество спортсменов!");
	}
	else if (StrToInt(Form5->Amount->Text)==0)
	{
		ShowMessage("Введите корректное число");
	}
	else if(input)
	{
		Form5->Close();
		Form4->Show();
		sportsmen.InputSize(Form5);
		i=0;
	}
	else if(add)
	{
		Form5->Close();
		Form4->Show();
		addsize=sportsmen.GetSize()+StrToInt(Form5->Amount->Text);
		sportsmen.InputAdd(addsize);
		i=sportsmen.GetSize();
	}
	else if (del)
	{
		Form5->Close();
		sportsmen.Clear();
		sportsmen.Delete(StrToInt(Form5->Amount->Text));
		Form5->Amount->Clear();
		del=false;
	}
	else if(change)
	{
		Form4->Label10->Caption=Form5->Amount->Text+" спортстмен";
		Form5->Close();
		Form4->Show();
		sportsmen.Set(StrToInt(Form5->Amount->Text));
		sportsmen.Clear();
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Button3Click(TObject *Sender)
{
	sportsmen.Output(Memo1);
}
//---------------------------------------------------------------------------
void __fastcall TForm4::Button1Click(TObject *Sender)
{
	if(input)
	{
		if (i<StrToInt(Form5->Amount->Text))
		{
			Form4->Label10->Caption=IntToStr(i+2)+" спортстмен";
			sportsmen.Input(Form4, i);
			i++;
			if (i>=StrToInt(Form5->Amount->Text))
			{
				Form5->Amount->Clear();
				input=false;
				Form4->Close();
			}
		}
	}
	else if(add)
	{
		Form4->Label10->Caption=IntToStr(i+2)+" спортстмен";
		if (i<addsize)
		{
		   sportsmen.Add(Form4, i);
		   i++;
		   if (i>=addsize)
				{
					Form5->Amount->Clear();
					add=false;
					sportsmen.FinishAdd(addsize);
					Form4->Close();
				} 
		}
	}
	else if(change)
	{
		sportsmen.Change(StrToInt(Form5->Amount->Text));
		Form4->Close();
		Form5->Amount->Clear();
		change=false;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button4Click(TObject *Sender)
{
    Form5->Label1->Caption="Количество спортсменов:";
	Form5->Show();
	add=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button5Click(TObject *Sender)
{
	Form5->Label1->Caption="Номер спортсмена:";
	Form5->Show();
	del=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button6Click(TObject *Sender)
{
    Form5->Label1->Caption="Номер спортсмена:";
	Form5->Show();
	change=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button7Click(TObject *Sender)
{
    sportsmen.Youngest(Memo1);
}
//---------------------------------------------------------------------------

