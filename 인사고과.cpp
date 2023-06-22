/*
 *https://school.programmers.co.kr/learn/courses/30/lessons/152995
 *
인사고과
문제 설명
완호네 회사는 연말마다 1년 간의 인사고과에 따라 인센티브를 지급합니다. 각 사원마다 근무 태도 점수와 동료 평가 점수가 기록되어 있는데 만약 어떤 사원이 다른 임의의 사원보다 두 점수가 모두 낮은 경우가 한 번이라도 있다면 그 사원은 인센티브를 받지 못합니다. 그렇지 않은 사원들에 대해서는 두 점수의 합이 높은 순으로 석차를 내어 석차에 따라 인센티브가 차등 지급됩니다. 이때, 두 점수의 합이 동일한 사원들은 동석차이며, 동석차의 수만큼 다음 석차는 건너 뜁니다. 예를 들어 점수의 합이 가장 큰 사원이 2명이라면 1등이 2명이고 2등 없이 다음 석차는 3등부터입니다.

각 사원의 근무 태도 점수와 동료 평가 점수 목록 scores이 주어졌을 때, 완호의 석차를 return 하도록 solution 함수를 완성해주세요.

제한 사항
1 ≤ scores의 길이 ≤ 100,000
scores의 각 행은 한 사원의 근무 태도 점수와 동료 평가 점수를 나타내며 [a, b] 형태입니다.
scores[0]은 완호의 점수입니다.
0 ≤ a, b ≤ 100,000
완호가 인센티브를 받지 못하는 경우 -1을 return 합니다.
입출력 예
scores	result
[[2,2],[1,4],[3,2],[3,2],[2,1]]	4
입출력 예 설명
5 번째 사원은 3 번째 또는 4 번째 사원보다 근무 태도 점수와 동료 평가 점수가 모두 낮기 때문에 인센티브를 받을 수 없습니다. 2 번째 사원, 3 번째 사원, 4 번째 사원은 두 점수의 합이 5 점으로 최고점이므로 1 등입니다. 1 등이 세 명이므로 2 등과 3 등은 없고 1 번째 사원인 완호는 두 점수의 합이 4 점으로 4 등입니다.
 */


#include "stdafx.h"

using TUPLE = tuple<int, int>;



// 8, 10, 11, 14, 16, 22번 틀림. 왠지 모르겠음.
namespace WRONG
{
int solution(vector<vector<int>> scores)
{
	int answer = 1;	
	
	const auto WANHO = VectorToTuple::vectorToTuple<int, 2>(scores[0]);
	const auto wanhoSum = get<0>( WANHO) + get<1>(WANHO);
	const auto [wanhoX, wanhoY] = WANHO;
	unordered_map<int, int> GetMaxYBasedOnX;
	set<int> mapKey;

	// X값을 기준으로 가장 큰 Y 값을 map 에 입력.
	for (const auto& score : scores)
	{
		const auto& [x, y] = VectorToTuple::vectorToTuple<int, 2>(score);
		auto& yBasedOnX = GetMaxYBasedOnX[x];
		mapKey.insert(x);

		//printStr("x : %, yBasedOnX : %, y : %\n", x, yBasedOnX, y);
		if(yBasedOnX < y)
			GetMaxYBasedOnX[x] = y;
	}

	for (const auto& score : scores)
	{
		const auto& [x, y] = VectorToTuple::vectorToTuple<int, 2>(score);
		const auto&& scoreSum = x + y;

		if(x > wanhoX && y > wanhoY)
			return -1;

		if(wanhoSum >= scoreSum)
			continue;

		auto xKey = mapKey.find(x);
		++xKey;
		const auto yMaxBasedOnX = (xKey == mapKey.end()) ? numeric_limits<int>::lowest() : GetMaxYBasedOnX[*xKey];

		//printStr("scoreX : %, scoreY : %, yMaxBasedOnX : %\n", x, y, yMaxBasedOnX);
		if(yMaxBasedOnX == numeric_limits<int>::lowest() || yMaxBasedOnX <= y)
			answer++;
	}

	return answer;
}
}

int main()
{
	vector<tuple<vector<vector<int>>, int>> testCases
	{
		make_tuple(vector<vector<int>>{{2,2},{1,4},{3,2},{3,2},{2,1}}, 4),
		{{{4, 0}, {2, 3}, {4, 4}, {2, 6}}, 3},
		{ {{1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}} , 1},
		{ {{3, 1},{1, 4},{2, 3},{2, 3},{1, 5},{1, 0},{1, 0}} , 5},
		{{{4, 1}, {2, 4}, {3, 5}}, 2},

		{ {{2, 2}, {2, 2}, {2, 3}, {3, 2}}, 3 },
		{{{100, 2}, {100, 1}, {50, 1}}, 1}
	};


	for (auto testCase : testCases)
	{
		auto [param, expectedResult] = testCase;

		TestFunction(WRONG::solution, make_tuple(param), expectedResult);
	}
	return 0;
}

