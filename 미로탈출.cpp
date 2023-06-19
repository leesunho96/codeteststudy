#include "stdafx.h"

#define START 'S'
#define EXIT 'E'
#define LAVER 'L'
#define PATH 'O'
#define WALL 'X'
#define HEIGHT 0
#define WIDTH 1
#define WEIGHT 2

using TUPLE = tuple<int, int, int>;
using POINT = tuple<int, int>;



int FindWeight(POINT start, POINT exit, int mapHeight, int mapWidth, optional<bool> bVisitedArr[][101])
{
	struct cmp
	{
		const bool operator() (const TUPLE& val1, const TUPLE& val2)
		{
			return get<WEIGHT>(val1) < get<WEIGHT>(val2);
		}
	};
	priority_queue<TUPLE, vector<TUPLE>, cmp> pq;

	pq.push(tuple_cat(start, make_tuple(0)));
	bVisitedArr[get<0>(start)][get<1>(start)] = true;


	while (!pq.empty())
	{
		auto top = pq.top();
		pq.pop();

		auto [height, width, weight] = top;

		const auto pathes = GetPathes(make_tuple(height, width), mapHeight, mapWidth);

		for (auto path : pathes)
		{
			if (path == exit)
				return weight + 1;

			const auto& [pathHeight, pathWidth] = path;
			auto& targetPoint = bVisitedArr[pathHeight][pathWidth];

			// 예외처리. 해당 지점이 벽인 경우.
			{
				if (!targetPoint.has_value())
					continue;
			}
			const auto bVisitedThisPoint = targetPoint.value();

			if (bVisitedThisPoint)
				continue;

			targetPoint = true;
			pq.push(make_tuple(pathHeight, pathWidth, weight + 1));
		}

	}
	return -1;

};



int solution(vector<string> maps)
{
	const int mapHeight = maps.size();
	const int mapWidth = maps[0].size();

	POINT start, exit, laver;
	
	optional<bool> bVisitedArr[101][101];

	// InitializeData;
	{
		for (int i = 0; i < mapHeight; i++)
		{
			for (int j = 0; j < mapWidth; j++)
			{
				const auto& point = maps[i][j];

				bVisitedArr[i][j] = false;
				if(point == START)
					start = POINT{i, j};
				else if(point == EXIT)
					exit = POINT{i, j}; 
				else if(point == LAVER)
					laver = POINT{i, j};
				else if(point == WALL)
					bVisitedArr[i][j] = nullopt;				
			}
		}	
	}	
	vector<int> subWeight;

	subWeight.push_back(FindWeight(start, laver, mapHeight, mapWidth, bVisitedArr));
	subWeight.push_back(FindWeight(laver, exit, mapHeight, mapWidth, bVisitedArr));

	if(subWeight[0] == -1 || subWeight[1] == -1)
		return -1;
	


	return subWeight[0] + subWeight[1];
}

int main()
{

	vector<tuple<vector<string>, int>> testCases
	{
		{vector<string>{"SOOOL", "XXXXO", "OOOOO", "OXXXX", "OOOOE"}, 16},
		{{"LOOXS", "OOOOX", "OOOOO", "OOOOO", "EOOOO"}, - 1},
		{{"SOEOL","XXXXO","OOOOO","OXXXX","OOOOO"}, 6 },
		{{"SLEOX", "XXXXO", "OOOOO", "OXXXX", "OOOOO"},2 },
		{{"SELOX", "XXXXO", "OOOOO", "OXXXX", "OOOOO"},3 },
		{{"SLXOX", "EXXXO", "OOOOO", "OXXXX", "OOOOO"},3 },
		{{"SXXOX", "EXXXL", "OOXOO", "OXXXX", "OOOOO"},-1 }
	};



	for (const auto& testCase : testCases)
	{
		const auto& [ mapstr, result] = testCase;

		TestFunction(solution, make_tuple(mapstr), result);
	}
	
}
