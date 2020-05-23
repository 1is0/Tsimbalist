//---------------------------------------------------------------------------

#ifndef TrainContainerH
#define TrainContainerH
#include "Unit4.h"
#include "InputAmountOrNumber.h"
class TrainContainer
{
	private:
	Train *data;
	int size;
	public:
	void Copy(TMemo *Memo1);
	void InputSize(TForm5 *Form5);
};
//---------------------------------------------------------------------------
#endif
