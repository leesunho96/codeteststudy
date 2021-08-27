#include "stdafx.h"


vector<int> solution(int brown, int yellow) {
	vector<int> answer;

	int total = brown + yellow;
	int x = 0, y = 0;
	int brownNum = 0;
	int yellowNum = 0;
	while (x >= y)
	{
		y++;
		if ((total % y) == 0)
		{
			x = (total) / y;


			brownNum = 2 * x + 2 * y - 4;
			yellowNum = (x - 2) * (y - 2);

			if (brownNum + yellowNum == total && brownNum == brown && yellowNum == yellow)
			{
				answer.push_back(x);
				answer.push_back(y);
				return answer;
			}
		}
	}
}


int main()
{
	int brown = 24;
	int yellow = 24;

	vector<int> result = solution(brown, yellow);

	cout << result.at(0) << result.at(1);
}