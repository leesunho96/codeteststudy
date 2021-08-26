#include "stdafx.h"


int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0;
	
	int presentWeight = 0;
	
	vector<pair<int, int>> status;
	vector<pair<int, int>> onBridge;

	for (size_t i = 0; i < truck_weights.size(); i++)
	{
		status.push_back(make_pair(truck_weights.at(i), 0));
	}

	
	while (!status.empty())
	{
		answer++;
		for (size_t i = 0; i < onBridge.size(); i++)
		{			
			onBridge[i].second++;
			if (onBridge[i].second == bridge_length)
			{
				presentWeight -= onBridge[i].first;
				onBridge.erase(onBridge.begin() + i);
				i--;
			}
		}

		while (presentWeight < weight)
		{
			if (status.empty())
			{
				break;
			}
			if (status[0].first + presentWeight <= weight)
			{
				onBridge.push_back(status[0]);
				presentWeight += status[0].first;
				status.erase(status.begin());
				break;
			}
			else
			{
				break;
			}
		}		
	}

	return answer + bridge_length ;
}

int main()
{
	int bridge_length = 100;
	int weight = 100;
	vector<int> truck_weight = { 10,10,10,10,10,10,10,10,10,10 };

	cout << solution(bridge_length, weight, truck_weight) << endl;
}
