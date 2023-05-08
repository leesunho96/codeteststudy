#include "stdafx.h"

int k{ 80 };
vector<vector<int>> dungeon;
set<int> results;
void Recursive(vector<bool> visitedDungeon, int left, int visitedNum)
{
	results.insert(visitedNum);

	for (int i = 0; i < visitedDungeon.size(); i++)
	{
		if(!visitedDungeon[i])
		{
			if(left >= dungeon[i][0])
			{
				vector<bool> temp = visitedDungeon;
				temp[i] = true;
				Recursive(temp, left - dungeon[i][1], visitedNum + 1);
			}
			
		}
	}
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
	dungeon = dungeons;

	vector<bool> visitList(dungeon.size());
	for (int i = 0; i < visitList.size(); i++)
	{
		visitList[i] = false;
	}

	Recursive(visitList, k, 0);

	answer = *results.rbegin();



    return answer;
}

int main()
{
	vector<vector<int>> dungeons;
    int input[] = {80, 20 ,  50, 40 ,  30, 10};

	for (size_t i = 0; i < sizeof(input) / 4 / 2; i++)
	{
		vector<int> temp;
		temp.push_back(input[2 * i]);
		temp.push_back(input[2 * i + 1]);

		dungeons.emplace_back(temp);
	}


	cout << solution(k, dungeons);


}