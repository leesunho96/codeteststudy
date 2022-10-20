#include <iostream>
#include <cstdio>
#include <string>

using namespace std;


int main()
{
	int Num;
	int ErrorSize;
	bool isError[10] = { true, true, true, true, true, true, true, true, true, true };

	cin >> Num;
	cin >> ErrorSize;

	for (int i = 0; i < ErrorSize; i++)
	{
		int temp;
		scanf_s("%d", &temp);

		isError[temp] = false;
	}

	// 여기까지 입력 완료.
	int MinNum = 999999999;


	// BruteForce로 진행.
	for (int i = 0; i < 100000; i++)
	{
		bool isInErrorKey = false;
		string temp = to_string(i);


		for (int j = 0; j < temp.length(); j++)
		{
			char temp2 = temp.at(j);
			if (!isError[atoi(&temp2)])
			{
				isInErrorKey = true;
			}
		}

		if (isInErrorKey)
			continue;

		int tempResult = abs(i - Num);

		if (tempResult < MinNum)
			MinNum = tempResult;

		if (tempResult <= 6)
			cout << MinNum;


	}

	cout << MinNum;


}