#include "stdafx.h"


void Solution();
void Input(int& testNum, vector<int>& testCases);
void Output(int& testCase, int& idx);

int main()
{
	Solution();
}

void Solution()
{
	int testNum;
	vector<int> testCases;
	int idx = 1;

	Input(testNum, testCases);

	for (int& result : testCases)
	{
		Output(result, idx);
	}
}

void Input(int& testNum, vector<int>& testCases)
{
	cin >> testNum;

	for (int i = 0; i < testNum; i++)
	{
		int temp;
		cin >> temp;

		testCases.push_back(temp);
	}
}

void Output(int& testCase, int& idx)
{
	string result = testCase % 2 == 0 ? "Alice" : "Bob";
	cout << "#" << idx++ << " " << result << endl;
}


/*
 
#1 Alice
#2 Bob
#3 Alice
#4 Alice
#5 Alice
 */