/*
 *https://school.programmers.co.kr/learn/courses/30/lessons/42883
 * 어떤 숫자에서 k개의 수를 제거했을 때 얻을 수 있는 가장 큰 숫자를 구하려 합니다.

예를 들어, 숫자 1924에서 수 두 개를 제거하면 [19, 12, 14, 92, 94, 24] 를 만들 수 있습니다. 이 중 가장 큰 숫자는 94 입니다.

문자열 형식으로 숫자 number와 제거할 수의 개수 k가 solution 함수의 매개변수로 주어집니다. number에서 k 개의 수를 제거했을 때 만들 수 있는 수 중 가장 큰 숫자를 문자열 형태로 return 하도록 solution 함수를 완성하세요.

제한 조건
number는 2자리 이상, 1,000,000자리 이하인 숫자입니다.
k는 1 이상 number의 자릿수 미만인 자연수입니다.
입출력 예
number	k	return
"1924"	2	"94"
"1231234"	3	"3234"
"4177252841"	4	"775841"
 */


#include "stdafx.h"


string solution(string number, int k)
{
	string answer;

	auto cycle = [&](string number, int k)
	{
		const string targetStr = number.substr(0, k);
		
		int tempVal = -1, index = 0;
		
		for (int i = 0; i < k; i++)
		{
			const int&& tempComp = number.at(i) - '0';

			if(tempVal >= tempComp)
				continue;

			tempVal = tempComp;
			index = i;
		}
		return index;
	};

	
	while(k > 0)
	{
		auto presentIndex = cycle(number, k + 1);

		answer += number.substr(presentIndex, 1);
		number = number.substr(presentIndex + 1, number.length() - presentIndex);
		k -= presentIndex;

		if(number.length() == k)
		{
			number = "";
			break;
		}

	}


	answer += number;


	return answer;
}


int main()
{
	cout << solution(string("999"), 2);
}