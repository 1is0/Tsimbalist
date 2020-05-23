//---------------------------------------------------------------------------

#ifndef RealTrainContainerH
#define RealTrainContainerH
#include "RealTrain.h"
#include "InputAmountOrNumber.h"
#include "RealInputTrain.h"
#include "InputTrainAndSeat.h"
class TrainContainer
{
	private:
	Train *data;
	int size;
	public:
	int GetSize();
	void Copy(TMemo *Memo1);
	void InputSize(TForm5 *Form5);
	void Input(TForm9 *Form9,int i);
	void Output(TMemo *Memo1);
	void InputAdd(int addsize);
	void Add(TForm9 *Form9,int i);
	void FinishAdd(int addsize);
	void Delete(int num);
	void Set(int num);
	void Change(int num);
	void EndPlace(String place,TMemo *Memo1);
	void DayOfWeek(TMemo *Memo1);
	void TrainAndSeat(String num,TMemo *Memo1);
};
//---------------------------------------------------------------------------
#endif
