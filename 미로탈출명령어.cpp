/*
 *
 *
 *

https://school.programmers.co.kr/learn/courses/30/lessons/150365

�̷� Ż�� ��ɾ�
���� ����
n x m ���� �̷ΰ� �־����ϴ�. ����� �̷��� (x, y)���� ����� (r, c)�� �̵��ؼ� Ż���ؾ� �մϴ�.

��, �̷θ� Ż���ϴ� ������ �� ���� �ֽ��ϴ�.

������ �ٱ����δ� ���� �� �����ϴ�.
(x, y)���� (r, c)���� �̵��ϴ� �Ÿ��� �� k���� �մϴ�. �̶�, (x, y)�� (r, c)���ڸ� ������, ���� ���ڸ� �� �� �̻� �湮�ص� �˴ϴ�.
�̷ο��� Ż���� ��θ� ���ڿ��� ��Ÿ���� ��, ���ڿ��� ���� ������ ���� ���� ��η� Ż���ؾ� �մϴ�.
�̵� ��δ� ������ ���� ���ڿ��� �ٲ� �� �ֽ��ϴ�.

l: �������� �� ĭ �̵�
r: ���������� �� ĭ �̵�
u: �������� �� ĭ �̵�
d: �Ʒ������� �� ĭ �̵�
���� ���, �������� �� ĭ, ���� �� ĭ, �������� �� ĭ �������ٸ�, ���ڿ� "lul"�� ��Ÿ�� �� �ֽ��ϴ�.

�̷ο����� ������ ��, ��, ��, �� ���ڷ� �� ĭ�� �̵��� �� �ֽ��ϴ�.

���� ��� ������ ���� 3 x 4 ���ڰ� �ִٰ� ������ ���ڽ��ϴ�.

....
..S.
E...
�̷��� ���� ����� (1, 1)�̰� ���� �ϴ��� (3, 4)�Դϴ�. .�� �� ����, S�� ��� ����, E�� Ż�� �����Դϴ�.

Ż����� �̵��ؾ� �ϴ� �Ÿ� k�� 5��� ������ ���� ��η� Ż���� �� �ֽ��ϴ�.

lldud
ulldd
rdlll
dllrl
dllud
...
�̶� dllrl���� ���� ������ ���� ��η� Ż���� ���� �����ϴ�.

������ ũ�⸦ ���ϴ� ���� n, m, ��� ��ġ�� ���ϴ� ���� x, y, Ż�� ������ ���ϴ� ���� r, c, Ż����� �̵��ؾ� �ϴ� �Ÿ��� ���ϴ� ���� k�� �Ű������� �־����ϴ�. �̶�, �̷θ� Ż���ϱ� ���� ��θ� return �ϵ��� solution �Լ��� �ϼ����ּ���. ��, �� ���Ǵ�� �̷θ� Ż���� �� ���� ��� "impossible"�� return �ؾ� �մϴ�.

���ѻ���
2 �� n (= �̷��� ���� ����) �� 50
2 �� m (= �̷��� ���� ����) �� 50
1 �� x �� n
1 �� y �� m
1 �� r �� n
1 �� c �� m
(x, y) �� (r, c)
1 �� k �� 2,500
����� ��
n	m	x	y	r	c	k	result
3	4	2	3	3	1	5	"dllrl"
2	2	1	1	2	2	2	"dr"
3	3	1	2	3	3	4	"impossible"
����� �� ����
����� �� #1

���� ���ÿ� �����մϴ�.

����� �� #2

�̷��� ũ��� 2 x 2�Դϴ�. ��� ������ (1, 1)�̰�, Ż�� ������ (2, 2)�Դϴ�.

�� ������ ., ��� ������ S, Ż�� ������ E�� ��Ÿ���� ������ �����ϴ�.

S.
.E
�̷��� ���� ����� (1, 1)�̰� ���� �ϴ��� (2, 2)�Դϴ�.

Ż����� �̵��ؾ� �ϴ� �Ÿ� k�� 2�̹Ƿ� ������ ���� ��η� Ż���� �� �ֽ��ϴ�.

rd
dr
"dr"�� ���� ������ ���� ���� ����Դϴ�. ���� "dr"�� return �ؾ� �մϴ�.

����� �� #3

�̷��� ũ��� 3 x 3�Դϴ�. ��� ������ (1, 2)�̰�, Ż�� ������ (3, 3)�Դϴ�.

�� ������ ., ��� ������ S, Ż�� ������ E�� ��Ÿ���� ������ �����ϴ�.

.S.
...
..E
�̷��� ���� ����� (1, 1)�̰� ���� �ϴ��� (3, 3)�Դϴ�.

Ż����� �̵��ؾ� �ϴ� �Ÿ� k�� 4�Դϴ�. �̶�, �̵� �Ÿ��� 4�̸鼭, S���� E���� �̵��� �� �ִ� ��δ� �������� �ʽ��ϴ�.

���� "impossible"�� return �ؾ� �մϴ�.
 */


