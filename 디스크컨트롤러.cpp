#include "stdafx.h"



int solution(vector<vector<int>> jobs) {
	int answer = 0;
	int size = jobs.size();
	priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> input;

	for (size_t i = 0; i < jobs.size(); i++)
	{
		input.push(jobs[i]);			
	}

	while (input.empty())
	{

	}


	return answer / size;
}

int main()
{
	vector<vector<int>> jobs = { { 0, 3},{1, 9},{2, 6 } };

	cout << solution(jobs);
	return 0;
}