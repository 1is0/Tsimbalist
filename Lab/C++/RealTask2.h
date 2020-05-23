//---------------------------------------------------------------------------

#ifndef Task2H
#define Task2H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Dialogs.hpp>
//---------------------------------------------------------------------------
class TForm8 : public TForm
{
__published:	// IDE-managed Components
	TMemo *Memo1;
	TOpenDialog *OpenDialog1;
	TButton *CopyButton;
	TSaveDialog *SaveDialog1;
	TButton *InputButton;
	TButton *OutputButton;
	TButton *AddButton;
	TLabel *Filename;
	TButton *DeleteButton;
	TButton *CorrectButton;
	TButton *PlaceButton;
	TButton *DayButton;
	TButton *TypeButton;
	void __fastcall CopyButtonClick(TObject *Sender);
	void __fastcall InputButtonClick(TObject *Sender);
	void __fastcall OutputButtonClick(TObject *Sender);
	void __fastcall AddButtonClick(TObject *Sender);
	void __fastcall DeleteButtonClick(TObject *Sender);
	void __fastcall CorrectButtonClick(TObject *Sender);
	void __fastcall PlaceButtonClick(TObject *Sender);
	void __fastcall DayButtonClick(TObject *Sender);
	void __fastcall TypeButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm8(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm8 *Form8;
//---------------------------------------------------------------------------
#endif
