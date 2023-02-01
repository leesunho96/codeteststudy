#include "stdafx.h"

void Solution();
void Input(int& testNum, vector<string>& testCases);
void Output(const string& testCase, int& idx);

int main()
{
	Solution();
}

void Solution()
{
	int testNum;
	int idx = 1;
	vector<string> testCases;

	Input(testNum, testCases);

	for (string& temp : testCases)
	{
		Output(temp, idx);
	}

}
void Input(int& testNum, vector<string>& testCases)
{
	cin >> testNum;

	for (unsigned int i = 0; i < testNum; i++)
	{
		string temp;
		cin >> temp;
		testCases.push_back(temp);

	}
}


void Output(const string& testCase, int& idx)
{
	int result = 0;

	for (int i = 0; i < testCase.size(); i++)
	{
		if(testCase.at(i) - 97 == i)
		{
			result++;
		}
		else
		{
			break;
		}
	}
	cout << "#" << idx++ << " " << result << endl;
}

/*
5
abcdefghijklmnopqrstu
abcdefghijklmnopqrstuvwzyx
abcefghijk
xyz
absolute



#1 21
#2 23
#3 3
#4 0
#5 2

 */