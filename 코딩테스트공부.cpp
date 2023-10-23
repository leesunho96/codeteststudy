/*
 https://school.programmers.co.kr/learn/courses/30/lessons/118668

 코딩 테스트 공부
문제 설명
[본 문제는 정확성과 효율성 테스트 각각 점수가 있는 문제입니다.]

당신은 코딩 테스트를 준비하기 위해 공부하려고 합니다. 코딩 테스트 문제를 풀기 위해서는 알고리즘에 대한 지식과 코드를 구현하는 능력이 필요합니다.

알고리즘에 대한 지식은 알고력, 코드를 구현하는 능력은 코딩력이라고 표현합니다. 알고력과 코딩력은 0 이상의 정수로 표현됩니다.

문제를 풀기 위해서는 문제가 요구하는 일정 이상의 알고력과 코딩력이 필요합니다.

예를 들어, 당신의 현재 알고력이 15, 코딩력이 10이라고 가정해보겠습니다.

A라는 문제가 알고력 10, 코딩력 10을 요구한다면 A 문제를 풀 수 있습니다.
B라는 문제가 알고력 10, 코딩력 20을 요구한다면 코딩력이 부족하기 때문에 B 문제를 풀 수 없습니다.
풀 수 없는 문제를 해결하기 위해서는 알고력과 코딩력을 높여야 합니다. 알고력과 코딩력을 높이기 위한 다음과 같은 방법들이 있습니다.

알고력을 높이기 위해 알고리즘 공부를 합니다. 알고력 1을 높이기 위해서 1의 시간이 필요합니다.
코딩력을 높이기 위해 코딩 공부를 합니다. 코딩력 1을 높이기 위해서 1의 시간이 필요합니다.
현재 풀 수 있는 문제 중 하나를 풀어 알고력과 코딩력을 높입니다. 각 문제마다 문제를 풀면 올라가는 알고력과 코딩력이 정해져 있습니다.
문제를 하나 푸는 데는 문제가 요구하는 시간이 필요하며 같은 문제를 여러 번 푸는 것이 가능합니다.
당신은 주어진 모든 문제들을 풀 수 있는 알고력과 코딩력을 얻는 최단시간을 구하려 합니다.

초기의 알고력과 코딩력을 담은 정수 alp와 cop, 문제의 정보를 담은 2차원 정수 배열 problems가 매개변수로 주어졌을 때, 모든 문제들을 풀 수 있는 알고력과 코딩력을 얻는 최단시간을 return 하도록 solution 함수를 작성해주세요.

모든 문제들을 1번 이상씩 풀 필요는 없습니다. 입출력 예 설명을 참고해주세요.

제한사항
초기의 알고력을 나타내는 alp와 초기의 코딩력을 나타내는 cop가 입력으로 주어집니다.
0 ≤ alp,cop ≤ 150
1 ≤ problems의 길이 ≤ 100
problems의 원소는 [alp_req, cop_req, alp_rwd, cop_rwd, cost]의 형태로 이루어져 있습니다.
alp_req는 문제를 푸는데 필요한 알고력입니다.
0 ≤ alp_req ≤ 150
cop_req는 문제를 푸는데 필요한 코딩력입니다.
0 ≤ cop_req ≤ 150
alp_rwd는 문제를 풀었을 때 증가하는 알고력입니다.
0 ≤ alp_rwd ≤ 30
cop_rwd는 문제를 풀었을 때 증가하는 코딩력입니다.
0 ≤ cop_rwd ≤ 30
cost는 문제를 푸는데 드는 시간입니다.
1 ≤ cost ≤ 100
정확성 테스트 케이스 제한사항

0 ≤ alp,cop ≤ 20
1 ≤ problems의 길이 ≤ 6
0 ≤ alp_req,cop_req ≤ 20
0 ≤ alp_rwd,cop_rwd ≤ 5
1 ≤ cost ≤ 10
효율성 테스트 케이스 제한사항

주어진 조건 외 추가 제한사항 없습니다.
입출력 예
alp	cop	problems	result
10	10	[[10,15,2,1,2],[20,20,3,3,4]]	15
0	0	[[0,0,2,1,2],[4,5,3,1,2],[4,11,4,0,2],[10,4,0,4,2]]	13
입출력 예 설명
입출력 예 #1

코딩력 5를 늘립니다. 알고력 10, 코딩력 15가 되며 시간이 5만큼 소요됩니다.
1번 문제를 5번 풉니다. 알고력 20, 코딩력 20이 되며 시간이 10만큼 소요됩니다. 15의 시간을 소요하여 모든 문제를 풀 수 있는 알고력과 코딩력을 가질 수 있습니다.
입출력 예 #2

1번 문제를 2번 풉니다. 알고력 4, 코딩력 2가 되며 시간이 4만큼 소요됩니다.
코딩력 3을 늘립니다. 알고력 4, 코딩력 5가 되며 시간이 3만큼 소요됩니다.
2번 문제를 2번 풉니다. 알고력 10, 코딩력 7이 되며 시간이 4만큼 소요됩니다.
4번 문제를 1번 풉니다. 알고력 10, 코딩력 11이 되며 시간이 2만큼 소요됩니다. 13의 시간을 소요하여 모든 문제를 풀 수 있는 알고력과 코딩력을 가질 수 있습니다.
 
 */

