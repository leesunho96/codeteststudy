#include "stdafx.h"

void Solution();
void Inputs(vector<string> &inputStrings);
void Outputs(vector<string>& outputStrings, vector<int> results);
int GetPalindromes(const string& inputString);
void GetSubStrings(const string& inputString, const int& DividesNum, vector<vector<string>>& OutResult);
string GetSubStringsBySize(int leftNum, int presentLocation);


int main()
{
	Solution();
}

void Solution()
{
	vector<string> inputStrings;
	vector<int> results;

	Inputs(inputStrings);

	for (size_t i = 0; i < inputStrings.size(); i++)
	{
		results.push_back(GetPalindromes(inputStrings.at(i)));
	}

	Outputs(inputStrings, results);
}


// 주어진 개수만큼 입력
void Inputs(vector<string>& inputStrings)
{
	int inputNums;
	cin >> inputNums;

	for (size_t i = 0; i < inputNums; i++)
	{
		string temp;
		cin >> temp;

		inputStrings.push_back(temp);
	}

	
}

// 결과물 출력
void Outputs(vector<string>& outputStrings, vector<int> results)
{
	for (size_t i = 0; i < outputStrings.size(); i++)
	{
		cout << "#" << i << " " << results.at(i) % 1000000007 << endl;
	}
}

// 회문인 i의 수 반환
int GetPalindromes(const string& inputString)
{
	int length = inputString.size();

	for (size_t k = 1; k < length; k++)
	{
		vector<vector<string>> DividedStrings;		
		GetSubStrings(inputString, k, DividedStrings);
	}
}

// 쪼갠 문자열 반환.
void GetSubStrings(const string& inputString, const int& DividesNum, vector<vector<string>>& OutResult)
{
	
}


string GetSubStringsBySize(int leftNum, int presentLocation)
{

}