/*
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

const vector<pair<int, int>> cases = {pair<int, int>(1, 0),pair<int, int>(0, 1) ,pair<int, int>(-1, 0) ,pair<int, int>(0, -1) };

optional<int> GetIsland(int x, int y, vector<vector<optional<int>>>& connectedMap)
{
	if(connectedMap[x][y] == nullopt)
		return nullopt;


	int result = 0;
	queue<pair<int, int>> visited;
	visited.push(pair<int, int>(x, y));

	while(!visited.empty())
	{
		auto present = visited.front();
		visited.pop();

		for (auto next : cases)
		{
			auto nextIsland = pair<int, int>(present.first + next.first, present.second + next.second);

			if(!IsInRange(nextIsland.first, static_cast<int>(connectedMap.size())))
				continue;
			if (!IsInRange(nextIsland.second, static_cast<int>(connectedMap[0].size())))
				continue;
			if(connectedMap[nextIsland.first][nextIsland.second] == nullopt)
				continue;

			visited.push(nextIsland);
		}

		auto presentIsland = connectedMap[present.first][present.second];

		if(presentIsland.has_value())
		{
			result += connectedMap[present.first][present.second].value();
			connectedMap[present.first][present.second] = nullopt;
		}
	}


	return result;
}


vector<int> solution(vector<string> maps)
{
	vector<int> answer;
	vector<vector<optional<int>>> connectedMap;

	// Initialize
	{
		for (auto mapLine : maps)
		{
			vector<optional<int>> temp;

			for (const auto mapRow : mapLine)
			{
				if (mapRow == 'X')
					temp.push_back(nullopt);
				else
					temp.push_back(mapRow - '0');
			}
			connectedMap.push_back(temp);
		}
	}


	for (int i = 0; i< maps.size(); i++)
	{
		for (int j = 0; j < maps[i].size(); j++)
		{
			auto result = GetIsland(i, j, connectedMap);

			if(result.has_value())
				answer.push_back(result.value());
			
		}
	}

	sort(answer.begin(), answer.end());
	
	if(answer.empty())
		return vector<int>(1, -1);
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