#include "stdafx.h"

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	int count = 0;
	while (!progresses.empty())
	{
		for (size_t i = 0; i < progresses.size(); i++)
		{
			progresses[i] += speeds[i];			
		}
		if (progresses.at(0) > 99)
		{			
			for (size_t i = 0; i < progresses.size(); i++)
			{				
				if (progresses.at(i) > 99)
				{
					count++;
					progresses.erase(progresses.begin() + i);
					speeds.erase(speeds.begin() + i);
					i--;
				}
				else
				{
					break;
				}
			}			
			answer.push_back(count);
			count = 0;
		}
	}
	return answer;
}



int main()
{
	vector<int> input = { 95, 90, 99, 99, 80, 99 };
	vector<int> speed = { 1, 1, 1, 1, 1, 1 };

	vector<int> result = solution(input, speed);

}