#include "stdafx.h"

#define FAIL "impossible"

auto operator+ (const tuple<int, int>& v1, const tuple<int, int>& v2)
{
	return make_tuple((get<0>(v1) + get<0>(v2)), (get<1>(v1) + get<1>(v2)));
}

string solution(int n, int m, int x, int y, int r, int c, int k)
{
	string answer = "";

	auto [height, width] = tie(n, m);
	auto [startY, startX] = tie(x, y);
	auto [endY, endX] = tie(r,c);
	int& distance = k;

	map<char, tuple<int, int>> directions;

	auto bCanMoveDirection = [&](tuple<int, int> start, tuple<int, int> target, char direction, int leftDistance, int height, int width)
	{
		const auto [nextPointY, nextPointX] = start + directions[direction];
		const auto& [targetY, targetX] = target;
		const auto [yPossible, xPossible] = make_tuple(IsInRange(nextPointY, height), IsInRange(nextPointX, width));

		if (!(xPossible && yPossible))
			return false;

		const auto nextLeftDistance = GetManhattanDistance(nextPointX, nextPointY, targetX, targetY);

		return nextLeftDistance <= leftDistance;
	};
	// D L R U ������.
	// �� �� �� ��
	// ���� ó��
	{	
		if(GetManhattanDistance(tie(startY, startX), tie(endY, endX)) > distance)
			return FAIL;
	}

	// Initialize
	{
		directions['d'] = make_tuple(1, 0);
		directions['l'] = make_tuple(0, -1);
		directions['r'] = make_tuple(0, 1);
		directions['u'] = make_tuple(-1, 0);

		width--;
		height--;
		startX--;
		startY--;
		endX--;
		endY--;

	}

	// Main Sequence.
	{
		printStr("presentY : %, presentX : %, distance : % \n", startY, startX, distance);
		array<char, 4> dirList{ 'd', 'l', 'r', 'u' };
		while(distance != 0)
		{
			bool bCanExist = false;
			
			for (auto a : dirList)
			{
				if(bCanMoveDirection(tie(startY, startX), tie(endY, endX), a, distance, height, width))
				{
					distance--;
					answer += a;


					const auto [movY, movX] = directions[a];
					startX += movX;
					startY += movY;
					bCanExist = true;
					break;
				}
			}
			printStr("presentY : %, presentX : %, distance : % \n", startY, startX, distance);

			if(!bCanExist)
				return FAIL;
		}
	}

	if(startY != endY || startX != endX)
		return FAIL;

	return answer;
}


int main()
{
	vector<tuple<int, int, int, int, int, int, int, string>> testCases
	{
	//{	3,	4,	2,	3,	3,	1,	5,	"dllrl"},
	//{	2,	2,	1,	1,	2,	2,	2,	"dr"},
	{	3,	3,	1,	2,	3,	3,	4,	"impossible"}
	};


	for (const auto& testCase : testCases)
	{
		const auto& [n, m, x, y, r, c, k, expectedResult] = testCase;
		TestFunction(solution, make_tuple(n, m, x, y, r, c, k), expectedResult);
	}
}




