//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "InputSportsmen.h"
#include "Sportsmen.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm4 *Form4;
//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm4::AgeKeyPress(TObject *Sender, System::WideChar &Key)
{
	if ((Key<'0'||Key>'9')&&Key!=8)
	{
		Key=0;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm4::AgeChange(TObject *Sender)
{
	if (Age->Text=="")
	{
		Button1->Enabled=False;
	}
	else
	{
	   Button1->Enabled=True;
    }

}
//---------------------------------------------------------------------------

