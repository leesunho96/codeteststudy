#include "stdafx.h"

void Solution();
void Input(unsigned int& TestCase, vector<unsigned int>& inputCases);
void OutPut(const vector<unsigned int>& Results);
unsigned int GetDiversity(unsigned int inputCase);
bool IsInCase(unsigned int CheckNum, const vector<unsigned int>& Cases);

unsigned int main()
{
	Solution();
}

void Solution()
{
	unsigned int TestCaseNum;
	
	vector<unsigned int> inputCases;
	vector<unsigned int> Results;

	Input(TestCaseNum, inputCases);

	for (unsigned int inputCase : inputCases)
	{
		Results.push_back(GetDiversity(inputCase));
	}

	OutPut(Results);
}

void Input(unsigned int& TestCase, vector<unsigned int>& inputCases)
{
	cin >> TestCase;

	for (size_t i = 0; i < TestCase; i++)
	{
		unsigned int temp;
		cin >> temp;

		inputCases.push_back(temp);
	}
}

void OutPut(const vector<unsigned int>& Results)
{
	unsigned int Num = 0;

	for (unsigned int i = 0; i < Results.size(); i++)
	{
		cout << "#" << " " << i + 1 << " " << Results.at(i) << endl;
	}
}

unsigned int GetDiversity(unsigned int inputCase)
{
	vector<unsigned int> NumCases;

	while(true)
	{
		unsigned int leftNums = inputCase / 10;
		unsigned int presentDigitNum = inputCase % 10;
		inputCase = inputCase / 10;

		if(leftNums == 0 && presentDigitNum == 0)
			break;

		if(IsInCase(presentDigitNum, NumCases))
			continue;

		NumCases.push_back(presentDigitNum);
	}

	return NumCases.size();
}

bool IsInCase(unsigned int CheckNum, const vector<unsigned int>& Cases)
{
	for (const unsigned int checkCase : Cases)
	{
		if(CheckNum == checkCase)
		{
			return true;
		}
	}

	return false;
}