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
class TForm6 : public TForm
{
__published:	// IDE-managed Components
	TMemo *Memo1;
	TOpenDialog *OpenDialog1;
	TButton *CopyButton;
	TSaveDialog *SaveDialog1;
	TButton *InputButton;
	void __fastcall CopyButtonClick(TObject *Sender);
	void __fastcall InputButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm6(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm6 *Form6;
//---------------------------------------------------------------------------
#endif
