//---------------------------------------------------------------------------

#ifndef InputSportsmenH
#define InputSportsmenH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm4 : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TEdit *Country;
	TButton *Button1;
	TLabel *Label2;
	TEdit *Team;
	TEdit *Name;
	TEdit *Surname;
	TPanel *Panel1;
	TEdit *Patronymic;
	TEdit *Number;
	TEdit *Age;
	TEdit *Height;
	TEdit *Weight;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
	TLabel *Label9;
	TLabel *Label10;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall AgeKeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall AgeChange(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm4(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm4 *Form4;
//---------------------------------------------------------------------------
#endif
