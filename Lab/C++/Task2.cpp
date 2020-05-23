//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Task2.h"
#include "TrainContainer.h"
#include "InputAmountOrNumber.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm6 *Form6;
bool input=false;
int i;
TrainContainer trains;
//---------------------------------------------------------------------------
__fastcall TForm6::TForm6(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm6::CopyButtonClick(TObject *Sender)
{
	trains.Copy(Memo1);
}
//---------------------------------------------------------------------------

void __fastcall TForm6::InputButtonClick(TObject *Sender)
{
	Form5->Label1->Caption="Количество спортсменов:";
	Form5->Show();
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
		trains.InputSize(Form5);
		i=0;
	}
}

