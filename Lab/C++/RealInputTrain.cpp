//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "RealInputTrain.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm9 *Form9;
//---------------------------------------------------------------------------
__fastcall TForm9::TForm9(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm9::CoupeKeyPress(TObject *Sender, System::WideChar &Key)
{
	if ((Key<'0'||Key>'9')&&Key!=8)
	{
		Key=0;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm9::ReservedKeyPress(TObject *Sender, System::WideChar &Key)
{
	if ((Key<'0'||Key>'9')&&Key!=8)
	{
		Key=0;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm9::CoupeFreeChange(TObject *Sender)
{
	if (Reserved->Text==""||Coupe->Text==""||ReservedFree->Text==""||CoupeFree->Text=="")
	{
		Button1->Enabled=False;
	}
	else
	{
	   Button1->Enabled=True;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm9::ReservedFreeChange(TObject *Sender)
{
	if (Reserved->Text==""||Coupe->Text==""||ReservedFree->Text==""||CoupeFree->Text=="")
	{
		Button1->Enabled=False;
	}
	else
	{
	   Button1->Enabled=True;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm9::CoupeChange(TObject *Sender)
{
	if (Reserved->Text==""||Coupe->Text==""||ReservedFree->Text==""||CoupeFree->Text=="")
	{
		Button1->Enabled=False;
	}
	else
	{
	   Button1->Enabled=True;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm9::CoupeFreeKeyPress(TObject *Sender, System::WideChar &Key)

{
	if ((Key<'0'||Key>'9')&&Key!=8)
	{
		Key=0;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm9::ReservedFreeKeyPress(TObject *Sender, System::WideChar &Key)

{
	if ((Key<'0'||Key>'9')&&Key!=8)
	{
		Key=0;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm9::ReservedChange(TObject *Sender)
{
	if (Reserved->Text==""||Coupe->Text==""||ReservedFree->Text==""||CoupeFree->Text=="")
	{
		Button1->Enabled=False;
	}
	else
	{
	   Button1->Enabled=True;
	}
}
//---------------------------------------------------------------------------

