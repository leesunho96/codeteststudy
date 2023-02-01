#include "stdafx.h"

void Solution();
void Input(int& testNum, vector<string>& testCases);
void OutPut(vector<string>& outputs);
string CheckCase(const string& input);

void main()
{
	Solution();
}

void Solution()
{
	int testNum;
	vector<string> testCases;
	vector<string> outputs;
	Input(testNum, testCases);

	for (string& temp : testCases)
	{
		outputs.push_back(CheckCase(temp));
	}

	OutPut(outputs);
}

void Input(int& testNum, vector<string>& testCases)
{
	cin>> testNum;
	for (size_t i = 0; i < testNum; i++)
	{
		string temp;
		cin >> temp;
		testCases.push_back(temp);
	}
}

void OutPut(vector<string>& outputs)
{
	for (int i = 0; i < outputs.size(); i++)
	{
		cout << "#" << i + 1 << " " << outputs.at(i) << endl;

	}
}


string CheckCase(const string& input)
{
	int alphabetNum[26] = {0, };
	char a = 'a';
	string Result;

	for (size_t i = 0; i < input.size(); i++)
	{
		alphabetNum[input.at(i) - 97]++;
	}


	for (int i = 0; i < 26; i++)
	{
		if(alphabetNum[i] % 2 > 0)
		{
			Result += (a + i);
		}
	}

	if (Result == string())
	{
		return "Good";
	}
	return Result;
}
