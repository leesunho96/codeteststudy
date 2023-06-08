/*https://school.programmers.co.kr/learn/courses/30/lessons/154540
 *
�޸��� ������ �¾� ���ε��� ������ ���� ���� ������ ���� �ֽ��ϴ�. �������� �ٴٿ� ���ε��鿡 ���� ������ ǥ�õ� �ֽ��ϴ�. ������ 1 x 1ũ���� �簢����� �̷���� ���簢�� ���� �����̸�, ������ �� ĭ���� 'X' �Ǵ� 1���� 9 ������ �ڿ����� �����ֽ��ϴ�. ������ 'X'�� �ٴٸ� ��Ÿ����, ���ڴ� ���ε��� ��Ÿ���ϴ�. �̶�, ��, ��, ��, ��� ����Ǵ� ������ �ϳ��� ���ε��� �̷�ϴ�. ������ �� ĭ�� ���� ���ڴ� �ķ��� ��Ÿ���µ�, ��, ��, ��, ��� ����Ǵ� ĭ�� ���� ���ڸ� ��� ���� ���� �ش� ���ε����� �ִ� ��ĥ���� �ӹ� �� �ִ����� ��Ÿ���ϴ�. � ������ � ���� �� ���� �޸��� �켱 �� ������ �ִ� ��ĥ�� �ӹ� �� �ִ��� �˾ƺ� �� ��� ���� �����Ϸ� �մϴ�.

������ ��Ÿ���� ���ڿ� �迭 maps�� �Ű������� �־��� ��, �� ������ �ִ� ��ĥ�� �ӹ��� �� �ִ��� �迭�� ������������ ��� return �ϴ� solution �Լ��� �ϼ����ּ���. ���� ���� �� �ִ� ���ε��� ���ٸ� -1�� �迭�� ��� return ���ּ���.

���ѻ���
3 �� maps�� ���� �� 100
3 �� maps[i]�� ���� �� 100
maps[i]�� 'X' �Ǵ� 1 �� 9 ������ �ڿ����� �̷���� ���ڿ��Դϴ�.
������ ���簢�� �����Դϴ�.
 */



#include "stdafx.h"

using ISLAND = tuple<int, int>;

int GetConnectedIsland(map<ISLAND, int>& maps)
{
	set<ISLAND> founded;
	queue<ISLAND> candidate;
	int answer = 0;
	auto baseIsland = *maps.begin();

	
	candidate.push(maps.begin()->first);
	answer += maps.begin()->second;
	maps.erase(maps.begin());


	while(!candidate.empty())
	{
		auto top = candidate.front();
		candidate.pop();


		auto pathes = GetPathes(top);

		for (auto path : pathes)
		{
			if(maps.find(path) == maps.end())
				continue;

			if(founded.find(path) != founded.end())
				continue;


			answer += maps[path];
			maps.erase(path);
			founded.insert(path);
			candidate.push(path);
		}
	}

	return answer;
}

vector<int> solution(vector<string> maps)
{
	map<ISLAND, int> MAPCOST;
	vector<int> answer;

	const int MAPWIDTH = maps[0].size();
	const int MAPHEIGHT = maps.size();

	for (int width = 0; width < MAPWIDTH; width++)
	{
		for (int height = 0; height < MAPHEIGHT; height++)
		{
			const auto val = maps[height][width];

			if(val == 'X')
				continue;

			MAPCOST[make_tuple(height, width)] = val - '0';
		}
	}

	if(MAPCOST.empty())
		return vector<int>{-1};

	while (!MAPCOST.empty())
	{
		answer.push_back(GetConnectedIsland(MAPCOST));
	}

	sort(answer.begin(), answer.end());

	return answer;
}

int main()
{
	vector<string> input{ "X591X","X1X5X","X231X", "1XXX1" };

	auto result = solution(input);

	for (auto val : result)
	{
		cout << val << " " ;
	}

	
}