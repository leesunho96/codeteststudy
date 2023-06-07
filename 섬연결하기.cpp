/*
 * https://school.programmers.co.kr/learn/courses/30/lessons/42861
 *
 *
 *���� ����
n���� �� ���̿� �ٸ��� �Ǽ��ϴ� ���(costs)�� �־��� ��, �ּ��� ������� ��� ���� ���� ���� �����ϵ��� ���� �� �ʿ��� �ּ� ����� return �ϵ��� solution�� �ϼ��ϼ���.

�ٸ��� ���� �� �ǳʴ���, ������ ���� ������ ���� �����ϴٰ� ���ϴ�. ���� ��� A ���� B �� ���̿� �ٸ��� �ְ�, B ���� C �� ���̿� �ٸ��� ������ A ���� C ���� ���� ���� �����մϴ�.

���ѻ���

���� ���� n�� 1 �̻� 100 �����Դϴ�.
costs�� ���̴� ((n-1) * n) / 2�����Դϴ�.
������ i�� ����, costs{i}{0} �� costs{i} {1}���� �ٸ��� ����Ǵ� �� ���� ��ȣ�� ����ְ�, costs{i} {2}���� �� �� ���� �����ϴ� �ٸ��� �Ǽ��� �� ��� ����Դϴ�.
���� ������ �� �� �־����� �ʽ��ϴ�. ���� ������ �ٲ���� ���� ����� ���ϴ�. �� 0�� 1 ���̸� �����ϴ� ����� �־����� ��, 1�� 0�� ����� �־����� �ʽ��ϴ�.
��� �� ������ �ٸ� �Ǽ� ����� �־����� �ʽ��ϴ�. �� ���, �� �� ������ �Ǽ��� �Ұ����� ������ ���ϴ�.
������ �� ���� ���� �־����� �ʽ��ϴ�.
����� ��

n	costs	return
4	{{0,1,1},{0,2,2},{1,2,5},{1,3,1},{2,3,8}}	4
 */



#include "stdafx.h"




int solution(int n, vector<vector<int>> costs) {
	int answer = 0;
	vector<set<int>> islands(n);	
	set<int> target;
	for (int i = 0; i < n; i++)
		target.insert(i);


	for (int i = 0; i < n; i++)
	{		
		islands[i].insert(i);
	}

	


	sort(costs.begin(), costs.end(), 
	[&](const vector<int>& a, const vector<int>& b)
	{
		return a[2] < b[2];
	}
	);


	set<int> temp;

	for (const auto& bridge : costs)
	{
		auto [from, to, cost] = VectorToTuple::vectorToTuple<int, 3>(bridge);

		auto& fromIsland = islands.at(from);
		auto& toIsland = islands.at(to);


		if(fromIsland == toIsland)
			continue;

		fromIsland.merge(toIsland);


		for (auto a : fromIsland)
		{
			islands[a] = fromIsland;
		}

		answer += cost;

		if(fromIsland == target)
			break;
	}

	return answer;
}

int main()
{
	//vector<vector<int>> island = {{0, 1, 1}, {0, 2, 2}, {1, 2, 5}, {1, 3, 1}, {2, 3, 8}};

	vector<vector<int>> island = {{0, 1, 1}, {0, 2, 2}, {1, 2, 5}, {1, 3, 3}, {2, 3, 8}, {3, 4, 1}};

	cout << solution(5, island);
}
