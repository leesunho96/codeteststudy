
/*
 * https://school.programmers.co.kr/learn/courses/30/lessons/132265
 *
 *
������ũ �ڸ���
���� ����
ö���� ������ũ�� �� �������� �߶� ������ �� ������ ���� �������� �մϴ�. �� ������ũ���� �������� ���ε��� �Ϸķ� �÷��� �ֽ��ϴ�.
ö���� ������ ������ũ�� �����ϰ� ���������� �ϴµ�, �׵��� ������ũ�� ũ�⺸�� ������ũ ���� �÷��� ���ε��� ������ �� ������ �����ϴ�.
�׷��� �߸� �������� ũ��� �÷��� ������ ������ ������� �� ������ ������ �������� ������ �ö󰡸� �����ϰ� ������ũ�� �������� ������ �����մϴ�.

���� ���, ������ũ�� 4���� ������ ������ �÷��� �ִٰ� �սô�. ���ε��� 1, 2, 3, 4�� ���� ��ȣ�� ǥ������ ��, ����ũ ���� ���ε��� [1, 2, 1, 3, 1, 4, 1, 2] ������ �÷��� �ֽ��ϴ�. ���� �� ��° ����(1)�� �� ��° ����(3) ���̸� �ڸ��� ������ũ�� ������ [1, 2, 1], [3, 1, 4, 1, 2]�� ������ �˴ϴ�. ö���� [1, 2, 1]�� ���� ������, ������ [3, 1, 4, 1, 2]�� ���� ������ �԰� �Ǹ� ö���� �� ���� ����(1, 2)�� ���� �� ������, ������ �� ���� ����(1, 2, 3, 4)�� ���� �� �����Ƿ�, �̴� �����ϰ� �������� ���� �ƴմϴ�. ���� ������ũ�� �� ��° ����(3)�� �ټ� ��° ����(1) ���̸� �ڸ��� [1, 2, 1, 3], [1, 4, 1, 2]�� ������ �˴ϴ�. �� ��� ö���� �� ���� ����(1, 2, 3)��, ������ �� ���� ����(1, 2, 4)�� ���� �� �����Ƿ�, �̴� �����ϰ� �������� ���Դϴ�. �����ϰ� ������ũ�� �ڸ��� ����� �������� �� �� �ֽ��ϴ�. ���� ������ũ�� [1, 2, 1, 3, 1], [4, 1, 2]���� �߶� �����ϰ� �����ϴ�. � ��쿡�� ������ũ�� �����ϰ� ������ ���� ���� �ֽ��ϴ�.

������ũ�� �÷��� ���ε��� ��ȣ�� ������ ���� �迭 topping�� �Ű������� �־��� ��, ������ũ�� �����ϰ� �ڸ��� ����� ���� return �ϵ��� solution �Լ��� �ϼ����ּ���.

���ѻ���
1 �� topping�� ���� �� 1,000,000
1 �� topping�� ���� �� 10,000
����� ��
topping	result
[1, 2, 1, 3, 1, 4, 1, 2]	2
[1, 2, 3, 1, 4]	0
����� �� ����
����� �� #1

������ũ�� [1, 2, 1, 3], [1, 4, 1, 2] �Ǵ� [1, 2, 1, 3, 1], [4, 1, 2]�� ���� �ڸ��� ö���� ������ ���� �� ���� ������ ���� �� �ֽ��ϴ�. �� ��� �����ϰ� ������ũ�� ������ ����� ���� �� ������ �����մϴ�.
����� �� #2

������ũ�� �����ϰ� ���� �� �����ϴ�.
 */

#include "stdafx.h"

int solution(vector<int> topping) {
	int answer = 0;
	map<int, int> toppingNumForB;
	set<int> toppingCase;
	set<int> forA, forB;


	// initialize Map, Set
	{
		auto top = topping.begin();

		toppingCase.insert(*top);
		forA.insert(*top);

		for (auto a = ++top; a != topping.end(); a++)
		{
			const auto forBTopping = *a;

			toppingNumForB[forBTopping] += 1;
			forB.insert(forBTopping);
			toppingCase.insert(forBTopping);
		}
	}

	// exception handling
	{
		if(toppingCase.size() == 1)
			return topping.size() - 1;
	}

	// Main Sequence	   
	{
		for (auto iter = topping.begin() + 1; iter != topping.end() - 1; ++iter)
		{
			const int topIdx = *iter;

			forA.insert(topIdx);
			toppingNumForB[topIdx] -= 1;

			if(toppingNumForB[topIdx] == 0)
				forB.erase(topIdx);

			if(forA.size() == forB.size())
				answer += 1;
		}
	}

	return answer;
}


int main()
{
	vector<tuple<vector<int>, int>> testCases
	{
		{{1, 2, 1, 3, 1, 4, 1, 2},	2},
		{{1, 2, 3, 1, 4},	0}
	};


	for (auto& testCase : testCases)
	{
		const auto& [topping, expectedResult] = testCase;

		TestFunction(solution, make_tuple(topping), expectedResult);
	}
}