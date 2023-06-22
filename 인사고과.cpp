/*
 *https://school.programmers.co.kr/learn/courses/30/lessons/152995
 *
�λ���
���� ����
��ȣ�� ȸ��� �������� 1�� ���� �λ����� ���� �μ�Ƽ�긦 �����մϴ�. �� ������� �ٹ� �µ� ������ ���� �� ������ ��ϵǾ� �ִµ� ���� � ����� �ٸ� ������ ������� �� ������ ��� ���� ��찡 �� ���̶� �ִٸ� �� ����� �μ�Ƽ�긦 ���� ���մϴ�. �׷��� ���� ����鿡 ���ؼ��� �� ������ ���� ���� ������ ������ ���� ������ ���� �μ�Ƽ�갡 ���� ���޵˴ϴ�. �̶�, �� ������ ���� ������ ������� �������̸�, �������� ����ŭ ���� ������ �ǳ� �ݴϴ�. ���� ��� ������ ���� ���� ū ����� 2���̶�� 1���� 2���̰� 2�� ���� ���� ������ 3������Դϴ�.

�� ����� �ٹ� �µ� ������ ���� �� ���� ��� scores�� �־����� ��, ��ȣ�� ������ return �ϵ��� solution �Լ��� �ϼ����ּ���.

���� ����
1 �� scores�� ���� �� 100,000
scores�� �� ���� �� ����� �ٹ� �µ� ������ ���� �� ������ ��Ÿ���� [a, b] �����Դϴ�.
scores[0]�� ��ȣ�� �����Դϴ�.
0 �� a, b �� 100,000
��ȣ�� �μ�Ƽ�긦 ���� ���ϴ� ��� -1�� return �մϴ�.
����� ��
scores	result
[[2,2],[1,4],[3,2],[3,2],[2,1]]	4
����� �� ����
5 ��° ����� 3 ��° �Ǵ� 4 ��° ������� �ٹ� �µ� ������ ���� �� ������ ��� ���� ������ �μ�Ƽ�긦 ���� �� �����ϴ�. 2 ��° ���, 3 ��° ���, 4 ��° ����� �� ������ ���� 5 ������ �ְ����̹Ƿ� 1 ���Դϴ�. 1 ���� �� ���̹Ƿ� 2 ��� 3 ���� ���� 1 ��° ����� ��ȣ�� �� ������ ���� 4 ������ 4 ���Դϴ�.
 */


#include "stdafx.h"

using TUPLE = tuple<int, int>;



// 8, 10, 11, 14, 16, 22�� Ʋ��. ���� �𸣰���.
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

	// X���� �������� ���� ū Y ���� map �� �Է�.
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

