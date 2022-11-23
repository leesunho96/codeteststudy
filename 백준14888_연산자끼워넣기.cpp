#include "stdafx.h"

#define PLUS 0
#define MINUS 1
#define MULTIPLY 2
#define DIVIDE 3

vector<int> Result;
vector<int> Numbers;
int inputNum;

void Solution(int PresentNum, int Digit, int plus, int minus, int multiple, int divide)
{	
	if(Digit == inputNum)
	{
		Result.push_back(PresentNum);
	}

	if(plus > 0)
	{		
		Solution(PresentNum + Numbers[Digit], Digit + 1, plus -1, minus, multiple, divide);
	}
	if(minus > 0)
	{
		Solution(PresentNum - Numbers[Digit], Digit + 1, plus, minus - 1, multiple, divide);
	}
	if(multiple > 0)
	{
		Solution(PresentNum * Numbers[Digit], Digit + 1, plus, minus , multiple - 1, divide);
	}
	if (divide > 0)
	{
		Solution(PresentNum / Numbers[Digit], Digit + 1, plus, minus, multiple, divide - 1);
	}

}


int main()
{	
	int Calculator[4] = {0, 0, 0, 0};
	int minResult = INT32_MAX, maxResult = INT32_MIN;

	cin >> inputNum;
	for (int i = 0; i < inputNum; i++)
	{
		int temp;
		cin >> temp;
		Numbers.push_back(temp);
	}

	cin >> Calculator[0] >> Calculator[1] >> Calculator[2] >> Calculator[3];



	Solution(Numbers[0], 1, Calculator[PLUS], Calculator[MINUS], Calculator[MULTIPLY], Calculator[DIVIDE]);

	for (auto a : Result)
	{
		if(a > maxResult)
			maxResult = a;
		if(a < minResult)
			minResult = a;
	}


	cout << maxResult << endl << minResult;


}