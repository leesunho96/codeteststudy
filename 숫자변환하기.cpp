/*
https://school.programmers.co.kr/learn/courses/30/lessons/154538

자연수 x를 y로 변환하려고 합니다. 사용할 수 있는 연산은 다음과 같습니다.

x에 n을 더합니다
x에 2를 곱합니다.
x에 3을 곱합니다.
자연수 x, y, n이 매개변수로 주어질 때, x를 y로 변환하기 위해 필요한 최소 연산 횟수를 return하도록 solution 함수를 완성해주세요. 이때 x를 y로 만들 수 없다면 -1을 return 해주세요.


1 ≤ x ≤ y ≤ 1,000,000
1 ≤ n < y



입출력 예 #1
x에 2를 2번 곱하면 40이 되고 이때가 최소 횟수입니다.

입출력 예 #2
x에 n인 30을 1번 더하면 40이 되고 이때가 최소 횟수입니다.

입출력 예 #3
x를 y로 변환할 수 없기 때문에 -1을 return합니다.
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