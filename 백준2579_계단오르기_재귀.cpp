#include"stdafx.h"

vector<int> TotalResult;
vector<int> stairs;
int inputNum;

void Move(int presentStair, int presentSum, int continueNum)
{

	
	int presentResult = presentSum + stairs.at(presentStair);
	if (presentStair == inputNum - 1)
	{
		TotalResult.push_back(presentSum);
		return;
	}
	if (presentStair < inputNum - 3)
	{
		Move(presentStair + 2, presentResult, 0);
	}
	if (continueNum < 3 && presentStair < inputNum - 1)
	{
		Move(presentStair + 1, presentResult, continueNum+1);
	}
}


int main()
{
	cin >> inputNum;

	for (size_t i = 0; i < inputNum; i++)
	{
		static int temp;
		cin >> temp;
		stairs.push_back(temp);
	}	
	Move(0, 0, -1);	
	int result = 1;
	for (auto a : TotalResult)
	{
		if (result < a)
		{
			result = a;
		}
	}
	cout << result;
	return 0;

}