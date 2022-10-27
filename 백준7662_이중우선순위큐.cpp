#include "stdafx.h"

map<int, int> inputMap;
priority_queue<int, vector<int>, greater<int>> greaterQueue;
priority_queue<int, vector<int>, less<int>> lessQueue;

void Cycle()
{
	int InputMapNum;
	scanf("%d", &InputMapNum);

	for (size_t i = 0; i < InputMapNum; i++)
	{
		char inputCommand;
		int inputNum;

		scanf("%c", &inputCommand);
		scanf("%d", &inputNum);
		map<int, int>::iterator iter = inputMap.find(inputNum);

		if (inputCommand == 'I')
		{			
			if (iter == inputMap.end())
			{
				greaterQueue.push(inputNum);
				lessQueue.push(inputNum);
				inputMap.insert(inputNum, 1);
			}
			else
			{				
				iter->second = iter->second + 1;
			}
		}
		else if (inputCommand == 'D')
		{
			map<int, int>::iterator itertemp;
			if (inputNum == 1)
			{
				while(true)
				{
					int temp = greaterQueue.top();
					itertemp = inputMap.find(temp);

					if (itertemp == inputMap.end())
					{
						greaterQueue.pop();
						continue;
					}
					else
					{
						itertemp->second = itertemp->second -1;
						if (itertemp->second == 0)
						{
							greaterQueue.pop();
							inputMap.erase(itertemp);
						}
					}
				}
			}
			else
			{
				while (true)
				{
					int temp = lessQueue.top();
					itertemp = inputMap.find(temp);

					if (itertemp == inputMap.end())
					{
						lessQueue.pop();
						continue;
					}
					else
					{
						itertemp->second = itertemp->second - 1;
						if (itertemp->second == 0)
						{
							lessQueue.pop();
							inputMap.erase(itertemp);
						}
					}
				}
			}
		}

}
}

int main()
{
	int inputNum;

	scanf("%d", &inputNum);

	for (size_t i = 0; i < inputNum; i++)
	{
		Cycle();
	}
}