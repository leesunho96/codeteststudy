/*
https://school.programmers.co.kr/learn/courses/30/lessons/154538

�ڿ��� x�� y�� ��ȯ�Ϸ��� �մϴ�. ����� �� �ִ� ������ ������ �����ϴ�.

x�� n�� ���մϴ�
x�� 2�� ���մϴ�.
x�� 3�� ���մϴ�.
�ڿ��� x, y, n�� �Ű������� �־��� ��, x�� y�� ��ȯ�ϱ� ���� �ʿ��� �ּ� ���� Ƚ���� return�ϵ��� solution �Լ��� �ϼ����ּ���. �̶� x�� y�� ���� �� ���ٸ� -1�� return ���ּ���.


1 �� x �� y �� 1,000,000
1 �� n < y



����� �� #1
x�� 2�� 2�� ���ϸ� 40�� �ǰ� �̶��� �ּ� Ƚ���Դϴ�.

����� �� #2
x�� n�� 30�� 1�� ���ϸ� 40�� �ǰ� �̶��� �ּ� Ƚ���Դϴ�.

����� �� #3
x�� y�� ��ȯ�� �� ���� ������ -1�� return�մϴ�.
*/

#include "stdafx.h"


template<typename T>
bool IsIntiger(T input)
{
	int share = static_cast<int>(input);
	auto points = input - static_cast<T>(share);

	if(points == static_cast<T>(0))
		return true;
	else
		return false;

}

optional<bool> IsTarget(float presentVal, int targetVal)
{

	if(!IsIntiger<float>(presentVal))
		return nullopt;

	if(presentVal == targetVal)
		return true;

	if(presentVal > targetVal)
		return false;

	return nullopt;
}




int solution(int x, int y, int n) {

	if(x == y)
		return 0;

	set<int> checkedOne;	
	unordered_map<int, int> minVal;
	

	auto insertVal = [&](int key, int value) {	
	checkedOne.insert(key);
		auto presentIter = minVal.find(key);

		if(presentIter == minVal.end())
		{
			checkedOne.insert(key);
			minVal.insert(make_pair(key, value + 1));
		}
		else
		{
			if(minVal[key] > value + 1)
			{
				minVal[key] = value + 1;
			}
		}
	};


	
	insertVal(y, -1);

	queue<int> checkingQue;
	checkingQue.push(y);
	while(!checkingQue.empty())
	{
		auto temp = checkingQue.front();
		checkingQue.pop();


		vector<float> tempVec(3);

		tempVec[0] = static_cast<float>(temp) / 2.0f;
		tempVec[1] = static_cast<float>(temp) / 3.0f;
		tempVec[2] = temp - n;

		for (float& val : tempVec)
		{
			auto isTarget = IsTarget(val, x);

			if(!isTarget.has_value())
				continue;

			if(isTarget.value())
				return minVal[temp] + 1;

			if(checkedOne.find(val) == checkedOne.end())
			{
				insertVal(val, minVal[temp]);
				checkingQue.push(val);
			}	
				
		}
	}

	return -1;
}

int main()
{
	cout << solution(10, 40, 5) << endl;
	cout << solution(10, 40, 30) << endl;
	cout << solution(2, 5, 4) << endl;
	
	
}