#include "stdafx.h"

// 효율성 실패.

int solution(int alp, int cop, vector<vector<int>> problems) {
	int answer = 0;
	int maxAlp = numeric_limits<int>::min(), maxCop = numeric_limits<int>::min();
	array<array<int, 151>, 151> dp;
	
	// Initialize
	{
		// Req
		for (const auto& problem : problems)
		{
			const auto&[reqAlp, reqCop] = tie(problem[0], problem[1]);
			// Get Required Alp/Cop Value
			{				
				if(maxAlp < reqAlp)
					maxAlp = reqAlp;
				if(maxCop < reqCop)
					maxCop = reqCop;
			}
		}


		for (auto& dpi : dp)
		{
			for (auto& dpj : dpi)
			{
				dpj = numeric_limits<int>::max();
			}
		}

		for (int tempAlp = 0; tempAlp <= alp; tempAlp++)
		{
			for (int tempCop = 0; tempCop <= cop; tempCop++)
				dp[tempAlp][tempCop] = 0;
		}

		
		problems.push_back(vector<int>{0, 0, 1, 0, 1});
		problems.push_back(vector<int>{0, 0, 0, 1, 1});
	}

	// Exception
	{
		if(alp >= maxAlp && cop >= maxCop)
			return 0;
	}

	// Sequence
	{
		auto f = [&](int presentAlp, int presentCop, const vector<int>& problem) mutable
		{
			const auto&[targetAlp, targetCop] = tie(maxAlp, maxCop);
			const auto&[alp_req, cop_req, alp_rew, cop_rew, cost] = VectorToTuple::vectorToTuple<int, 5>(problem);
			auto [nextAlp, nextCop] = make_pair(presentAlp + alp_rew, presentCop + cop_rew);

			if (presentAlp < alp_req || presentCop < cop_req)
				return;


			// 원하는 값은 모든 문제를 풀 수 있는 최소한의 Cop/Alp. dp[alp][cop]의 값이 아니다. 따라서 그보다 큰 값이 나올 경우, 그냥 최대값에 입력.
			nextAlp = min(targetAlp, nextAlp);
			nextCop = min(targetCop, nextCop);

			const int&& newCost = cost + dp[presentAlp][presentCop];
			const int& pastCost = dp[nextAlp][nextCop];

			dp[nextAlp][nextCop] = min(newCost, pastCost);
		};

		{
			const auto&[targetAlp, targetCop] = tie(maxAlp, maxCop);

			for (int presentAlp = alp; presentAlp < targetAlp; presentAlp++)
			{
				for (int presentCop = 0; presentCop < targetCop; presentCop++)
				{
					for (const auto& problem : problems)
					{
						f(presentAlp, presentCop, problem);
					}

				}
			}

			for (int presentAlp = 0; presentAlp < targetAlp; presentAlp++)
			{
				for (int presentCop = cop; presentCop < targetCop; presentCop++)
				{
					for (const auto& problem : problems)
					{
						f(presentAlp, presentCop, problem);
					}

				}
			}

			for (int presentAlp = alp; presentAlp <= targetAlp; presentAlp++)
			{
				for (int presentCop = cop; presentCop <= targetCop; presentCop++)
				{
					for (const auto& problem : problems)
					{
						f(presentAlp, presentCop, problem);
					}

				}
			}
		}
	}
	return dp[maxAlp][maxCop];
}


int main()
{
	vector<tuple<int, int, vector<vector<int>>, int>> testCases
	{
		{	10,	10, {{10,15,2,1,2}, {20,20,3,3,4}},	15},
		{	0	,0,{{0,0,2,1,2}, {4,5,3,1,2}, {4,11,4,0,2}, {10,4,0,4,2}},	13}
	};



	for (const auto& testCase : testCases)	
	{
		const auto& [alp, cop, problems, expectedResult] = testCase;

		TestFunction(solution, make_tuple(alp, cop, problems), expectedResult);
	}
}


