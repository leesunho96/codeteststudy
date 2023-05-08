#include "stdafx.h"

int solution(vector<vector<int>> targets)
{
	int answer = 0;

	sort(targets.begin(), targets.end(),
	[&targets](vector<int>& a, vector<int>& b)
	{
		return a[1] < b[1] ? true : false;
	});

	int end = -1;



	for(auto& target : targets)
	{
		if(target[0] < end && target[1] >= end)
			continue;
		else
		{		
			end = target[1];
			answer++;
		}
	}


	return answer;
}



int main()
{
	vector<vector<int>> input;
	int inputArr[] = {4,5 , 4,8 , 10,14 , 11,13 , 5,12 , 3,7 , 1,4};

	for (size_t i = 0; i < sizeof(inputArr) / 8; i++)
	{
		vector<int> temp;
		temp.push_back(inputArr[2 * i]);
		temp.push_back(inputArr[2 * i + 1]);

		input.emplace_back(temp);
	}

	cout << solution(input);
}
