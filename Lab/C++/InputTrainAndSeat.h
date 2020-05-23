//---------------------------------------------------------------------------

#ifndef InputTrainAndSeatH
#define InputTrainAndSeatH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TForm11 : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TEdit *Number;
	TButton *Button1;
	TLabel *Label2;
	TRadioButton *Coupe;
	TRadioButton *Reserved;
	void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm11(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm11 *Form11;
//---------------------------------------------------------------------------
#endif
