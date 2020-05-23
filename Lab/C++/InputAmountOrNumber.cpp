//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "InputAmountOrNumber.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm5 *Form5;
//---------------------------------------------------------------------------
__fastcall TForm5::TForm5(TComponent* Owner)
	: TForm(Owner)
{
}

void __fastcall TForm5::AmountKeyPress(TObject *Sender, System::WideChar &Key)
{
	if ((Key<'0'||Key>'9')&&Key!=8)
	{
		Key=0;
	}
}
//---------------------------------------------------------------------------





