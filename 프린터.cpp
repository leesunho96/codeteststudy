#include "stdafx.h"

int findsmallest(vector<pair<int, int>> input)
{
	int answer = 0;
	int temp = -1;
	for (size_t i = 0; i < input.size(); i++)
	{
		if (temp < input[i].first)
		{
			temp = input[i].first;
			answer = i;
		}


	}
	return answer;
}

int solution(vector<int> priorities, int location) {
	int answer = 0;
	vector<pair<int, int>> input;
	pair<int, int> ptemp;

	for (size_t i = 0; i < priorities.size(); i++)
	{
		input.push_back(make_pair(priorities.at(i), (int)i));
	}

	while (true)
	{
		answer++;
		int temp = findsmallest(input);
		if (input[temp].second == location)
		{
			return answer;
		}
		for (size_t i = 0; i < temp; i++)
		{
			ptemp = input.at(0);
			input.erase(input.begin());
			input.push_back(ptemp);
		}
		input.erase(input.begin());
	}


}


int main()
{
	vector<int> properties = { 2, 1, 3, 2 };
	int location = 2;

	cout << solution(properties, location) << endl;
}