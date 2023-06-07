/*
 *https://school.programmers.co.kr/learn/courses/30/lessons/49191
 *
 *
 *
 n���� ���������� ���� ��ȸ�� �����߰� ���� 1������ n������ ��ȣ�� �޾ҽ��ϴ�.
 ���� ���� 1��1 ������� ������ �ǰ�, ���� A ������ B �������� �Ƿ��� ���ٸ� A ������ B ������ �׻� �̱�ϴ�.
 ������ �־��� ��� ����� ������ �������� ������ �ű�� �մϴ�. ������ ��� ��� ����� �н��Ͽ� ��Ȯ�ϰ� ������ �ű� �� �����ϴ�.

������ �� n, ��� ����� ���� 2���� �迭 results�� �Ű������� �־��� �� ��Ȯ�ϰ� ������ �ű� �� �ִ� ������ ���� return �ϵ��� solution �Լ��� �ۼ����ּ���.

���ѻ���
������ ���� 1�� �̻� 100�� �����Դϴ�.
��� ����� 1�� �̻� 4,500�� �����Դϴ�.
results �迭 �� �� [A, B]�� A ������ B ������ �̰�ٴ� �ǹ��Դϴ�.
��� ��� ������� ����� �����ϴ�.
����� ��
n	results	return
5	[[4, 3], [4, 2], [3, 2], [1, 2], [2, 5]]	2
����� �� ����
2�� ������ [1, 3, 4] �������� �й��߰� 5�� �������� �¸��߱� ������ 4���Դϴ�.
5�� ������ 4���� 2�� �������� �й��߱� ������ 5���Դϴ�.
 */
#include "stdafx.h"
#define DEBUG_MODE 1
int solution(int n, vector<vector<int>> results) {
	int answer = 0;
	array<array<int, 100>,100> board;
	constexpr int MAX = numeric_limits<int>::max();

	for (auto& a : board)
	{
		for(auto& b : a)
			b = MAX;
	}

	for (int i = 0; i < n; i++)
		board[i][i] = 0;

	for (auto match : results)
	{
		auto[winner, looser] = VectorToTuple::vectorToTuple<int, 2>(match);
		winner--; looser--;
		board[winner][looser] = 1;
		board[looser][winner] = -1;
	}

	for (int m = 0; m < n; m++)
	{
		for (int s = 0; s < n; s++)
		{
			for (int e = 0; e < n; e++)
			{
				auto& se = board[s][e];
				auto& es = board[e][s];
				const auto& sm = board[s][m];
				const auto& me = board[m][e];

				if(sm == 1 && me == 1)
				{
					se = 1;
					es = -1;
				}
			}
		}
	}
#ifdef DEBUG_MODE
		for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
#endif

	for (int i = 0; i < n; i++)
	{
		bool isValid = true;
		for(int j = 0; j < n; j++)
		{
			if(board[i][j] == MAX)
			{
				isValid = false;
				break;
			}
		}
		if(isValid)
			answer++;
	}


	return answer;
}

int main()
{
	vector<vector<int>> results {{ 4, 3},{4, 2},{3, 2},{1, 2},{2, 5 }};


	cout << solution(5, results);
}