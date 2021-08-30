#include "stdafx.h"


bool ismakeable(int input, vector<int> inputvector)
{
	string stemp = to_string(input);
	int correctNum = 0;

	for (size_t i = 0; i < stemp.size(); i++)
	{
		for (size_t j = 0; j < inputvector.size(); j++)
		{
			// stemp[i] - '0' => char를 int로 변경시켜줌
			if (stemp[i] - '0' == inputvector[j])
			{
				inputvector.erase(inputvector.begin() + j);
				correctNum++;
				break;
			}
		}
	}

	if (correctNum == stemp.size())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool isprimeNum(int input)
{
	int itemp = 2;
	while (itemp * itemp <= input)
	{
		if (input % itemp == 0)
			return false;
		itemp++;
	}
	return true;
}


int solution(string numbers) {
	int answer = 0;
	vector<int> numberVector;
	string stemp = "";
	for (size_t i = 0; i < numbers.size(); i++)
	{
		numberVector.push_back(numbers[i] - '0');
	}
	sort(numberVector.begin(), numberVector.end(), greater<int>());

	for (int i = 0; i < numberVector.size(); i++)
	{
		stemp = stemp + to_string(numberVector[i]);
	}

	int i = 2;

	while (i <= stoi(stemp))
	{
		if (ismakeable(i, numberVector) && isprimeNum(i))
		{
			answer++;
		}
		i++;
	}

	return answer;
}


int main()
{
	string input = "011";

	cout << solution(input);

}