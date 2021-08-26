#include "stdafx.h"


int solution(vector<int> scoville, int K) {
	int answer = 0;

	priority_queue<int, vector<int>, greater<int>> qinput;

	for (size_t i = 0; i < scoville.size(); i++)
	{
		qinput.push(scoville[i]);
	}

	while (true)
	{
		if (qinput.top() >= K)
		{
			return answer;
		}
		if (qinput.size() == 1)
		{
			return -1;
		}
		answer++;
		int temp = qinput.top();
		qinput.pop();
		temp = temp + 2 * qinput.top();
		qinput.pop();

		qinput.push(temp);
		
	}

	
}


int main()
{
	vector<int> scoville = { 3, 5, 1, 10, 30, 5 };
	int K = 7;

	cout << solution(scoville, K);
}