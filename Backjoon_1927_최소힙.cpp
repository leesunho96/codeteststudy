#include "stdafx.h"

int main()
{
	vector<int> inputList;
	int inputNum;

	//cin >> inputNum;
	scanf_s("%d", &inputNum);

	for (int i = 0; i < inputNum; i++)
	{
		int temp;
		//cin >> temp;
		scanf_s("%d", &temp);
		inputList.push_back(temp);
	}

	priority_queue<int, vector<int>, greater<int>> InputQueue;

	for (size_t i = 0; i < inputList.size(); i++)
	{
		if (inputList[i] == 0)
		{
			if (InputQueue.empty())
			{
				//cout << "0" << endl;
				printf("0\n");
			}
			else
			{
				//cout << InputQueue.top() << endl;
				printf("%d\n", InputQueue.top());
				InputQueue.pop();
			}
		}
		else
		{
			InputQueue.push(inputList[i]);
		}
	}	
}
//9
//0
//12345678
//1
//2
//0
//0
//0
//0
//32