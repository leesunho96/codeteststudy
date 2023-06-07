/*
https://school.programmers.co.kr/learn/courses/30/lessons/49189

문제 설명
n개의 노드가 있는 그래프가 있습니다. 각 노드는 1부터 n까지 번호가 적혀있습니다. 1번 노드에서 가장 멀리 떨어진 노드의 갯수를 구하려고 합니다. 가장 멀리 떨어진 노드란 최단경로로 이동했을 때 간선의 개수가 가장 많은 노드들을 의미합니다.

노드의 개수 n, 간선에 대한 정보가 담긴 2차원 배열 vertex가 매개변수로 주어질 때, 1번 노드로부터 가장 멀리 떨어진 노드가 몇 개인지를 return 하도록 solution 함수를 작성해주세요.

제한사항
노드의 개수 n은 2 이상 20,000 이하입니다.
간선은 양방향이며 총 1개 이상 50,000개 이하의 간선이 있습니다.
vertex 배열 각 행 [a, b]는 a번 노드와 b번 노드 사이에 간선이 있다는 의미입니다.
입출력 예
n	vertex	return
6	[[3, 6], [4, 3], [3, 2], [1, 3], [1, 2], [2, 4], [5, 2]]	3
입출력 예 설명
예제의 그래프를 표현하면 아래 그림과 같고, 1번 노드에서 가장 멀리 떨어진 노드는 4,5,6번 노드입니다.
*/




#include "stdafx.h"

/*
 *   플로이드 워셜은 시간초과.
 *	 값은 정상 출력.
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