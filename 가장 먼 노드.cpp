/*
https://school.programmers.co.kr/learn/courses/30/lessons/49189

���� ����
n���� ��尡 �ִ� �׷����� �ֽ��ϴ�. �� ���� 1���� n���� ��ȣ�� �����ֽ��ϴ�. 1�� ��忡�� ���� �ָ� ������ ����� ������ ���Ϸ��� �մϴ�. ���� �ָ� ������ ���� �ִܰ�η� �̵����� �� ������ ������ ���� ���� ������ �ǹ��մϴ�.

����� ���� n, ������ ���� ������ ��� 2���� �迭 vertex�� �Ű������� �־��� ��, 1�� ���κ��� ���� �ָ� ������ ��尡 �� �������� return �ϵ��� solution �Լ��� �ۼ����ּ���.

���ѻ���
����� ���� n�� 2 �̻� 20,000 �����Դϴ�.
������ ������̸� �� 1�� �̻� 50,000�� ������ ������ �ֽ��ϴ�.
vertex �迭 �� �� [a, b]�� a�� ���� b�� ��� ���̿� ������ �ִٴ� �ǹ��Դϴ�.
����� ��
n	vertex	return
6	[[3, 6], [4, 3], [3, 2], [1, 3], [1, 2], [2, 4], [5, 2]]	3
����� �� ����
������ �׷����� ǥ���ϸ� �Ʒ� �׸��� ����, 1�� ��忡�� ���� �ָ� ������ ���� 4,5,6�� ����Դϴ�.
*/




#include "stdafx.h"

/*
 *   �÷��̵� ������ �ð��ʰ�.
 *	 ���� ���� ���.
 */
namespace FLOYDWARSHALL
{
int solution(int n, vector<vector<int>> edge) 
{
	typedef tuple<int, int, int> NODE;

	typedef optional<int> INT;
	typedef tuple<int, int> PATH;

	INT** Graph = new INT*[n];
	
	for (int i = 0; i < n; i++)
	{
		Graph[i] = new INT[n];
		for (int j= 0; j < n; j++)
		{
			Graph[i][j] = nullopt;
		}
	}

	for (const auto& road : edge)
	{		
		auto [from, to] = VectorToTuple::vectorToTuple<int, 2>(road);
		from--; to--;
		Graph[from][to] = 1;
		Graph[to][from] = 1;	
	}

	for (int m = 0; m < n; m++)
	{
		for (int s = 0; s < n; s++)
		{
			for (int e = 0; e < n; e++)
			{
				auto& se = Graph[s][e];
				const auto& sm = Graph[s][m];
				const auto& me = Graph[m][e];

				if(sm == nullopt || me == nullopt)
					continue;

				auto val = sm.value() + me.value();
				if(se != nullopt)
				{
					if(se.value() < val)
						continue;						
				}
				se = val;
			}
		}
	}

	int answer = 0, farDistance = 0;

	for (int i = 1; i < n; i++)
	{
		const auto& tempNode = Graph[0][i];

		if(tempNode == nullopt)
			continue;
		
		const auto& tempValue = tempNode.value();

		if(tempValue < farDistance)
			continue;
		if(tempValue > farDistance)
		{
			answer = 1;farDistance = tempValue;continue;
		}
		if(tempValue == farDistance)
			answer++;
	}
	return answer;
}
}


namespace BFS
{
typedef tuple<int, int, int> NODE;

typedef optional<int> INT;
typedef tuple<int, int> PATH;


int solution(int n, vector<vector<int>> edge) {

	const auto INVALID = numeric_limits<int>::max();
	vector<set<int>> PATH(n + 1);
	vector<int> distance(n + 1, INVALID);
	vector<bool> visited(n + 1, false);
	

	for (const auto & road : edge)
	{
		PATH[road[0]].insert(road[1]);
		PATH[road[1]].insert(road[0]);
	}

	queue<int> qu;
	distance[0] = -1;
	distance[1] = 0;
	qu.push(1);

	while (!qu.empty())
	{
		const auto present = qu.front();
		const auto presentDistance = distance[present] + 1;
		qu.pop();		

		for (auto target : PATH[present])
		{
			if(visited[target])
				continue;
			if(distance[target] < presentDistance)
				continue;
			visited[target] = true;
			distance[target] = presentDistance;
			qu.push(target);				
		}
	}


	int max = 0, maxDistance = 0;
	for (auto a : distance)
	{
		if(a > max)
		{
			max = a;
			maxDistance = 1;
		}
		else if(a == max)
		{
			maxDistance++;
		}
	}
	return maxDistance;
}

}

int main()
{
	vector<vector<int>> edge{{3, 6}, {4, 3}, {3, 2}, {1, 3}, {1, 2}, {2, 4}, {5, 2}};

	cout << BFS::solution(6, edge);
	cout << FLOYDWARSHALL::solution(6, edge);;
}