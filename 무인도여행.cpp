/*
 *
메리는 여름을 맞아 무인도로 여행을 가기 위해 지도를 보고 있습니다. 지도에는 바다와 무인도들에 대한 정보가 표시돼 있습니다. 지도는 1 x 1크기의 사각형들로 이루어진 직사각형 격자 형태이며, 격자의 각 칸에는 'X' 또는 1에서 9 사이의 자연수가 적혀있습니다. 지도의 'X'는 바다를 나타내며, 숫자는 무인도를 나타냅니다. 이때, 상, 하, 좌, 우로 연결되는 땅들은 하나의 무인도를 이룹니다. 지도의 각 칸에 적힌 숫자는 식량을 나타내는데, 상, 하, 좌, 우로 연결되는 칸에 적힌 숫자를 모두 합한 값은 해당 무인도에서 최대 며칠동안 머물 수 있는지를 나타냅니다. 어떤 섬으로 놀러 갈지 못 정한 메리는 우선 각 섬에서 최대 며칠씩 머물 수 있는지 알아본 후 놀러갈 섬을 결정하려 합니다.

지도를 나타내는 문자열 배열 maps가 매개변수로 주어질 때, 각 섬에서 최대 며칠씩 머무를 수 있는지 배열에 오름차순으로 담아 return 하는 solution 함수를 완성해주세요. 만약 지낼 수 있는 무인도가 없다면 -1을 배열에 담아 return 해주세요.

제한사항
3 ≤ maps의 길이 ≤ 100
3 ≤ maps[i]의 길이 ≤ 100
maps[i]는 'X' 또는 1 과 9 사이의 자연수로 이루어진 문자열입니다.
지도는 직사각형 형태입니다.
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