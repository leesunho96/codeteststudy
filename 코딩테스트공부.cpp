/*
 https://school.programmers.co.kr/learn/courses/30/lessons/118668

 �ڵ� �׽�Ʈ ����
���� ����
[�� ������ ��Ȯ���� ȿ���� �׽�Ʈ ���� ������ �ִ� �����Դϴ�.]

����� �ڵ� �׽�Ʈ�� �غ��ϱ� ���� �����Ϸ��� �մϴ�. �ڵ� �׽�Ʈ ������ Ǯ�� ���ؼ��� �˰��� ���� ���İ� �ڵ带 �����ϴ� �ɷ��� �ʿ��մϴ�.

�˰��� ���� ������ �˰��, �ڵ带 �����ϴ� �ɷ��� �ڵ����̶�� ǥ���մϴ�. �˰�°� �ڵ����� 0 �̻��� ������ ǥ���˴ϴ�.

������ Ǯ�� ���ؼ��� ������ �䱸�ϴ� ���� �̻��� �˰�°� �ڵ����� �ʿ��մϴ�.

���� ���, ����� ���� �˰���� 15, �ڵ����� 10�̶�� �����غ��ڽ��ϴ�.

A��� ������ �˰�� 10, �ڵ��� 10�� �䱸�Ѵٸ� A ������ Ǯ �� �ֽ��ϴ�.
B��� ������ �˰�� 10, �ڵ��� 20�� �䱸�Ѵٸ� �ڵ����� �����ϱ� ������ B ������ Ǯ �� �����ϴ�.
Ǯ �� ���� ������ �ذ��ϱ� ���ؼ��� �˰�°� �ڵ����� ������ �մϴ�. �˰�°� �ڵ����� ���̱� ���� ������ ���� ������� �ֽ��ϴ�.

�˰���� ���̱� ���� �˰��� ���θ� �մϴ�. �˰�� 1�� ���̱� ���ؼ� 1�� �ð��� �ʿ��մϴ�.
�ڵ����� ���̱� ���� �ڵ� ���θ� �մϴ�. �ڵ��� 1�� ���̱� ���ؼ� 1�� �ð��� �ʿ��մϴ�.
���� Ǯ �� �ִ� ���� �� �ϳ��� Ǯ�� �˰�°� �ڵ����� ���Դϴ�. �� �������� ������ Ǯ�� �ö󰡴� �˰�°� �ڵ����� ������ �ֽ��ϴ�.
������ �ϳ� Ǫ�� ���� ������ �䱸�ϴ� �ð��� �ʿ��ϸ� ���� ������ ���� �� Ǫ�� ���� �����մϴ�.
����� �־��� ��� �������� Ǯ �� �ִ� �˰�°� �ڵ����� ��� �ִܽð��� ���Ϸ� �մϴ�.

�ʱ��� �˰�°� �ڵ����� ���� ���� alp�� cop, ������ ������ ���� 2���� ���� �迭 problems�� �Ű������� �־����� ��, ��� �������� Ǯ �� �ִ� �˰�°� �ڵ����� ��� �ִܽð��� return �ϵ��� solution �Լ��� �ۼ����ּ���.

��� �������� 1�� �̻� Ǯ �ʿ�� �����ϴ�. ����� �� ������ �������ּ���.

���ѻ���
�ʱ��� �˰���� ��Ÿ���� alp�� �ʱ��� �ڵ����� ��Ÿ���� cop�� �Է����� �־����ϴ�.
0 �� alp,cop �� 150
1 �� problems�� ���� �� 100
problems�� ���Ҵ� [alp_req, cop_req, alp_rwd, cop_rwd, cost]�� ���·� �̷���� �ֽ��ϴ�.
alp_req�� ������ Ǫ�µ� �ʿ��� �˰���Դϴ�.
0 �� alp_req �� 150
cop_req�� ������ Ǫ�µ� �ʿ��� �ڵ����Դϴ�.
0 �� cop_req �� 150
alp_rwd�� ������ Ǯ���� �� �����ϴ� �˰���Դϴ�.
0 �� alp_rwd �� 30
cop_rwd�� ������ Ǯ���� �� �����ϴ� �ڵ����Դϴ�.
0 �� cop_rwd �� 30
cost�� ������ Ǫ�µ� ��� �ð��Դϴ�.
1 �� cost �� 100
��Ȯ�� �׽�Ʈ ���̽� ���ѻ���

0 �� alp,cop �� 20
1 �� problems�� ���� �� 6
0 �� alp_req,cop_req �� 20
0 �� alp_rwd,cop_rwd �� 5
1 �� cost �� 10
ȿ���� �׽�Ʈ ���̽� ���ѻ���

�־��� ���� �� �߰� ���ѻ��� �����ϴ�.
����� ��
alp	cop	problems	result
10	10	[[10,15,2,1,2],[20,20,3,3,4]]	15
0	0	[[0,0,2,1,2],[4,5,3,1,2],[4,11,4,0,2],[10,4,0,4,2]]	13
����� �� ����
����� �� #1

�ڵ��� 5�� �ø��ϴ�. �˰�� 10, �ڵ��� 15�� �Ǹ� �ð��� 5��ŭ �ҿ�˴ϴ�.
1�� ������ 5�� Ǳ�ϴ�. �˰�� 20, �ڵ��� 20�� �Ǹ� �ð��� 10��ŭ �ҿ�˴ϴ�. 15�� �ð��� �ҿ��Ͽ� ��� ������ Ǯ �� �ִ� �˰�°� �ڵ����� ���� �� �ֽ��ϴ�.
����� �� #2

1�� ������ 2�� Ǳ�ϴ�. �˰�� 4, �ڵ��� 2�� �Ǹ� �ð��� 4��ŭ �ҿ�˴ϴ�.
�ڵ��� 3�� �ø��ϴ�. �˰�� 4, �ڵ��� 5�� �Ǹ� �ð��� 3��ŭ �ҿ�˴ϴ�.
2�� ������ 2�� Ǳ�ϴ�. �˰�� 10, �ڵ��� 7�� �Ǹ� �ð��� 4��ŭ �ҿ�˴ϴ�.
4�� ������ 1�� Ǳ�ϴ�. �˰�� 10, �ڵ��� 11�� �Ǹ� �ð��� 2��ŭ �ҿ�˴ϴ�. 13�� �ð��� �ҿ��Ͽ� ��� ������ Ǯ �� �ִ� �˰�°� �ڵ����� ���� �� �ֽ��ϴ�.
 
 */

#include "stdafx.h"

// ȿ���� ����.

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


			// ���ϴ� ���� ��� ������ Ǯ �� �ִ� �ּ����� Cop/Alp. dp[alp][cop]�� ���� �ƴϴ�. ���� �׺��� ū ���� ���� ���, �׳� �ִ밪�� �Է�.
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


