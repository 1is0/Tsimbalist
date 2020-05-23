//---------------------------------------------------------------------------

#ifndef RealInputTrainH
#define RealInputTrainH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Mask.hpp>
//---------------------------------------------------------------------------
class TForm9 : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
	TLabel *Label10;
	TEdit *Number;
	TEdit *Date;
	TEdit *End;
	TEdit *Coupe;
	TEdit *Reserved;
	TEdit *CoupeFree;
	TEdit *ReservedFree;
	TButton *Button1;
	TMaskEdit *Time;
	void __fastcall CoupeKeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall ReservedKeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall CoupeFreeChange(TObject *Sender);
	void __fastcall ReservedFreeChange(TObject *Sender);
	void __fastcall CoupeChange(TObject *Sender);
	void __fastcall CoupeFreeKeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall ReservedFreeKeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall ReservedChange(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm9(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm9 *Form9;
//---------------------------------------------------------------------------
#endif
